#include "zhl_internal.h"
#include "zhl_private.h"
#include "detours.h"
#include "SigScan.h"
#include <unordered_map>
#include <functional>
#include <map>
#include <string>
#include <cstdarg>
#include "PALMemoryProtection.h"
#include <inttypes.h>

#ifdef _WIN32
    #define OUR_OWN_FUNCTIONS_CALLEE_DOES_CLEANUP 1
#elif defined(__linux__) || defined(__APPLE__)
    #define OUR_OWN_FUNCTIONS_CALLEE_DOES_CLEANUP 0
    #define USE_STACK_ALIGNMENT
    #define STACK_ALIGNMENT_SIZE 0x10
	#include <SDL2/SDL_messagebox.h>
	#include <cstdlib>
#else
    #define "Unknown OS"
#endif

#ifdef __i386__
    #define PTR_PRINT_F "0x%08" PRIxPTR
    #define POINTER_BYTES 4
#elif defined(__amd64__)
    #define PTR_PRINT_F "0x%016" PRIxPTR
    #define POINTER_BYTES 8
#else
    #error "Unknown processor architecture not supported."
#endif // Architecture

using namespace ZHL;

static const char *g_logPath = NULL;
static FILE *g_hookLog = NULL;

void ZHL::Init()
{
	static bool initialized = false;
	if(initialized) return;

	if(!Definition::Init())
	{
        // TODO: Maybe change this over to SDL_ShowSimpleMessageBox for all systems; however, we'll have to add libsdl to the build & maybe the sdl.dll runtime DLL on Windows
        // SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", FunctionDefinition::GetLastError(), NULL);
#ifdef _WIN32
		MessageBox(0, FunctionDefinition::GetLastError(), "Error", MB_ICONERROR);
		ExitProcess(1);
#elif defined(__linux__) || defined(__APPLE__)
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Fatal Error", FunctionDefinition::GetLastError(), NULL);
        fprintf(stderr, "Fatal Error %s:", FunctionDefinition::GetLastError());
        exit(1);
#endif
	}

	if(!FunctionHook_private::Init())
	{
#ifdef _WIN32
		MessageBox(0, FunctionHook_private::GetLastError(), "Error", MB_ICONERROR);
		ExitProcess(1);
#elif defined(__linux__) || defined(__APPLE__)
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Fatal Error", FunctionHook_private::GetLastError(), NULL);
        fprintf(stderr, "Fatal Error %s:", FunctionHook_private::GetLastError());
        exit(1);
#endif
	}

	initialized = true;
}

void ZHL::SetLogPath(const char *logPath)
{
	g_logPath = logPath;
	if(g_hookLog)
	{
		fclose(g_hookLog);
		g_hookLog = NULL;
	}
}

//#define HOOK_LOG
static void Log(const char *format, ...)
{
	if(!g_logPath) return;
	if(!g_hookLog) g_hookLog = std::fopen(g_logPath, "w");
	if(!g_hookLog) return;



	va_list va;
	va_start(va, format);
	vfprintf(g_hookLog, format, va);
	fflush(g_hookLog);
	va_end(va);
}

template <size_t Size> static const char *ConvertToUniqueName(char (&dst)[Size], const char *name, const char *type)
{
	char tmp[128];
	strncpy(tmp, type, 128);

	const char *p = tmp;
	if(p[0] == '.')
	{
		++p;
		if(p[0] == 'P' && p[1] == '8')
		{
			p += 2;
			while(p[0] && (p[0] != '@' || p[1] != '@')) ++p;
		}
	}

	snprintf(dst, Size, "%s%s", name, p);
	return dst;
}

//================================================================================
// Definition

static std::vector<Definition*> &Defs()
{
	static std::vector<Definition*> defs;
	return defs;
}

static std::unordered_map<std::string, Definition*> &DefsByName()
{
	static std::unordered_map<std::string, Definition*> defsByName;
	return defsByName;
}

static char g_defLastError[1024] = {0};

const char *Definition::GetLastError() {return g_defLastError;}

void FunctionDefinition::SetName(const char *name, const char *type)
{
	ConvertToUniqueName(_name, name, type);
	strncpy(_shortName, name, 512);
}

