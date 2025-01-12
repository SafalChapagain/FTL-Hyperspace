:: parsefuncs <input file> <function definitions path> <output cpp> <output h>
CALL ..\parsefuncs functions\win32\FTLGameStripped.h functions\win32\1.6.9 ..\..\FTLGameWin32.cpp ..\..\FTLGameWin32.h i386-w64-mingw32
CALL ..\parsefuncs functions\mac/FTLGameStripped.h functions\mac\1.6.13 ..\..\FTLGameMac.cpp ..\..\FTLGameMac.h x86_64-apple-darwin
CALL ..\parsefuncs functions\ELF_x86\FTLGameStripped.ELF32.h functions\ELF_x86\1.6.13 ..\..\FTLGameELF32.cpp ..\..\FTLGameELF32.h i386-pc-linux
CALL ..\parsefuncs functions\ELF_amd64\FTLGameStripped.h functions\ELF_amd64\1.6.13 ..\..\FTLGameELF64.cpp ..\..\FTLGameELF64.h x86_64-pc-linux
CALL ..\parsefuncs functions\mac\FTLGameStripped.h functions\mac\1.6.13 ..\..\FTLGameMacOSAMD64.cpp ..\..\FTLGameMacOSAMD64.h x86_64-pc-darwin
pause
