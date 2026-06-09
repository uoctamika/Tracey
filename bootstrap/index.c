#include <stdio.h>
#include <tracey/argument/args.h>

int main(int argc, char **argv) {
    TraceyOptions opts = {0};
    if (!parse_args(argc, argv, &opts)) {
        fprintf(stderr, "Invalid arguments\n");
        return 1;
    }
    compile(&opts);
    return 0;
}
