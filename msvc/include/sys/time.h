#ifndef UDPCAST_MSVC_SYS_TIME_H
#define UDPCAST_MSVC_SYS_TIME_H

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <winsock2.h>
#include <windows.h>
#include <time.h>

static inline int gettimeofday(struct timeval *tv, void *tz)
{
    FILETIME ft;
    unsigned __int64 ticks;
    (void)tz;

    if (tv == NULL) {
        return -1;
    }

    GetSystemTimeAsFileTime(&ft);
    ticks = ((unsigned __int64)ft.dwHighDateTime << 32) | ft.dwLowDateTime;
    ticks -= 116444736000000000ULL;
    tv->tv_sec = (long)(ticks / 10000000ULL);
    tv->tv_usec = (long)((ticks % 10000000ULL) / 10ULL);
    return 0;
}

#endif
