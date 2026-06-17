#include <stdio.h>
#include <string.h>
#include <tracey/argument/argument.h>

static int has_trc_extension(const char *filename)
{
    const char *ext = strrchr(filename, '.');

    if (!ext) {
        return 0;
    }

    return strcmp(ext, ".trc") == 0;
}

int parse_args(int argc, char **argv, TraceyOptions *opts)
{
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-Wall") == 0) {
            opts->warning_all = 1;
        }
        else if (strcmp(argv[i], "-Wextra") == 0) {
            opts->warning_extra = 1;
        }
        else if (strcmp(argv[i], "-o") == 0) {
            if (++i >= argc) {
                return 0;
            }

            opts->output_file = argv[i];
        }
        else {
            opts->input_file = argv[i];
        }
    }

    if (!opts->input_file) {
        fprintf(stderr, "no input file specified\ncompilation terminated.\n");
        return 0;
    }

    if (!has_trc_extension(opts->input_file)) {
        fprintf(stderr, "input file '%s' is not valid\ncompilation terminated.\n",
                       opts->input_file);
        return 0;
    }

    return 1;
}
