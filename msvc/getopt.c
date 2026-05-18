#include "config.h"
#include <stdio.h>
#include <string.h>
#include "getopt.h"

char *optarg = NULL;
int optind = 1;
int opterr = 1;
int optopt = 0;

static const char *short_next = NULL;

static int needs_argument(const char *optstring, int option)
{
    const char *entry = strchr(optstring, option);
    return entry != NULL && entry[1] == ':';
}

int getopt(int argc, char *const argv[], const char *optstring)
{
    int option;

    optarg = NULL;

    if (short_next == NULL || *short_next == '\0') {
        if (optind >= argc) {
            return EOF;
        }
        if (argv[optind][0] != '-' || argv[optind][1] == '\0') {
            return EOF;
        }
        if (strcmp(argv[optind], "--") == 0) {
            optind++;
            return EOF;
        }
        short_next = argv[optind] + 1;
    }

    option = (unsigned char)*short_next++;
    optopt = option;

    if (strchr(optstring, option) == NULL || option == ':') {
        if (*short_next == '\0') {
            optind++;
            short_next = NULL;
        }
        if (opterr) {
            fprintf(stderr, "unknown option -- %c\n", option);
        }
        return '?';
    }

    if (needs_argument(optstring, option)) {
        if (*short_next != '\0') {
            optarg = (char *)short_next;
            optind++;
            short_next = NULL;
        } else if (optind + 1 < argc) {
            optarg = argv[++optind];
            optind++;
            short_next = NULL;
        } else {
            if (opterr) {
                fprintf(stderr, "option requires an argument -- %c\n", option);
            }
            optind++;
            short_next = NULL;
            return '?';
        }
    } else if (*short_next == '\0') {
        optind++;
        short_next = NULL;
    }

    return option;
}

int getopt_long(int argc,
                char *const argv[],
                const char *optstring,
                const struct option *longopts,
                int *longindex)
{
    const char *name;
    const char *value;
    size_t name_len;
    int i;

    optarg = NULL;

    if (optind >= argc) {
        return EOF;
    }

    if (strncmp(argv[optind], "--", 2) != 0 || argv[optind][2] == '\0') {
        return getopt(argc, argv, optstring);
    }

    if (strcmp(argv[optind], "--") == 0) {
        optind++;
        return EOF;
    }

    name = argv[optind] + 2;
    value = strchr(name, '=');
    name_len = value ? (size_t)(value - name) : strlen(name);

    for (i = 0; longopts[i].name != NULL; i++) {
        if (strlen(longopts[i].name) == name_len &&
            strncmp(longopts[i].name, name, name_len) == 0) {
            int result;

            if (longindex != NULL) {
                *longindex = i;
            }

            if (longopts[i].has_arg == required_argument) {
                if (value != NULL) {
                    optarg = (char *)(value + 1);
                } else if (optind + 1 < argc) {
                    optarg = argv[++optind];
                } else {
                    optopt = longopts[i].val;
                    if (opterr) {
                        fprintf(stderr, "option requires an argument -- %s\n",
                                longopts[i].name);
                    }
                    optind++;
                    return '?';
                }
            } else if (value != NULL && longopts[i].has_arg == no_argument) {
                optopt = longopts[i].val;
                if (opterr) {
                    fprintf(stderr, "option does not allow an argument -- %s\n",
                            longopts[i].name);
                }
                optind++;
                return '?';
            } else if (value != NULL) {
                optarg = (char *)(value + 1);
            }

            optind++;
            result = longopts[i].val;
            if (longopts[i].flag != NULL) {
                *longopts[i].flag = result;
                return 0;
            }
            return result;
        }
    }

    if (opterr) {
        fprintf(stderr, "unknown option -- %s\n", name);
    }
    optind++;
    return '?';
}
