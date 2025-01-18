#pragma once

#define JUMP_INSTRUCTION "jmp *%0"
#ifdef _WIN32
    #define FUNC_NAKED __declspec(naked)
    #ifdef LIBZHL_EXPORTS
        #define LIBZHL_API __declspec(dllexport)
    #else
        #define LIBZHL_API __declspec(dllimport)
    #endif
    #ifdef _MSC_VER
        // MSVC Requires Intel assembler syntax and cannot handle AT&T style
        #undef JUMP_INSTRUCTION
        #define JUMP_INSTRUCTION "jmp %0"
    #endif // MSVC
#elif defined(__linux__) || defined(__APPLE__)
    // Linux exports all symbols, we don't need to be specific like in Windows.
    // If we want to optimize this library in the future we'd need to change things around to an EXPORTED & NON_EXPORTED definition and set the __attribute___((visibility( thing to explicitly hide some exports on *NIX systems
    // SEE: https://gcc.gnu.org/wiki/Visibility
    #define LIBZHL_API
    #if __GNUC__ < 8 && !defined(__clang__)
        #error "GCC version too old, must be at least version 8 to support naked functions"
    #endif
    #define FUNC_NAKED __attribute__((naked))
#else
    #error "Unsupported OS"
#endif

#include <stdlib.h>
#include <typeinfo>
#include <cstdio>
#include <utility>
#include <new>

//=================================================================================================

namespace ZHL
{
	void Init();
	void SetLogPath(const char *logPath);
}

class FunctionHook
{
private:
	static void Add(const char *name, const std::type_info &type, void *hook, void **outInternalSuper, int priority);

public:
	template <class T> FunctionHook(const char *name, const std::type_info &type, T hook, void **outInternalSuper, int priority)
	{
		Add(name, type, *(void**)&hook, outInternalSuper, priority);
	}
};

//=================================================================================================

#define _DEFINE_METHOD_HOOK1(_id, _classname, _name, _priority, ...) \
	namespace { namespace Hook_##_id { \
		static void *internalSuper = NULL; \
		struct wrapper : public _classname { \
			using _callsign = auto (wrapper::*) __VA_ARGS__; \
			auto hook __VA_ARGS__ ; \
			template <typename... Args> decltype((std::declval<wrapper>().*(std::declval<_callsign>()))(std::declval<Args>()...)) super(Args&&... args) { \
				_callsign mfp = &wrapper::hook; \
				uintptr_t *mfpAsUintPtr = reinterpret_cast<uintptr_t*>(&mfp); \
				*mfpAsUintPtr = reinterpret_cast<uintptr_t&>(internalSuper) + (*mfpAsUintPtr % 2 == 1 ? 1 : 0); \
				return (this->*mfp)(std::forward<Args>(args)...); \
			} \
		}; \
		static FunctionHook hookObj = FunctionHook(#_classname "::" #_name, typeid(auto (_classname::*) __VA_ARGS__), &wrapper::hook, &internalSuper, _priority); \
	} } \
	auto Hook_##_id ::wrapper::hook __VA_ARGS__

#define _DEFINE_METHOD_HOOK0(_id, _classname, _name, _priority, ...) _DEFINE_METHOD_HOOK1(_id, _classname, _name, _priority, __VA_ARGS__)

#define HOOK_METHOD(_classname, _name, ...) _DEFINE_METHOD_HOOK0(__LINE__, _classname, _name, 0, __VA_ARGS__)
#define HOOK_METHOD_PRIORITY(_classname, _name, _priority, ...) _DEFINE_METHOD_HOOK0(__LINE__, _classname, _name, _priority, __VA_ARGS__)

//=================================================================================================

#define _DEFINE_STATIC_HOOK1(_id, _classname, _name, _priority, _type) \
	namespace { namespace Hook_##_id { \
		static void *internalSuper = NULL; \
		struct wrapper : public _classname { \
			using _callsign = auto __stdcall (*) _type; \
			static auto __stdcall hook _type ; \
			template <typename... Args> static decltype(std::declval<_callsign>()(std::declval<Args>()...)) super(Args&&... args) { \
				return (*reinterpret_cast<_callsign*>(&internalSuper))(std::forward<Args>(args)...); \
			} \
		}; \
		static FunctionHook hookObj(#_classname "::" #_name, typeid(auto (*) _type), &wrapper::hook, &internalSuper, _priority); \
	} } \
	auto Hook_##_id ::wrapper::hook _type

#define _DEFINE_STATIC_HOOK0(_id, _classname, _name, _priority, _type) _DEFINE_STATIC_HOOK1(_id, _classname, _name, _priority, _type)

#define HOOK_STATIC(_classname, _name, _type) _DEFINE_STATIC_HOOK0(__LINE__, _classname, _name, 0, _type)
#define HOOK_STATIC_PRIORITY(_classname, _name, _priority, _type) _DEFINE_STATIC_HOOK0(__LINE__, _classname, _name, _priority, _type)

//=================================================================================================

#define _DEFINE_GLOBAL_HOOK1(_id, _name, _priority, _type) \
	namespace { namespace Hook_##_id { \
		static void *internalSuper = NULL; \
		using _callsign = auto __stdcall (*) _type; \
		static auto __stdcall hook _type ; \
		template <typename... Args> static decltype(std::declval<_callsign>()(std::declval<Args>()...)) super(Args&&... args) { \
			return (*reinterpret_cast<_callsign*>(&internalSuper))(std::forward<Args>(args)...); \
		} \
		\
		static FunctionHook hookObj(#_name, typeid(auto (*) _type), &hook, &internalSuper, _priority); \
	} } \
	auto __stdcall Hook_##_id ::hook _type

#define _DEFINE_GLOBAL_HOOK0(_id, _name, _priority, _type) _DEFINE_GLOBAL_HOOK1(_id, _name, _priority, _type)

#define HOOK_GLOBAL(_name, _type) _DEFINE_GLOBAL_HOOK0(__LINE__, _name, 0, _type)
#define HOOK_GLOBAL_PRIORITY(_name, _priority, _type) _DEFINE_GLOBAL_HOOK0(__LINE__, _name, _priority, _type)
