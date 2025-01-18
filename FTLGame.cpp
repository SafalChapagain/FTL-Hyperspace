#ifdef _WIN32
    #include "FTLGameWin32.cpp"
#elif defined(__linux__)
    #ifdef __i386__
        #include "FTLGameELF32.cpp"
    #elif defined(__amd64__)
        #include "FTLGameELF64.cpp"
    #else
        #error "Unsupported architecture"
    #endif
#elif defined(__APPLE__)
    #include "FTLGameMacOSAMD64.cpp"
#else
    #error "Unsupported OS"
#endif
