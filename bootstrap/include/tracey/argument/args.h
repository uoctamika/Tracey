#ifndef TRACEY_H
#define TRACEY_H

typedef struct TraceyOptions
{
    const char *input_file;
    int warning_all;
    int warning_extra;
    const char *output_file;
} TraceyOptions;

int parse_args(int argc, char **argv, TraceyOptions *opts);
void compile(const TraceyOptions *opts);

#endif
