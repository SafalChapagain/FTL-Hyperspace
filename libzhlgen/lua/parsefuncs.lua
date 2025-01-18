local inputPath, funcPath, outputCPP, outputH, mode = ...
local cparser = require("cparser")
local lfs = require("lfs")

-- Currently supported "HOST" modes
-- i386-*linux* -- GCC/LLVM
-- i386-*mingw* -- Windows GCC (or LLVM)
-- i386-*windows* -- MSVC
-- x86_64-*linux* -- GCC/LLVM
-- x86_64-*darwin -- LLVM

local arch
local archPushSize = 4 -- Bytes of default register/stack push size for the CPU architecture
if string.find(mode, "i386") ~= nil then
    arch = "i386"
elseif string.find(mode, "x86_64") ~= nil then
    arch = "x86_64"
    archPushSize = 8
else
    error("Unsupported Architecture")
end

-- local compiler
local isPOSIX = false -- TODO: Still use this, but should probably clean this up into just a check for SystemVi386ABI & SystemVAMD64ABI as it's kinda a mess where it's used right now
local useStackAlignment = false -- Aligns the stack before CALL instruction (as required by System V ABI specification)
local thiscallFirstArgumentECX = false -- Microsoft specific __thiscall, first argument is passed by ECX all others are stack. This does not affect MSVC vs GCC's order of the this argument.
local structPointerAfterHiddenArguments = false -- This affects order of a memory-passed struct pointer after hidden arguments like `this`, MSVC puts it after other hidden arguments, GCC puts it always as the first argument.
local memPassedStructsPoppedByCallee = false -- Do functions who are not normally callee cleanup for some stupid reason decide to cleanup one argument when passing a struct via memory... System V i386 ABI does this for some historical bizzare reason.
local useIntelASMSyntax = false -- True for Intel ASM, False for AT&T style. MSVC requires Intel, GCC can use either, Clang requires AT&T.
local saveAllRegistersForSomeReason = true
local recordClobberedRegisters = false
local stackAlignmentSize = 0x10
local useNaked = true
local compiler_passSmallStructsInTwoRegisters = true -- Should small structs be passed in EDX:EAX (or RDX:RAX) or only returned by memory pointer
-- TODO: Maybe read stdNamespaceSizes and some of these other compiler/libstdc++ configuration settings from a separate config file? Or maybe from the IDA stripped header file under different names?
local stdNamespaceSizes = {
	[ "string" ] = 28,
	[ "vector" ] = 16,
	[ "set" ] = 16,
	[ "pair" ] = 8
}
if string.find(mode, "linux") ~= nil then
    -- compiler = "gcc"
    useStackAlignment = true
    isPOSIX = true
	useIntelASMSyntax = false -- LLVM/Clang only supports AT&T Syntax, GCC supports both, so use AT&T Syntax instead of Intel
    saveAllRegistersForSomeReason = false
    useNaked = true
    recordClobberedRegisters = true
	if arch == "i386" then
		memPassedStructsPoppedByCallee = true
		compiler_passSmallStructsInTwoRegisters = false -- Pass all structs by memory even if they fit in EDX:EAX
		-- Note this stdNamespaceSizes is setup for GCC 4.8.5's libstdc++, these sizes might be different in newer versions, string most certainly is different.
		stdNamespaceSizes = {
			[ "string" ] = 28,
			[ "vector" ] = 12,
			[ "set" ] = 24, -- Unknown if correct
			[ "pair" ] = 8,
			[ "map" ] = 24
		}
	elseif arch == "x86_64" then
		-- Note this stdNamespaceSizes is setup for GCC 4.8.5's libstdc++, these sizes might be different in newer versions, string most certainly is different.
		stdNamespaceSizes = {
			[ "string" ] = 28,
			[ "vector" ] = 24,
			[ "set" ] = 48, -- Unknown if correct
			[ "pair" ] = 8,
			[ "map" ] = 48
		}
    end
elseif string.find(mode, "darwin") ~= nil then
    -- compiler = "gcc"
    useStackAlignment = true
    isPOSIX = true
	useIntelASMSyntax = false -- LLVM/Clang only supports AT&T Syntax, GCC supports both, so use AT&T Syntax instead of Intel
    saveAllRegistersForSomeReason = false
    useNaked = true
    recordClobberedRegisters = true
	if arch == "i386" then
		error("32-bit Darwin is not supported")
	elseif arch == "x86_64" then
		-- Note this stdNamespaceSizes is setup for GCC 4.8.5's libstdc++, these sizes might be different in newer versions, string most certainly is different.
		stdNamespaceSizes = {
			[ "string" ] = 28,
			[ "vector" ] = 24,
			[ "set" ] = 48, -- Unknown if correct
			[ "pair" ] = 8,
			[ "map" ] = 48
		}
    end
elseif string.find(mode, "windows") ~= nil then
    thiscallFirstArgumentECX = true
    structPointerAfterHiddenArguments = true
	useIntelASMSyntax = true -- Use Intel syntax with MSVC
	if arch == "i386" then
		stdNamespaceSizes = {
			[ "string" ] = 28,
			[ "vector" ] = 16,
			[ "set" ] = 16,
			[ "pair" ] = 8
		}
	elseif arch == "x86_64" then
        error("64-bit x86 is not yet supported for Windows MSVC")
    end
    -- compiler = "msvc"
elseif string.find(mode, "mingw") ~= nil then
    thiscallFirstArgumentECX = true
	if arch == "i386" then
		stdNamespaceSizes = {
			[ "string" ] = 24,
			[ "vector" ] = 12,
			[ "set" ] = 24, -- Unknown if correct
			[ "pair" ] = 8,
			[ "map" ] = 24
		}
	elseif arch == "x86_64" then
        error("64-bit x86 is not yet supported for Windows MinGW")
    end
    -- compiler = "gcc"
else
    error("Unsupported OS")
end

local function makeset(t)
	for k,v in ipairs(t) do
		t[v], t[k] = true, nil
	end
	return t
end

local hasFuncDef = {}
hasFuncDef.EntityFactory = true

local structs = {}
local namespaces = {}
local vtables = {}
local pools = {}
local functionsByFile = {}
local functions = {}

local globalVars = {}

local globalPreCode, globalPostCode
local global = cparser.ParseDefinition("namespace Global {};")
global.dependencies = {}

