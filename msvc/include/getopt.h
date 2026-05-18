#ifndef UDPCAST_MSVC_GETOPT_H
#define UDPCAST_MSVC_GETOPT_H

#ifdef __cplusplus
extern "C" {
#endif

extern char *optarg;
extern int optind;
extern int opterr;
extern int optopt;

struct option {
    const char *name;
    int has_arg;
    int *flag;
    int val;
};

#ifndef no_argument
#define no_argument 0
#endif
#ifndef required_argument
#define required_argument 1
#endif
#ifndef optional_argument
#define optional_argument 2
#endif

int getopt(int argc, char *const argv[], const char *optstring);
int getopt_long(int argc,
                char *const argv[],
                const char *optstring,
                const struct option *longopts,
                int *longindex);

#ifdef __cplusplus
}
#endif

#endif
