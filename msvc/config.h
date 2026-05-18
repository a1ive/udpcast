#ifndef UDPCAST_MSVC_CONFIG_H
#define UDPCAST_MSVC_CONFIG_H

/*
 * Static config for building udpcast with MSVC.  The autotools build writes a
 * root-level config.h; this file is selected only by the Visual Studio projects
 * through their msvc include path.
 */

#ifdef _MSC_VER
#ifndef __MINGW32__
#define __MINGW32__ 1
#endif
#ifndef __attribute
#define __attribute(x)
#endif
#ifndef __attribute__
#define __attribute__(x)
#endif
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_WARNINGS 1
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1
#endif

#include <stdint.h>
#include <stddef.h>

#ifdef _MSC_VER
#ifndef UDPCAST_SSIZE_T_DEFINED
typedef intptr_t ssize_t;
#define UDPCAST_SSIZE_T_DEFINED 1
#endif
#endif

#define HAVE_ATEXIT 1
#define HAVE_FCNTL_H 1
#define HAVE_GETOPT_H 1
#define HAVE_GETOPT_LONG 1
#define HAVE_HTONS 1
#define HAVE_LIMITS_H 1
#define HAVE_MALLOC_H 1
#define HAVE_MEMORY_H 1
#define HAVE_SIGNAL_H 1
#define HAVE_SNPRINTF 1
#define HAVE_STDINT_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_STRTOULL 1
#define HAVE_SYS_STAT_H 1
#define HAVE_SYS_TIME_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_UINTPTR_T 1
#define HAVE_WINSOCK2_H 1

#define SIZEOF_LONG 4
#define SIZEOF_LONG_LONG 8
#define SIZEOF_OFF_T 8
#define SIZEOF_SIZE_T sizeof(size_t)
#define SIZEOF_TIME_T sizeof(time_t)

#ifdef _MSC_VER
#define strtoull _strtoui64
#define NEED_LSEEK64 1
#define lseek64 _lseeki64
#endif

#endif