int Definition::Init()
{
	SigScan::Init();

	for(auto it = Defs().begin() ; it != Defs().end() ; ++it)
	{
		if(!(*it)->Load()) return 0;
	}
	return 1;
}

Definition *Definition::Find(const char *name)
{
	auto it = DefsByName().find(name);
	if(it != DefsByName().end())
		return (*it).second;
	else
		return NULL;
}

void Definition::Add(const char *name, Definition *def)
{
	Defs().push_back(def);
	DefsByName().insert(std::pair<std::string, Definition*>(name, def));
}



//================================================================================
// VariableDefinition


int VariableDefinition::Load()
{
	SigScan sig(_sig);
	if(!sig.Scan())
	{
		snprintf(g_defLastError, 1024, "Failed to find value for variable %s, address could not be found", _name);
		return 0;
	}

	if(sig.GetMatchCount() == 0)
	{
		snprintf(g_defLastError, 1024, "Failed to find address for variable %s, no capture in input signature", _name);
		return 0;
	}

	const SigScan::Match &m = sig.GetMatch();
	if(_useOffset)
    {
        /* Instruction Pointer relative addressing
         * Determine real address of variable match
         * RIP + var = real addr
         * During execution (E|R)IP would be at the next instruction so instead we add the length of the match
         * NOTE: This means it is only possible to match a variable with offset computation that is at the END of the instruction bytes
         * i.e., operands that can take two memory addresses, only the second memory address (end of the bytes of the instruction) can be matched.
         */
        uintptr_t valueVar = 0;
        memcpy(&valueVar, m.address, m.length);
        uintptr_t realAddr = (uintptr_t) m.address;
        realAddr += m.length;
        realAddr += valueVar;
        *(void**)_outVar = (void*) realAddr;
    }
	else if(_useValue)
        memcpy(_outVar, m.address, m.length);
    else
        *(void**)_outVar = (void*)m.address;

	Log("Found value for %s: " PTR_PRINT_F ", dist %d\n", _name, *((uintptr_t*) _outVar), sig.GetDistance());

	return 1;
}

//================================================================================
// NoOpDefinition


int NoOpDefinition::Load()
{
	SigScan sig(_sig);
	if(!sig.Scan())
	{
		snprintf(g_defLastError, 1024, "Failed to find match for no-op region %s, address could not be found", _name);
		return 0;
	}

	if(sig.GetMatchCount() == 0)
	{
		snprintf(g_defLastError, 1024, "Failed to find match for no-op region %s, no capture in input signature", _name);
		return 0;
	}

	const SigScan::Match &m = sig.GetMatch();
	
	uintptr_t ptrToCode = (uintptr_t) m.address;
    const size_t noopingSize = sizeof(uint8_t) * m.length;
    MEMPROT_SAVE_PROT(dwOldProtect);
    MEMPROT_PAGESIZE();
    MEMPROT_UNPROTECT(ptrToCode, noopingSize, dwOldProtect);
    for(unsigned int i = 0; i < m.length; i++)
    {
        *(uint8_t*)(ptrToCode++) = 0x90;
    }
    MEMPROT_REPROTECT(ptrToCode, noopingSize, dwOldProtect);

	Log("Found address for %s: " PTR_PRINT_F ", wrote NOP's for %d bytes, dist %d\n", _name, (uintptr_t) m.address, m.length, sig.GetDistance());

	return 1;
}

//================================================================================
// FunctionDefinition

FunctionDefinition::FunctionDefinition(const char *name, const std::type_info &type, const char* sig, const short *argdata, int nArgs, unsigned int flags, void **outfunc)
{
    _argdata = argdata;
    _nArgs = nArgs;
    _flags = flags;
    _outFunc = outfunc;



    SetName(name, type.name());
    strcpy(_name, name);
    strcpy(_sig, sig);

    Add(_name, this);

}

