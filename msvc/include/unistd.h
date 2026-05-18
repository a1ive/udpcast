#ifndef UDPCAST_MSVC_UNISTD_H
#define UDPCAST_MSVC_UNISTD_H

#include <direct.h>
#include <io.h>
#include <process.h>
#include <stdlib.h>

#ifndef STDIN_FILENO
#define STDIN_FILENO 0
#endif
#ifndef STDOUT_FILENO
#define STDOUT_FILENO 1
#endif
#ifndef STDERR_FILENO
#define STDERR_FILENO 2
#endif

typedef unsigned int useconds_t;

#define access _access
#define close _close
#define dup _dup
#define dup2 _dup2
#define execvp _execvp
#define fileno _fileno
#define isatty _isatty
#define lseek _lseeki64
#define open _open
#define read _read
#define rmdir _rmdir
#define unlink _unlink
#define write _write

#endif