local blacklist = makeset{
	"__m64";
	"__m128";
	"__m128d";
	"__m128i";
	"_EH4_SCOPETABLE_RECORD";
	"_EH4_SCOPETABLE";
	"struct_fileInfo";
	"struct_archive";
	"struct_a1";
	"struct_a1b";
	"struct_v3";
	"string_u";
	"LARGE_INTEGER";
	"type_info";
	"tagRECT";
}

function sortKeys(t)
    local sortedKeys = {}
    for k in pairs(t) do
        table.insert(sortedKeys, k)
    end
    table.sort(sortedKeys)
    return sortedKeys
end

----------------------------------------------------------------------------------
-- Read structure definitions generated by IDA

local f = io.open(inputPath, "r")
local str = f:read("*a")
f:close()

cparser.UseIdaFormat(true)
local defs = cparser.ParseDefinitions(str)
cparser.UseIdaFormat(false)

local function shouldBlacklist(t)
	if t.template then return true end
	
	if not t.parent then
		return blacklist[t.class]
	else
		while t.parent do
			t = t.parent
			if t.template then return true end
		end
		if t.class == "std" then return true end
	end
	
	return false
end

local function getsize_alignment(t)
	-- May need further verification
	local size = 4
	local alignment = 4
	
	local field_size = 0
	local field_alignment = 0
	
	if not t.ptr or #t.ptr == 0 then
		local sdef = structs[t:cname()]
		if sdef and sdef.fields then
			size = 0
			alignment = 0
			if sdef.inherits then
				for _,f in ipairs(sdef.inherits) do
					field_size, field_alignment = getsize_alignment(structs[f:cname()])
					size = math.ceil(size/field_alignment)*field_alignment + field_size
					alignment = math.max(alignment, field_alignment)
				end
			elseif sdef.vtable then
				size = math.ceil(size/4)*4 + 4 -- TODO: Is 4 correct on 64-bit?
				alignment = math.max(alignment, 4)
			end
			
			for _,f in pairs(sdef.fields) do
				field_size, field_alignment = getsize_alignment(f)
				size = math.ceil(size/field_alignment)*field_alignment + field_size
				alignment = math.max(alignment, field_alignment)
			end
		elseif t.class == "__int64" or t.class == "double" or t.class == 'uint64_t' or t.class == 'int64_t' then
			size = 8
			alignment = 8
		elseif t.class == "__int16" or t.class == "short" or t.class == 'uint16_t' or t.class == 'int16_t'  then
			size = 2
			alignment = 2
		elseif t.class == "__int8" or t.class == "char" or t.class == 'uint8_t' or t.class == 'int8_t' or t.class == "bool"  then
			size = 1
			alignment = 1
		elseif t.parent and t.parent.class == "std" then
			local stdStructSize = stdNamespaceSizes[t.class]
			if not stdStructSize then
				print("Warning, unknown size for std::" .. t.class)
			else
				size = stdNamespaceSizes[t.class]
			end
		elseif t.class == "SmartPointer" then
			size = 8
		elseif t.class == "ReferenceCount" then
			size = 12
		end 
    else
        size = archPushSize -- pointer size, only really ends up mattering on 64-bit as otherwise it was already 4
		alignment = archPushSize
	end
	
	if t.array and t.array > 1 then
		size = size + math.ceil(size/alignment)*alignment * (t.array-1)
	end
	
	return size, alignment
end

local function sizeof(t)
	local size
	local alignment
	
	size, alignment = getsize_alignment(t)
	
	return size
end

local function sizeof_aligned(t)
	return math.ceil(sizeof(t)/archPushSize)
end

----------------------------------------------------------------------------------
-- Perform some preprocessing on those structures

local function addDependency(v, name, ptr)
	local t = (ptr and 1) or 2
	
	v.dependencies[name] = math.max(v.dependencies[name] or 0, t)
	if v.parent then
		local ps = structs[v.parent:cname()]
		if ps then
			addDependency(ps, name, ptr)
		end
	end
end

local function processField(f, v)
	if not shouldBlacklist(f) then
		-- integer types
		if f.class == "_DWORD" then
			f.class, f.unsigned = "int", true
		elseif f.class == "_WORD" then
			f.class, f.unsigned = "short", true
		elseif f.class == "_BYTE" then
			f.class, f.unsigned = "char", true
		end
		
		-- struct dependencies
		local cname = f:cname()
		if structs[cname] then
			addDependency(v, cname, f:isPointer())
		end
	end
	
	-- template arguments
	for _,a in pairs(f.template or {}) do
		processField(a, v)
	end
	
	-- function arguments
	for _,a in pairs(f.args or {}) do
		processField(a, v)
	end
end

-- Register all non-blacklisted structs
for _,v in pairs(defs) do
	if not shouldBlacklist(v) then
		structs[v:cname()] = v
	end
end

-- Entity pools (we'll manually register those since they're a bit tricky)
--[[
for _,v in pairs(structs) do
	for k,f in pairs(v.fields) do
		local cname = f:cname()
		if structs[cname] and f.class:find("^Pool_") then
			local p = structs[cname]
			local pclass = p.fields[1].class
			local psize = p.fields[1].array
			
			pools[cname] = true
			f.class = "Pool"
			f.template = {
				setmetatable({class = pclass, ptr={}}, getmetatable(f)),
				setmetatable({class = tostring(psize), ptr={}}, getmetatable(f))
			}
		end
	end
end

for k,v in pairs(pools) do
	structs[k] = nil
end]]

-- vtables
for _,v in pairs(structs) do
	for k,f in pairs(v.fields) do
		local cname = f:cname()
		if k == 1 and f.name == "_vtable" and f:isPointer() and structs[cname] then
			-- vtables
			vtables[cname] = structs[cname]
			v.vtable = structs[cname]
			
			if v.vtable.fields[1] and v.vtable.fields[1].name == "Free" then
				v.hasVirtualDestructor = true
			end
		end
	end
	
	if v.vtable then
		table.remove(v.fields, 1)
	end
end