int FunctionDefinition::Load()
{
	SigScan sig = SigScan(_sig);

	if(!sig.Scan())
	{
		snprintf(g_defLastError, 1024, "Failed to find address for function %s", _name);
		return 0;
	}

	_address = sig.GetAddress<void*>();
	*_outFunc = _address;
	Log("Found address for %s: " PTR_PRINT_F ", dist %d\n", _name, (uintptr_t)_address, sig.GetDistance());

	return 1;
}


//================================================================================
// FunctionHook

#ifdef HOOK_LOG
static FILE *g_hookLog = NULL;
#endif

static std::multimap<int, FunctionHook_private*, std::greater<int>> &FuncHooks()
{
	static std::multimap<int, FunctionHook_private*, std::greater<int>> funcHooks;
	return funcHooks;
}

static char g_hookLastError[1024] = {0};

FunctionHook_private::FunctionHook_private(const char *name, const std::type_info &type, void *hook, void **outInternalSuper, int priority) :
		_hook(hook),
		_outInternalSuper(outInternalSuper),
		_hSize(0),
		_sSize(0),
		_detour(NULL),
		_priority(priority)
{
    SetName(name, type.name());
    memcpy(&_outInternalSuper, &outInternalSuper, POINTER_BYTES);
	strcpy(_name, name);
	Add(this);
}

const char *FunctionHook_private::GetLastError() {return g_hookLastError;}

void FunctionHook_private::SetName(const char *name, const char *type)
{
	ConvertToUniqueName(_name, name, type);
	strncpy(_shortName, name, 512);
}

int FunctionHook_private::Init()
{
	for(auto it = FuncHooks().begin() ; it != FuncHooks().end() ; ++it)
	{
		if(!it->second->Install()) return 0;
	}
	return 1;
}

void FunctionHook_private::Add(FunctionHook_private *hook)
{
	FuncHooks().insert(std::pair<int, FunctionHook_private*>(hook->_priority, hook));
}

#define P(x) *(ptr++) = (x)
#define PS(x) *(((unsigned short*&)ptr)++) = (x)
#define PL(x) *(((unsigned int*&)ptr)++) = (x)

FunctionHook_private::~FunctionHook_private()
{
	if(_detour)
		delete (MologieDetours::Detour<void*>*)_detour;
}

