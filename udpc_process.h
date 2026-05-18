#ifndef UDPC_PROCESS_H
#define UDPC_PROCESS_H

#ifdef __MINGW32__

#include <process.h>
#include <fcntl.h>
#include <stdint.h>

typedef intptr_t udpc_pid_t;

#define pipe(a) _pipe((a), 0, _O_BINARY | _O_NOINHERIT)
#define waitpid(a,b,c) _cwait(b,a,c)

#else /* __MINGW32__ */
#include <sys/wait.h>
typedef int udpc_pid_t;

#endif /* __MINGW32__ */

udpc_pid_t open2(int in, int out, char **arg, int closeFd);

#endif