for k,v in pairs(vtables) do
	-- HACK: consecutive functions with the same name but different arguments are compiled in reverse order by MSVC
	-- ... go figure
	local lastName
	local seqStart
	for i=1, #v.fields+1 do
		local f = v.fields[i]
		local name
		if f then
			name = f.name:gsub("__.*$", "")
		end
		
		if name == lastName then
			if not seqStart then
				seqStart = i-1
			end
		else
			if seqStart then
				local seqEnd = i-1
				for j=0, (seqEnd-seqStart-1)/2 do
					v.fields[seqStart+j], v.fields[seqEnd-j] = v.fields[seqEnd-j], v.fields[seqStart+j]
				end
				seqStart = nil
			end
			lastName = name
		end
		
		if f and f.args and f.args[1] then f.args[1].hidden = true end
	end
	
	-- Process virtual functions with an implicit output argument
	for _,f in ipairs(v.fields) do
		if f.args and f.args[2] and f.args[2].name == "implicit_output" then
			table.remove(f.ptr)
			table.remove(f.args, 2)
		end
	end
	
	-- Remove this vtable from the structures list
	structs[k] = nil
end

-- remove any remaining vtables
for k,v in pairs(structs) do
	if v.class:lower():find("^vtable") then
		structs[k] = nil
	end
end

-- struct dependencies
for _,v in pairs(structs) do
	v.dependencies = {}
end

for _,v in pairs(structs) do
	-- nested classes
	if v.parent then
		local ps = structs[v.parent:cname()]
		if ps then
			if not ps.children then ps.children = {} end
			ps.children[v:cname()] = v
		else
			error(string.format("namespaces not supported yet (%s)", v.parent:cname()))
		end
	end
	
	for k,f in pairs(v.fields) do
		local cname = f:cname()
		if not f:isPointer() and structs[cname] and (f.name == "_entity" or f.name == "_base") then
			-- inheritance
			if v.inherits == nil then
				v.inherits = {}
			end
			table.insert(v.inherits, f)
			addDependency(v, cname, false)
			hasFuncDef[cname] = true
		end
		processField(f, v)
	end
	
	if v.vtable then
		for _,f in ipairs(v.vtable.fields) do
			processField(f, v)
		end
	end
	
	if v.inherits then
		for i = 1,#v.inherits do
			table.remove(v.fields, 1)
		end
	end
end

----------------------------------------------------------------------------------
-- Load function definitions

local tfiles = {}
for d in lfs.dir(funcPath) do
	local name = d:match("^(.-)%.zhl$")
    local filepath = funcPath.."/"..d
	local a = lfs.attributes(filepath)
    if name and a and a.mode == "file" then
        table.insert(tfiles, {
            path = filepath,
            name = name
        })
    end
end

table.sort(tfiles, function(a, b) return a.path < b.path end)