int FunctionHook_private::Install()
{
	FunctionDefinition *def = dynamic_cast<FunctionDefinition*>(Definition::Find(_name)); // function definition
	if(!def)
	{
		snprintf(g_hookLastError, 1024, "Failed to install hook for %s: Function not found", _name);
		return 0;
	}

	struct ArgData
	{
		char r;
		char s;
	};

	const ArgData *argd = (const ArgData*)def->GetArgData();
	int argc = def->GetArgCount();
#ifdef __i386__
	unsigned char *ptr;
	int stackPos;
#ifdef USE_STACK_ALIGNMENT
	unsigned int stackAlignPosition;
	unsigned int stackAlignOffset;
	unsigned int registersUsedSize;
#endif // USE_STACK_ALIGNMENT
	int k;
	MEMPROT_SAVE_PROT(oldProtect);
	MEMPROT_PAGESIZE();
#endif // __i386__

	//==================================================
	// Internal hook
	// Converts userpurge to thiscall to call the user
	// defined hook

#ifdef __i386__
	ptr = _internalHook;

	// Prologue
	P(0x55);					// push ebp
	P(0x89); P(0xe5);			// mov ebp, esp

	// Not sure yet if this is different on 64-bit, I think it is because of push EBP + CALL so maybe?
	// Compute stack size
	#ifdef USE_STACK_ALIGNMENT
	registersUsedSize = 0;
	#endif // USE_STACK_ALIGNMENT
	stackPos = 8;
	for(int i=0 ; i<argc ; ++i)
	{
		if(argd[i].r < 0)
			stackPos += 4 * argd[i].s;
        #ifdef USE_STACK_ALIGNMENT
        else
            registersUsedSize += 4; // Must also include arguments that come in on registers that we push to the stack for proper alignment computation
        #endif // USE_STACK_ALIGNMENT
	}

	#ifdef USE_STACK_ALIGNMENT
        stackAlignPosition = stackPos + registersUsedSize;
        /* We need to account for everything pushed onto the stack so we can compute the proper 16-byte alignment per System V ABI specification */
        if(def->IsVoid() || !def->IsLongLong())
            stackAlignPosition += 4;
        if(def->IsVoid())
            stackAlignPosition += 4;
        stackAlignPosition += 4 * 4; // Because of the regular ECX/EBX/ESI/EDI registers we always push (or their R equivalents for 64-bit),

        // Modulo to get amount of padding we need to add to ensure the correct alignment
        stackAlignOffset = (STACK_ALIGNMENT_SIZE - (stackAlignPosition % STACK_ALIGNMENT_SIZE)) % STACK_ALIGNMENT_SIZE;
        
        // Reserve some extra space to ensure proper stack alignment
        if(stackAlignOffset != 0) {
            P(0x83); P(0xec); P(stackAlignOffset); // sub esp, N8
        }
	#endif // USE_STACK_ALIGNMENT

	// Push general purpose registers
	if(def->IsVoid() || !def->IsLongLong())
		P(0x52);	// push edx
	if(def->IsVoid())
		P(0x50);	// push eax
	P(0x51);	// push ecx
	P(0x53);	// push ebx
	P(0x56);	// push esi
	P(0x57);	// push edi

	// Copy arguments to their appropriate location
	int sizePushed = 0;
	k = stackPos;
	for(int i=argc-1 ; i>=0 ; --i)
	{
		if(def->IsThiscall() && i == 0)
		{
			// special case: this (shouldn't be pushed to the stack but copied to ecx)
			if(argd[i].r >= 0)
			{
				if(argd[i].r != 1) // no need to do mov ecx, ecx
				{
					P(0x89); P(0xc1 | ((argd[i].r & 7) << 3));	// mov ecx, XXX
				}
			}
			else
			{
				k -= 4;
				P(0x8b); P(0x4d); P(k);							// mov ecx, [ebp+8+4*X]
			}
		}
		else
		{
			if(argd[i].r >= 0)
			{
				P(0x50 + argd[i].r);							// push XXX
				sizePushed += 4;
			}
			else
			{
				for(int j=0 ; j<argd[i].s ; ++j)
				{
					k -= 4;
					P(0xff); P(0x75); P(k);						// push [ebp+8+4*X]
					sizePushed += 4;
				}
			}
		}
	}

	if(def->isMemPassedStructPointer())
        sizePushed -= 4;


	// Call the hook
	P(0xE8); PL((uintptr_t)_hook - (uintptr_t)ptr - 4);	// call _hook

#if OUR_OWN_FUNCTIONS_CALLEE_DOES_CLEANUP == 0
    if(sizePushed != 0)
    {
        // If our hook function requires caller cleanup, increment the stack pointer here. This will only be true on non-Windows platforms where our hook will be generated as __cdecl
        if(sizePushed < 128)	{ P(0x83); P(0xc4); P(sizePushed); }	// add esp, N8
        else					{ P(0x81); P(0xc4); PL(sizePushed); }	// add esp, N32
    }
#endif // OUR_OWN_FUNCTIONS_CALLEE_DOES_CLEANUP

	// Restore all saved registers
	P(0x5f);	// pop edi
	P(0x5e);	// pop esi
	P(0x5b);	// pop ebx
	P(0x59);	// pop ecx
	if(def->IsVoid())
		P(0x58);	// pop eax
	if(def->IsVoid() || !def->IsLongLong())
		P(0x5a);	// pop edx

	// Epilogue
	P(0x89); P(0xec);				// mov esp, ebp
	P(0x5d);						// pop ebp
	if(stackPos > 8 && !def->NeedsCallerCleanup())
	{
		P(0xc2); PS(stackPos - 8);	// ret 4*N
	}
	else if(def->isMemPassedStructPointer()) // TODO: Might need to limit this only to Sys V i386 ABI and not Windows also?
	{
        P(0xc2); PS(4);
	}
	else
		P(0xc3);					// ret

	_hSize = ptr - _internalHook;
	MEMPROT_UNPROTECT(_internalHook, _hSize, oldProtect);
#endif // __i386__

	// Install the hook with MologieDetours
	try
	{
#ifdef __i386__
        if(def->forceDetourSize()) // This flag should be used with caution as it'll allow it to skip past RET when writing the detour, if used on a function that was larger it'll create garbage code.
            _detour = new MologieDetours::Detour<void*>(def->GetAddress(), _internalHook, MOLOGIE_DETOURS_DETOUR_SIZE);
        else
            _detour = new MologieDetours::Detour<void*>(def->GetAddress(), _internalHook);
#else
        if(def->forceDetourSize()) // This flag should be used with caution as it'll allow it to skip past RET when writing the detour, if used on a function that was larger it'll create garbage code.
            _detour = new MologieDetours::Detour<void*>(def->GetAddress(), _hook, MOLOGIE_DETOURS_DETOUR_SIZE);
        else
            _detour = new MologieDetours::Detour<void*>(def->GetAddress(), _hook);
#endif // __amd64__
	}
	catch(MologieDetours::DetourException &e)
	{
		snprintf(g_hookLastError, 1024, "Failed to install hook for %s: %s", _name, e.what());
		return 0;
	}
	void *original = ((MologieDetours::Detour<void*>*)_detour)->GetOriginalFunction();

	//==================================================
	// Internal super
	// Converts thiscall to userpurge to call the
	// original function from the user defined hook
#ifdef __i386__
	ptr = _internalSuper;

	// Prologue
	P(0x55);					// push ebp
	P(0x89); P(0xe5);			// mov ebp, esp

	// TODO: I think this needs to change for 64-bit
	// Compute stack size
	#ifdef USE_STACK_ALIGNMENT
	registersUsedSize = 0;
	#endif // USE_STACK_ALIGNMENT
	stackPos = 8;
	for(int i=0 ; i<argc ; ++i)
	{
		if(!def->IsThiscall() || i != 0)
			stackPos += 4 * argd[i].s;

        #ifdef USE_STACK_ALIGNMENT
        if(argd[i].r >= 0)
            registersUsedSize += 4;
        #endif // USE_STACK_ALIGNMENT
	}

	#ifdef USE_STACK_ALIGNMENT
        stackAlignPosition = stackPos - registersUsedSize; // Need to ignore arguments currently on the stack that are destined for register storage as they will not be pushed back to the stack.
        /* We need to account for everything pushed onto the stack so we can compute the proper 16-byte alignment per System V ABI specification */
        if(def->IsVoid() || !def->IsLongLong())
            stackAlignPosition += 4;
        if(def->IsVoid())
            stackAlignPosition += 4;
        stackAlignPosition += 4 * 4; // Because of the regular ECX/EBX/ESI/EDI registers we always push (or their R equivalents for 64-bit),

        // Modulo to get amount of padding we need to add to ensure the correct alignment
        stackAlignOffset = (STACK_ALIGNMENT_SIZE - (stackAlignPosition % STACK_ALIGNMENT_SIZE)) % STACK_ALIGNMENT_SIZE;
        
        // Reserve some extra space to ensure proper stack alignment
        if(stackAlignOffset != 0) {
            P(0x83); P(0xec); P(stackAlignOffset); // sub esp, N8
        }
	#endif // USE_STACK_ALIGNMENT

	// Push general purpose registers
	if(def->IsVoid() || !def->IsLongLong())
		P(0x52);	// push edx
	if(def->IsVoid())
		P(0x50);	// push eax
	P(0x51);	// push ecx
	P(0x53);	// push ebx
	P(0x56);	// push esi
	P(0x57);	// push edi

	// Copy arguments to their appropriate location
	// Stack arguments first
    sizePushed = 0;
	k = stackPos;
	for(int i=argc-1 ; i>=0 ; --i)
	{
		if(def->IsThiscall() && i == 0)
		{
			if(argd[i].r < 0)
			{
				// special case: this (shouldn't be taken from the stack but copied from ecx)
				P(0x51);								// push ecx
				sizePushed += 4;
			}
		}
		else
		{
			if(argd[i].r < 0)
			{
				for(int j=0 ; j<argd[i].s ; ++j)
				{
					k -= 4;
					P(0xff); P(0x75); P(k);				// push [ebp+8+4*X]
					sizePushed += 4;
				}
			}
			else
				k -= 4 * argd[i].s;
		}
	}

	// Now register based arguments
	k = 8;
	for(int i=0 ; i<argc ; ++i)
	{
		if(def->IsThiscall() && i == 0)
		{
			// special case: this (shouldn't be taken from the stack but copied from ecx)
			if(argd[i].r >= 0 && argd[i].r != 1) // no need to do mov ecx, ecx
			{
				P(0x89); P(0xc8 | (argd[i].r & 7));		// mov XXX, ecx
			}
		}
		else
		{
			if(argd[i].r >= 0)
			{
				P(0x8b); P(0x45 | ((argd[i].r & 7)<<3));
				P(k);							// mov XXX, [ebp+8+4*X]
			}
			k += 4 * argd[i].s;
		}
	}
	
	if(def->isMemPassedStructPointer())
        sizePushed -= 4;

	// Call the original function
	P(0xE8); PL((uintptr_t)original - (uintptr_t)ptr - 4);	// call original

	// If the function requires caller cleanup, increment the stack pointer here
	if(def->NeedsCallerCleanup() && sizePushed != 0)
	{
		if(sizePushed < 128)	{ P(0x83); P(0xc4); P(sizePushed); }	// add esp, N8
		else					{ P(0x81); P(0xc4); PL(sizePushed); }	// add esp, N32
	}

	// Pop general purpose registers
	P(0x5f);	// pop edi
	P(0x5e);	// pop esi
	P(0x5b);	// pop ebx
	P(0x59);	// pop ecx
	if(def->IsVoid())
		P(0x58);	// pop eax
	if(def->IsVoid() || !def->IsLongLong())
		P(0x5a);	// pop edx

	// Epilogue
	P(0x89); P(0xec);				// mov esp, ebp
	P(0x5d);						// pop ebp

	if(stackPos > 8 && OUR_OWN_FUNCTIONS_CALLEE_DOES_CLEANUP)
	{
		P(0xc2); PS(stackPos - 8);	// ret 4*N
	}
	else if(def->isMemPassedStructPointer()) // TODO: Might need to limit this only to Sys V i386 ABI and not Windows also? (but then again, the OUR_OWN_FUNCTIONS_CALLEE_DOES_CLEANUP thing might already take care of this for Windows)
	{
        P(0xc2); PS(4);
	}
	else
		P(0xc3);					// ret

	_sSize = ptr - _internalSuper;
	MEMPROT_UNPROTECT(_internalSuper, _sSize, oldProtect);

	// Set the external reference to internalSuper so it can be used inside the user defined hook

	*_outInternalSuper = _internalSuper;
#endif // __i386__
#ifdef __amd64__
	// Set the external reference to the original function so it can be used inside the user defined hook
	*_outInternalSuper = original;
#endif // __amd64__

	Log("Successfully hooked function %s\n", _name);
#ifdef __amd64__
	Log("HookAddress: " PTR_PRINT_F ", SuperAddress: " PTR_PRINT_F "\n\n", (uintptr_t) _hook, (uintptr_t) original);
#endif // __amd64__
#ifdef __i386__
#ifdef DEBUG
    Log("InternalHookAddress: " PTR_PRINT_F "\n", (uintptr_t)&_internalHook);
#endif // DEBUG
	Log("%s\ninternalHook:\n", _name);
    
	for(unsigned int i=0 ; i<_hSize ; ++i)
		Log("%02x ", _internalHook[i]);
    Log("\n");

#ifdef DEBUG
    Log("InternalSuperAddress: " PTR_PRINT_F "\n", (uintptr_t)&_internalSuper);
#endif // DEBUG
	Log("\ninternalSuper:\n", _name);

	for(unsigned int i=0 ; i<_sSize ; ++i)
		Log("%02x ", _internalSuper[i]);
    Log("\n");
#endif // __i386__


	return 1;
}

//================================================================================
// FunctionHook

void FunctionHook::Add(const char *name, const std::type_info &type, void *hook, void **outInternalSuper, int priority)
{

	new FunctionHook_private(name, type, hook, outInternalSuper, priority);
}
