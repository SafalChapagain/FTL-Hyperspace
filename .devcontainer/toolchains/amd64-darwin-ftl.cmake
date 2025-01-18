if(NOT _FTL_TOOLCHAIN)
    set(_FTL_TOOLCHAIN 1)

    # Systemdefinition für macOS
    set(CMAKE_SYSTEM_NAME Darwin)

    # Definiere Flags für Compiler und Linker
    string(CONCAT _compiler_flags
            # Erzwinge den Build für AMD64 (x86_64)
            "-target x86_64-apple-macos10.13"

            # Für macOS ist Position Independent Code (PIC) erforderlich
            " -fPIC"

            # Verwende die C++11 ABI
            " -D_GLIBCXX_USE_CXX11_ABI=0"
    )
    string(CONCAT _linker_flags
            # Erzwinge die Verwendung von LLD als Linker
            " -fuse-ld=lld"

            # Link gegen das System-Framework auf macOS
            " -framework CoreFoundation"
    )

    # Compiler für macOS
    set(CMAKE_C_COMPILER "clang" CACHE PATH "")
    set(CMAKE_CXX_COMPILER "clang++" CACHE PATH "")

    # Compiler-Flags für verschiedene Build-Konfigurationen
    foreach(lang C CXX)
        set(CMAKE_${lang}_FLAGS_DEBUG_INIT "-DDEBUG")
        set(CMAKE_${lang}_FLAGS_RELEASE_INIT "-DNDEBUG")
        set(CMAKE_${lang}_FLAGS_MINSIZEREL_INIT "-DNDEBUG")
        set(CMAKE_${lang}_FLAGS_RELWITHDEBINFO_INIT "-DNDEBUG")

        # Füge die angepassten Compiler-Flags hinzu
        string(APPEND CMAKE_${lang}_FLAGS " ${_compiler_flags}")
    endforeach()

    # Linker-Flags
    set(CMAKE_SHARED_LINKER_FLAGS_INIT "${_linker_flags}")
    set(CMAKE_EXE_LINKER_FLAGS_INIT "${_linker_flags}")

    # macOS-spezifische Suchpfade für Libraries und Includes
    list(APPEND CMAKE_FIND_ROOT_PATH
            "/usr/local"       # Standardpfad für Homebrew
            "/Library/Frameworks"  # macOS Frameworks
    )
    set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
    set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
    set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

endif()