for k,fd in pairs(tfiles) do
    local name = fd.name
    local filename = fd.path
    local str = ""
    local f = io.open(filename, "r")
    if f then
        str = f:read("*a")
        f:close()
    end
    
    local t = cparser.ParseFunctions(str)
    
    -- Preprocess functions and their arguments
    for _, func in ipairs(t) do
        if func.struct then
            -- Generic code and extra dependencies for structs
            local s = structs[func:cname()]
            
            if s then
                if func.generic_code then
                    s.generic_code = (s.generic_code or "")..func.generic_code
                end
                
                if func.depends then
                    for _,d in ipairs(func.depends) do
                        local dname = d:cname()
                        addDependency(s, dname, false)
                    end
                end
            else
                local n = func:cname()
                if n == "GlobalPre" then
                    globalPreCode = (globalPreCode or "")..func.generic_code:gsub("\n\t", "\n")
                elseif n == "GlobalConst" then
                    globalConstDependencies = {}
                    local dummy = {dependencies = globalConstDependencies}
                    
                    if func.depends then
                        for _,d in ipairs(func.depends) do
                            local dname = d:cname()
                            addDependency(dummy, dname, false)
                        end
                    end
                    
                    globalConstCode = (globalConstCode or "")..func.generic_code:gsub("\n\t", "\n")
                elseif n == "GlobalPost" then
                    globalPostCode = (globalPostCode or "")..func.generic_code:gsub("\n\t", "\n")
                end
            end
        elseif func.args then
            -- Detect member functions
            if func.args[1] and func.args[1].name == "this" then
                func.thiscall = true
                func.args[1].hidden = true
            end
            
            -- Check if this function returns a struct
            local isImplicitType = true
            if func.class == "double" or func.class == "__int64" or func.class == "uint64_t" or func.class == "int64_t" then
                isImplicitType = false
            elseif func.class == "pair" and not isPOSIX then
                isImplicitType = false
            end
                
			local structMaxRegisterPassSize
			if compiler_passSmallStructsInTwoRegisters then
				structMaxRegisterPassSize = archPushSize * 2
			else
				structMaxRegisterPassSize = archPushSize
			end

            if sizeof(func) > structMaxRegisterPassSize and isImplicitType then
                -- if it does, insert a pointer to that struct as the first argument (second if first one is "this" and using MSVC)
                local i = 1
                -- Maybe simplified to just?
                -- if func.thiscall and compiler == "msvc" then
                --     i = 2
                -- end
                if structPointerAfterHiddenArguments then
                    while func.args[i] and func.args[i].hidden do i = i + 1 end
                end
                
                local a = cparser.ParseDefinition(string.format("%s *implicit_output;", func:cname()))
                a.reg = func.reg
                a.hidden = true
                if memPassedStructsPoppedByCallee then
                    func.memPassedPointer = true
                end
                table.insert(func.args, i, a)
            elseif sizeof(func) == archPushSize * 2 then
                func.longlong = true
            end
            
            if func.callingConvention ~= nil then
                local i = 0
                for k, arg in ipairs(func.args) do
                    arg.size = sizeof_aligned(arg)

                    if arch == "i386" then
                        if arg.size > archPushSize then -- Make sure under max size of struct passing in registers in argument for architecture/ABI, i386 Microsoft & System V is just single register I think but not certain. Above this size, use stack.
                            arg.reg = nil
                        else
                            i = i + 1
                        end

                        if func.callingConvention == "__cdecl" then
                            arg.reg = nil
                        elseif func.callingConvention == "__thiscall" then -- TODO: Print warning if __thiscall used on Linux, it's valid but results in Microsoft style passing on ECX
                            if i == 1 then
                                -- TODO: Support that arg #2 is ECX when using MSVC if and only if there was a return struct larger than 8 bytes. On GCC, first arg in thiscall is always ECX regardless of if it is the actual *this
                                arg.reg = "ecx"
                            else
                                arg.reg = nil
                            end
                        elseif func.callingConvention == "__regparm1" then
                            if i == 1 then
                                arg.reg = "eax"
                            else
                                arg.reg = nil
                            end
                        elseif func.callingConvention == "__regparm2" then
                            if i == 1 then
                                arg.reg = "eax"
                            elseif i == 2 then
                                arg.reg = "edx"
                            else
                                arg.reg = nil
                            end
                        elseif func.callingConvention == "__regparm3" then
                            if i == 1 then
                                arg.reg = "eax"
                            elseif i == 2 then
                                arg.reg = "edx"
                            elseif i == 3 then
                                arg.reg = "ecx"
                            else
                                arg.reg = nil
                            end
                        elseif func.callingConvention == "__vectorcall" then
                            -- TODO: Need to be aware of if arg is int or SSE type?
                            error("Unimplemented calling convention for x86: " .. func.callingConvention)
                        elseif func.callingConvention == "__fastcall" then
                            if i == 1 then
                                arg.reg = "ecx"
                            elseif i == 2 then
                                arg.reg = "edx"
                            else
                                arg.reg = nil
                            end
                        else
                            error("Unsupported calling convention for x86: " .. func.callingConvention)
                        end
                    elseif arch == "x86_64" then
                        i = i + 1
                        if func.callingConvention == "__amd64" then
                            -- Don't set any registers for AMD64 or do any computation for stack stuff, although registers are used none of the assembly code we use for x86_64 ever needs to know it so we just skip all this nonsense.
                        elseif func.callingConvention == "__vectorcall" then
                        else
                            error("Unsupported calling convention for x86_64: " .. func.callingConvention)
                        end
                    end
                end
            elseif arch == "x86_64" then
                error("Calling convention required on x86_64")
            else
                -- Precompute stack positions for all arguments
                local stackPos = 8
                local pushSize = 0
                local flt_i = 1
                local int_i = 1
                for k, arg in ipairs(func.args) do
                    arg.size = sizeof_aligned(arg)
                    if k == 1 and func.thiscall and arg.reg == "ecx" and thiscallFirstArgumentECX then
                        assert(arg.size == 1)
                    else
                        arg.pos = stackPos
                        local argMemory = archPushSize * arg.size
                        stackPos = stackPos + argMemory
                        if not arg.reg then
                            pushSize = pushSize + argMemory
                        end
                    end
                end
                
                func.stacksize = stackPos - 8 -- size of the stack for cleanup (the stack size the hook was called with, includes register targeted args if they were passed to this hook on the stack)
                func.stackCallPushSize = pushSize -- Size of the stack in the CALL to the target function (original size in target, ignores register args)
            end
            
            -- Special behaviour for void functions
            if func.class == "void" and (not func.ptr or #func.ptr == 0) then
                func.void = true
            end
            
            -- Process dependencies and register the function
            local ps = global
            if func.varparent then
                ps = structs[func.varparent:cname()] or global
            end
            
            processField(func, ps)
            
            if not ps.funcs then ps.funcs = {} end
            ps.funcs[#ps.funcs+1] = func
            
            if not functionsByFile[name] then functionsByFile[name] = {} end
            local fbb = functionsByFile[name]
            fbb[#fbb+1] = func
            functions[#functions+1] = func
        else
            -- Global variable, register it (todo: handle static members too)
            functions[#functions+1] = func
        end
    end
end

----------------------------------------------------------------------------------
-- Write those structs

local written = {}
local writing = {}
local prototypeWritten = {}
local included = {}

local function fileWriter(path)
	print(path)
	return setmetatable({
		f = io.open(path, "w");
		i = 0;
		included = {};
		declared = {};
	}, {
		__call = function(self, fmt, ...)
			local sp = string.rep("\t", self.i)
			local str = string.format(fmt, ...):gsub("\n", "\n"..sp)
			self.f:write(str)
		end,
		__index = {
			indent = function(self) self.i = self.i + 1 end;
			unindent = function(self) self.i = math.max(self.i - 1, 0) end;
			close = function(self) self.f:close() end;
		}
	})
end

---------------------------------------------------------------
-- Child structs

local writeStruct

local function writeChildStructs(struct, out)
	local cname = struct:cname()
	
--[==[
	-- Child structs
	if cname == "EntityFactory" then
		out([[

template <class T, int Size> struct Pool
{
	T _data[Size];
	int _current;
};
]])
	end
]==]
    local children = struct.children or {}
	local sortedChildrenKeys = sortKeys(children)
    for _,k in ipairs(sortedChildrenKeys) do
        writeStruct(children[k], out, struct)
	end
end

---------------------------------------------------------------
-- Fields

local function writeFields(struct, out)
	for _,f in pairs(struct.fields) do
		out("\n%s;", f:toStringFull(struct))
	end
end

---------------------------------------------------------------
-- Virtual functions

local ref_exceptions = {
	void = true;
	int = true;
	char = true;
	VertexAttributeDescriptor = true;
	ShaderInitData = true;
}

local function compareFuncs(f1, f2)
	if f1.name:gsub("__.*$", "") ~= f2.name:gsub("__.*$", "") then
		return false
	end
	
	if not f1.args and not f2.args then
		return true
	end
	
	local n1, n2 = 0, 0
	for _, a in ipairs(f1.args) do
		if not a.hidden then
			n1 = n1 + 1
		end
	end
	for _, a in ipairs(f2.args) do
		if not a.hidden then
			n2 = n2 + 1
		end
	end
	
	return n1 == n2
end

local function writeVirtualFunctions(struct, out)
	if not struct.vtable then return end
	
	for _,f in ipairs(struct.vtable.fields) do
		local name = f.name:gsub("__.*$", "")
		
	
		-- Look for a function definition in the structure that shares the same name and argument types
		for _, func in ipairs(struct.funcs or {}) do
			if compareFuncs(func, f) then
				f = func
				f.virtualDeclared = true
				break
			end
		end
		
		if f.name == "Free" then -- this is actually a virtual destructor
			if f.virtualDeclared then
				out("\nLIBZHL_API virtual ~%s();", struct.class)
			else
				--out("\nvirtual ~%s() LIBZHL_PLACEHOLDER", struct.class)
				out("\nvirtual ~%s() {}", struct.class)
			end
		elseif f.args then
			if f.virtualDeclared then
				out("\nLIBZHL_API virtual %s%s(", f:toString(), name)
			else
				out("\nvirtual %s%s(", f:toString(), name)
			end
			
			local i = 0
			for k,arg in ipairs(f.args) do
				if not arg.hidden then
					if i>0 then
						out(", ")
					end
					
					-- replace pointers with references
					if arg.ptr and #arg.ptr == 1 and arg.ptr[1] == "*" then
						local s = structs[arg:cname()]
						if (not s or (not s.vtable and not s.inherits)) and not ref_exceptions[arg.class] then
							arg.ptr[1] = "&"
						end
					end
					
					local str = arg:toString()..(arg.name or "")
					if arg.default then
						str = str.." = "..arg.default
					end
					
					out("%s", str)
					i = i+1
				end
			end
			--out(") = 0;")
			
			if f.virtualDeclared then
				out(");")
			else
				out(") LIBZHL_PLACEHOLDER")
			end
		else
			--out("\nvirtual void v__%s() = 0;", name)
			out("\nvirtual void v__%s();", name)
		end
	end
end

---------------------------------------------------------------
-- Functions

local function argsToString(func, names, def, includeThis, hideType, suffix)
	local t = {}
	local i = 0
	for _, arg in ipairs(func.args) do
		if not arg.hidden or (includeThis and arg.name == "this") then
            local str = ""
            if not hideType then
                str = arg:toString()
            end
			if names then
				str = str..arg.name
                if suffix ~= nil then
                    str = str..suffix
                end
				if def and arg.default then
					str = str.." = "..arg.default
				end
			end
			t[#t+1] = str
		end
	end
	return table.concat(t, ", ")
end

local function writeFunctions(struct, out)
	if struct.funcs then
        table.sort(struct.funcs, function(a, b) return a.name < b.name end)
		for _, func in ipairs(struct.funcs) do
			if func.args and not func.virtualDeclared and not func.noHook then
				out("\n")
				out("LIBZHL_API ")
				if func.static then
					out("static ")
				end
				if func.virtual then
					out("virtual ")
				end
				
				if func.virtual and func.name == "Free" then
					out("~%s();", struct.class)
				else
					out("%s", func:toString())

					if not func.thiscall then
						out("__stdcall ")
					end
					
					out("%s(", func.name)
					out(argsToString(func, true, true))
					out(")")
					if func.constfunc then out(" const") end
					out(";")
				end
			end
		end
		
		if #struct.funcs > 0 then
			out("\n")
		end
	end
end

---------------------------------------------------------------
-- Full struct

function writeStructDependencies(dep, out, parent)
    local sortedDepKeys = sortKeys(dep)
	local lastWasStructPrototype = false
	for _,c in ipairs(sortedDepKeys) do
        local n = dep[c]
		local st = structs[c]
		if parent then
			if st.parent and st.parent:cname() == parent:cname() then
				writeStruct(st, out, parent)
				lastWasStructPrototype = false
			end
		else
			while st.parent do
				st = structs[st.parent:cname()]
				n = 2
			end
			c = st:cname()
			
			if n == 1 then
				if not out.declared[c] then
					if not lastWasStructPrototype then out("\n") end
					out('struct %s;\n', c)
					out.declared[c] = true;
					lastWasStructPrototype = true
				end
			else
				writeStruct(st, out)
				lastWasStructPrototype = false
			end
		end
	end
end

function writeStruct(struct, out, parent)
	local isGlobal = struct.class == "Global"
	
	local cname = struct:cname()
	if written[cname] or writing[cname] then return end
	if struct.parent and not writing[struct.parent:cname()] then return end
	
	writing[cname] = true
	
	-----------------------------------------------------
	-- If this struct depends on other structs, write those first
	writeStructDependencies(struct.dependencies, out, parent)
	
	-----------------------------------------------------
	-- Write the struct
	
	if not isGlobal then
		if struct.vtable then
			out("\nstruct LIBZHL_INTERFACE %s", struct:cname(parent))
		else
			out("\nstruct %s", struct:cname(parent))
		end
		
		if struct.inherits then
			for i,v in ipairs(struct.inherits) do
				if i == 1 then
					out(" : %s", v:cname(parent))
				else
					out(", %s", v:cname(parent))
				end
			end
		end
		out("\n{")
		if struct.generic_code then
			out("%s", struct.generic_code)
		end
		out:indent()
		
		writeChildStructs(struct, out)
		writeVirtualFunctions(struct, out)
	end
	
	writeFunctions(struct, out)
	writeFields(struct, out)
	
	if not isGlobal then
		out:unindent()
        if struct.attribute then
            out("\n} __attribute__%s;\n", struct.attribute)
        else
            out("\n};\n")
        end
	end
	
	writing[cname] = false
	written[cname] = true
end

---------------------------------------------------------------
-- Functions

local function writeFunctionWrappers(funcs, out)
	local name_h = outputH:match("([^/\\]+)$")
	
	out([[#include "%s"
#include "zhl_internal.h"

#ifdef _WIN32
    #define FUNC_NAKED __declspec(naked)
#elif defined(__linux__) || defined(__APPLE__)
    #if __clang__
    #elif __GNUC__ < 8
        #error "GCC version too old, must be at least version 8"
    #endif
    #define FUNC_NAKED __attribute__((naked))
#endif

using namespace ZHL;

]], name_h)
	
	local regid = {
		eax = 0;
		ecx = 1;
		edx = 2;
		ebx = 3;
		esp = 4;
		ebp = 5;
		esi = 6;
		edi = 7;
	}

	-- C++ function implementations
	local counter = 0;
	for _, func in ipairs(funcs) do
		if func.args then
			-- function definition
			out([[namespace _func%d
{
	static void *func = 0;
]], counter)

            local isSystemVAMD64StandardCall = arch == "x86_64" and isPOSIX and func.callingConvention == "__amd64"

            if not isSystemVAMD64StandardCall then
                if #func.args == 0 then
                    out("\tstatic const short *argdata = NULL;\n")
                else
                    out("\tstatic short argdata[] = {")
                    i = 0
                    for _, arg in ipairs(func.args) do
                        if i>0 then
                            out(", ")
                        end
                        local reg = regid[arg.reg or ""] or 0xff
                        local sz = arg.size
                        
                        out("0x%x", reg + sz * 0x100)
                        i = i + 1
                    end
                    out("};\n")
                end
            end

			local isGlobal = not func.varparent
			local classname
			if func.varparent then classname = func.varparent:cname() end
			
			local flags = 0
            if not isSystemVAMD64StandardCall then
                if func.thiscall and not isPOSIX then flags = flags + 1 end
                if func.cleanup then flags = flags + 2 end
                if func.void then flags = flags + 4 end
                if func.longlong then flags = flags + 8 end
                if func.memPassedPointer then flags = flags + 16 end
            end
            if func.forceDetour then flags = flags + 32 end
			
			local funcptr
			if func.static or isGlobal then
				funcptr = string.format("%s(*)(%s)", func:toString(), argsToString(func, false))
			else
				funcptr = string.format("%s(%s::*)(%s)%s", func:toString(), classname, argsToString(func, false), (func.constfunc and " const") or "")
			end

			if isSystemVAMD64StandardCall then
                if isGlobal then
                    out("\tstatic FunctionDefinition funcObj(\"%s\", typeid(%s), \"%s\", nullptr, 0, %d, &func);\n", func.name, funcptr, func.sig or "", flags)
                else
                    out("\tstatic FunctionDefinition funcObj(\"%s::%s\", typeid(%s), \"%s\", nullptr, 0, %d, &func);\n", classname, func.name, funcptr, func.sig or "", flags)
                end
            else
                if isGlobal then
                    out("\tstatic FunctionDefinition funcObj(\"%s\", typeid(%s), \"%s\", argdata, %d, %d, &func);\n", func.name, funcptr, func.sig or "", #func.args, flags)
                else
                    out("\tstatic FunctionDefinition funcObj(\"%s::%s\", typeid(%s), \"%s\", argdata, %d, %d, &func);\n", classname, func.name, funcptr, func.sig or "", #func.args, flags)
                end
            end
            out("}\n\n")
			
			local isDestructor = func.virtual and func.name == "Free"
			
			--if not func.virtual then
			--if func.name ~= "Free" then
            if not func.noHook then
                if func.callingConvention ~= nil then
                    if isDestructor then
                        out("%s::~%s(", classname, func.varparent.class)
                    elseif isGlobal then
                        out("%s__stdcall %s(", func:toString(), func.name) -- TODO: Eliminate __stdcall except on MSVC
                    else
                        out("%s%s::%s(", func:toString(), classname, func.name)
                    end

                    if isDestructor then
                        out(")")
                    else
                        out(argsToString(func, true))
                        out(")")
                        if func.constfunc then out(" const") end
                    end
                    
                    out("\n{\n")

                    -- TODO: Support MSVC style rather than GCC style __attribute__ NOTE: MSVC sucks, it requires __fastcall and shit in the cast, so like typedef whatever (__fastcall *ptr)(def)
                    -- TODO: Maybe support ms_hook_prologue for Win32 API functions
                    -- TODO: Maybe support force_align_arg_pointer?
                    out("\ttypedef %s", func:toString())
                    if arch == "i386" then
                        if func.callingConvention == "__cdecl" then -- TODO: In the future make cdecl imply cleanup
                            -- TODO: On Linux, cdecl is the default across the board (same as thiscall), it could be left out of the generated code
                            out("__attribute__((cdecl)) ")
                        elseif func.callingConvention == "__thiscall" then -- TODO: Print warning if __thiscall used on Linux, it's valid but results in Microsoft style passing on ECX
                            out("__attribute__((thiscall)) ")
                        elseif func.callingConvention == "__regparm1" then
                            out("__attribute__((regparm(1))) ")
                        elseif func.callingConvention == "__regparm2" then
                            out("__attribute__((regparm(2))) ")
                        elseif func.callingConvention == "__regparm3" then
                            out("__attribute__((regparm(3))) ")
                        elseif func.callingConvention == "__vectorcall" then
                            out("__attribute__((vectorcall)) ")
                        elseif func.callingConvention == "__fastcall" then
                            out("__attribute__((fastcall)) ")
                        else
                            error("Unsupported calling convention for x86: " .. func.callingConvention)
                        end
                    elseif arch == "x86_64" then
                        if func.callingConvention == "__amd64" then
                        elseif func.callingConvention == "__vectorcall" then
                            out("__attribute__((vectorcall)) ")
                        else
                            error("Unsupported calling convention for x86_64: " .. func.callingConvention)
                        end
                    end

                    out("(*custom_arg_funcptr_t)(")
                    out(argsToString(func, true, false, true, false, "_arg")) -- TODO: Need to hide implicit attributes (but leave this attribute)
                    out(");\n")
                    
                    out("\tcustom_arg_funcptr_t execfunc = (custom_arg_funcptr_t) _func%d::func;\n", counter)
                    out("\treturn execfunc(")
                    out(argsToString(func, true, false, true, true)) -- TODO: Need to hide implicit attributes (but leave this attribute)
                    out(");\n")
                    out("}\n\n")
                elseif arch == "x86_64" then
                    error("Calling convention style definition required on x86_64, old register/assembly style not supported")
                else
                -- if true then
                    -- function implementation
                    if useNaked then
                        if isDestructor then
                            out("FUNC_NAKED %s::~%s(", classname, func.varparent.class)
                        elseif isGlobal then
                            out("FUNC_NAKED %s__stdcall %s(", func:toString(), func.name)
                        else
                            out("FUNC_NAKED %s%s::%s(", func:toString(), classname, func.name)
                        end
                    else
                        if isDestructor then
                            out("%s::~%s(", classname, func.varparent.class)
                        elseif isGlobal then
                            out("%s__stdcall %s(", func:toString(), func.name) -- TODO: Eliminate __stdcall except on MSVC
                        else
                            out("%s%s::%s(", func:toString(), classname, func.name)
                        end
                    end
                    
                    if isDestructor then
                        out(")")
                    else
                        out(argsToString(func, true))
                        out(")")
                        if func.constfunc then out(" const") end
                    end
                    
                    out("\n{")
                    
                    -- asm code
                    out("\n\t__asm__\n\t(")
                    
                    -- prolog
                    if useNaked then
                        if useIntelASMSyntax then
                            out("\n\t\t\"push ebp\\n\\t\"")
                            out("\n\t\t\"mov ebp, esp\\n\\t\"")
                        else
                            out("\n\t\t\"pushl %%%%ebp\\n\\t\"")
                            out("\n\t\t\"movl %%%%esp, %%%%ebp\\n\\t\"")
                        end
                    end
                    
                    local stackAlignPushSize = func.stackCallPushSize
                    if useNaked then
                        stackAlignPushSize = stackAlignPushSize + (archPushSize*2) -- size of CALL's saved return pointer (EIP/RIP) & base pointer (EBP/RBP) saved above
                    end
                    
                    if saveAllRegistersForSomeReason then
                        if func.void or not func.longlong then
                            stackAlignPushSize = stackAlignPushSize + archPushSize -- Because of push edx
                        end
                        if func.void then
                            stackAlignPushSize = stackAlignPushSize + archPushSize -- Because of push eax
                        end

                        stackAlignPushSize = stackAlignPushSize + (archPushSize*4) -- Because of the push ECX/EBX/ESI/EDI that we always push below
                    end
                    
                    -- We do this after the push ebp & move ebp, esp but before the other pushes so we don't have to worry about resetting the stack correctly afterwards (as all our arguments & pops are directly next to each other without a gap until we've already reset the saved esp stack pointer and would no longer care [ebp][gap][other registers & arguments]call[registers & arguments pop/remove][reset stack][pop ebp])
                    if useStackAlignment then
                        local stackAlignOffset = (stackAlignmentSize - (stackAlignPushSize % stackAlignmentSize)) % stackAlignmentSize
                        if(stackAlignOffset ~= 0) then

                            if useIntelASMSyntax then
                                out("\n\t\t\"sub esp, %d\\n\\t\"", stackAlignOffset)
                            else
                                out("\n\t\t\"subl $%d, %%%%esp\\n\\t\"", stackAlignOffset)
                            end
                        end
                    end
                    
                    if saveAllRegistersForSomeReason then
                        -- TODO: Change this to a list of "volatile" & "non-volatile" registers and we must only push & pop the non-volatiles. This might make it more generic, aside from the void & longlong 32-bit crap.
                        -- save all registers that matter for the ABI
                        if useIntelASMSyntax then
                            if func.void or not func.longlong then out("\n\t\t\"push edx\\n\\t\"") end
                            if func.void then out("\n\t\t\"push eax\\n\\t\"") end
                            out("\n\t\t\"push ecx\\n\\t\"")
                            out("\n\t\t\"push ebx\\n\\t\"")
                            out("\n\t\t\"push esi\\n\\t\"")
                            out("\n\t\t\"push edi\\n\\t\"")
                        else
                            if func.void or not func.longlong then out("\n\t\t\"pushl %%%%edx\\n\\t\"") end
                            if func.void then out("\n\t\t\"pushl %%%%eax\\n\\t\"") end
                            out("\n\t\t\"pushl %%%%ecx\\n\\t\"")
                            out("\n\t\t\"pushl %%%%ebx\\n\\t\"")
                            out("\n\t\t\"pushl %%%%esi\\n\\t\"")
                            out("\n\t\t\"pushl %%%%edi\\n\\t\"")
                        end
                    end
                    
                    -- push all stack based arguments
                    local sizePushed = 0
                    -- TODO: If we reserve stack space & use mov instead of push we can generate the assembly in the same forward-order as the register arguments and not have to have this separate block that operates backwards, this could probably simplify this logic.
                    for k = #func.args, 1, -1 do
                        local arg = func.args[k]
                        if not arg.reg then
                            if k == 1 and func.thiscall and not isPOSIX then
                                assert(arg.size == 1)
                                if useIntelASMSyntax then
                                    out("\n\t\t\"push ecx\\n\\t\"\t\t\t// %s", arg.name)
                                else
                                    out("\n\t\t\"pushl %%%%ecx\\n\\t\"\t\t\t// %s", arg.name)
                                end
                                sizePushed = sizePushed + archPushSize
                            else
                                for p=archPushSize*arg.size-archPushSize, 0, -archPushSize do
                                    if useIntelASMSyntax then
                                        out("\n\t\t\"push [ebp+%d]\\n\\t\"\t\t// %s", arg.pos + p, arg.name)
                                    else
                                        out("\n\t\t\"pushl %d(%%%%ebp)\\n\\t\"\t\t// %s", arg.pos + p, arg.name)
                                    end
                                    sizePushed = sizePushed + archPushSize
                                end
                            end
                        end
                    end
                    
                    -- then move all register based arguments to their respective registers
                    local int_i = 1
                    local flt_i = 1
                    local usedRegisters = {}
                    for k, arg in ipairs(func.args) do
                        if arg.reg then
                            assert(arg.size == 1)
                            table.insert(usedRegisters, "\"" .. arg.reg .. "\"")
                            if k == 1 and func.thiscall and not isPOSIX then
                                if arg.reg ~= "ecx" then
                                    if useIntelASMSyntax then
                                        out("\n\t\t\"mov %s, ecx\\n\\t\t// %s\\n\\t\"", arg.reg, arg.name)
                                    else
                                        out("\n\t\t\"movl %%%%ecx, %%%%%s\\n\\t\t// %s\\n\\t\"", arg.reg, arg.name)
                                    end
                                else
                                    out("\n\t\t\t// %s has %s", arg.reg, arg.name)
                                end
                            else
                                if useIntelASMSyntax then
                                    out("\n\t\t\"mov %s, [ebp+%d]\\n\\t\"\t// %s", arg.reg, arg.pos, arg.name)
                                else
                                    out("\n\t\t\"movl %d(%%%%ebp), %%%%%s\\n\\t\"\t// %s", arg.pos, arg.reg, arg.name)
                                end
                            end
                        end
                    end
                    
                    -- finally call the function
                    if useIntelASMSyntax then
                        out("\n\t\t\"call %%0\\n\\t\"")
                    else
                        out("\n\t\t\"call *%%0\\n\\t\"")
                    end

                    -- if the function requires caller cleanup, increment the stack pointer here
                    if func.cleanup then
                        if func.memPassedPointer then
                            sizePushed = sizePushed - archPushSize
                        end
                        if sizePushed > 0 then
                            if useIntelASMSyntax then
                                out("\n\t\t\"add esp, %d\\n\\t\"", sizePushed)
                            else
                                out("\n\t\t\"addl $%d, %%%%esp\\n\\t\"", sizePushed)
                            end
                        end
                    end
                    
                    if saveAllRegistersForSomeReason then
                        -- restore all registers
                        if useIntelASMSyntax then
                            -- TODO: ALl these pops could be simplified with a function to generate them & accepting in the register names, plus then having a "epilogue" function
                            out("\n\t\t\"pop edi\\n\\t\"")
                            out("\n\t\t\"pop esi\\n\\t\"")
                            out("\n\t\t\"pop ebx\\n\\t\"")
                            out("\n\t\t\"pop ecx\\n\\t\"")
                            if func.void then out("\n\t\t\"pop eax\\n\\t\"") end
                            if func.void or not func.longlong then out("\n\t\t\"pop edx\\n\\t\"") end
                        else
                            out("\n\t\t\"popl %%%%edi\\n\\t\"")
                            out("\n\t\t\"popl %%%%esi\\n\\t\"")
                            out("\n\t\t\"popl %%%%ebx\\n\\t\"")
                            out("\n\t\t\"popl %%%%ecx\\n\\t\"")
                            if func.void then out("\n\t\t\"popl %%%%eax\\n\\t\"") end
                            if func.void or not func.longlong then out("\n\t\t\"popl %%%%edx\\n\\t\"") end
                        end
                    end
                    
                    -- epilog
                    if useNaked then
                        if useIntelASMSyntax then
                            out("\n\t\t\"mov esp, ebp\\n\\t\"")
                            out("\n\t\t\"pop ebp\\n\\t\"")
                            if func.stacksize > 0 and not isPOSIX then
                                out("\n\t\t\"ret %d\\n\\t\"", func.stacksize)
                            elseif func.memPassedPointer then -- TODO: May have to limit to SysVi386 ABI not sure if this is valid for Windows MSVC
                                out("\n\t\t\"ret %d\\n\\t\"", 4)
                            else
                                out("\n\t\t\"ret\\n\\t\"")
                            end
                        else
                            out("\n\t\t\"movl %%%%ebp, %%%%esp\\n\\t\"")
                            out("\n\t\t\"popl %%%%ebp\\n\\t\"")
                            if func.stacksize > 0 and not isPOSIX then
                                out("\n\t\t\"ret $%d\\n\\t\"", func.stacksize)
                            elseif func.memPassedPointer then -- TODO: May have to limit to SysVi386 ABI not sure if this is valid for Windows MSVC
                                out("\n\t\t\"ret $%d\\n\\t\"", 4)
                            else
                                out("\n\t\t\"ret\\n\\t\"")
                            end
                        end
                    end
                    
                    out("\n\t\t :: \"m\"(_func%d::func)", counter)
                    if recordClobberedRegisters and next(usedRegisters) then
                        out("\n\t\t : %s", table.concat(usedRegisters, ", "))
                    end
                    out("\n\t);")
                    
                    out("\n}\n\n")
                end
            end
		else
			-- variable definition
			if func.reference then
				out("%s*__ptr_%s;\n\n", func:toString(), func.name)
				out([[namespace _var%d
{
	static VariableDefinition varObj("%s", "%s", &__ptr_%s);
}

]], counter, func.name, func.sig or "", func.name)
			elseif func.isOffsetVariable then
				out("%s%s;\n\n", func:toString(), func.name)
				out([[namespace _var%d
{
	static VariableDefinition varObj("%s", "%s", &%s, true, true);
}

]], counter, func.name, func.sig or "", func.name)
			elseif func.instruction then
				out("%s%s;\n\n", func:toString(), func.name)
				out([[namespace _instruction%d
{
	static VariableDefinition varObj("%s", "%s", &%s, false);
}

]], counter, func.name, func.sig or "", func.name)
			elseif func.noop then
				out([[namespace _noop%d
{
	static NoOpDefinition noOpObj("%s", "%s");
}

]], counter, func.name, func.sig or "", func.name)
			else
				out("%s%s;\n\n", func:toString(), func.name)
				out([[namespace _var%d
{
	static VariableDefinition varObj("%s", "%s", &%s);
}

]], counter, func.name, func.sig or "", func.name)
			end
		end
		counter = counter + 1
	end
end

---------------------------------------------------------------
-- Global vars

local function writeGlobalVars(funcs, out)
	for _,var in ipairs(funcs) do
		if not var.args and not var.noop then
			if var.reference then
				out("\nextern LIBZHL_API %s*__ptr_%s;", var:toString(), var.name)
				out("\n#define %s (*__ptr_%s)", var.name, var.name)
			else
				out("\nextern LIBZHL_API %s%s;", var:toString(), var.name)
			end
		end
	end
	out("\n");
end

local datestr = os.date()

-- .h
local f = fileWriter(outputH)
f([[#pragma once

#pragma warning( disable : 4722 )

#define LIBZHL_API 

#ifdef SWIG
    #define LIBZHL_INTERFACE
    #define __stdcall
    #define LIBZHL_PLACEHOLDER {(void)0;}
    #define __attribute__(x)
#elif defined(_WIN32)
    #define LIBZHL_INTERFACE __declspec(novtable)
    __declspec(noreturn) inline void __cdecl __NOP() {}
    #define LIBZHL_PLACEHOLDER {__NOP();}
#elif defined(__linux__) || defined(__APPLE__)
    #define LIBZHL_INTERFACE
    #define LIBZHL_PLACEHOLDER {\
        _Pragma("GCC diagnostic push") \
        _Pragma("GCC diagnostic ignored \"-Wreturn-type\"") \
        (void)0; } \
        _Pragma("GCC diagnostic pop")
    #define __stdcall
#endif

]])

if globalPreCode then
	f("%s\n", globalPreCode)
end

if globalConstCode then
	writeStructDependencies(globalConstDependencies, f)
	f("%s\n", globalConstCode)
end

local sortedStructKeys = sortKeys(structs)

for _,k in ipairs(sortedStructKeys) do
	writeStruct(structs[k], f)
end
writeStruct(global, f)
writeGlobalVars(functions, f)

if globalPostCode then
	f("%s\n", globalPostCode)
end

f:close()

-- .cpp
f = fileWriter(outputCPP)
writeFunctionWrappers(functions, f)
f:close()
