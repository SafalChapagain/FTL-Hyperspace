#ifndef __PAL_WINGENERIC_H__
#define __PAL_WINGENERIC_H__


#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#elif defined(__linux__) || defined(__APPLE__)
#else
#error Unknown Platform
#endif

#endif // __PAL_WINGENERIC_H__
