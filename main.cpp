#include "main.h"
#include <stdio.h>
#include "Global.h"

// TODO: Add GCC poison pragma for some of the Windows specific bullshit functions & types so that we stop other devs from reintroducing them. https://gcc.gnu.org/onlinedocs/cpp/Pragmas.html#Pragmas (like sfopen!)
// TODO: Add GCC dependency pragma to Lua parser for the FTLGame files to have GCC auto complain if you updated the ZHL files (if it's possible to match a whole folder, not sure)
// TODO: Add GCC line preprocessor directives for the Lua parser to reference the correct original lines in the ZHL files maybe? https://gcc.gnu.org/onlinedocs/cpp/Line-Control.html#Line-Control

#ifdef _WIN32
#include <windef.h>

extern "C" BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {

        case DLL_PROCESS_ATTACH:
            {
#ifdef DEBUG
            AllocConsole();
            freopen("conin$", "r", stdin);
            freopen("conout$", "w", stdout);
            freopen("conout$", "w", stderr);
            printf("Hyperspace.dll is loaded\n");
#endif



            ZHL::SetLogPath("zhl.log");
            ZHL::Init();

            G_->Initialize();




            break;
            }
        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }

    return TRUE; // succesful
}
#elif defined(__linux__)
void __attribute__((constructor)) launchHyperspace() {

#ifdef DEBUG
    /* *NIX always has a console, it just matters if you launch FTL from it or not */
    /* If we wanted a nice way for consoles on Steam I suppose we could redirect the standard IOs to like some UNIX socket/file handle or something
     * That or you could modify steam's script that starts FTL to redirect the stdin/stdout/stderr to handles of your choice.
     * GOG is trivial, launch it from a terminal.
     */
    printf("Hyperspace.so is loaded\n");
#endif

            ZHL::SetLogPath("zhl.log");
            ZHL::Init();

            G_->Initialize();
}
#elif defined(__APPLE__)
void __attribute__((constructor)) launchHyperspace() {

#ifdef DEBUG
    printf("Hyperspace.dylib is loaded\n");
#endif

            ZHL::SetLogPath("zhl.log");
            ZHL::Init();

            G_->Initialize();
}
#endif
