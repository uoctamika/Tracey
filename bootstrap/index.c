#include <stdio.h>
#include <tracey/argument/argument.h>
#include <tracey/compile/compile.h>

int main(int argc, char **argv)
{
    TraceyOptions opts = {0};

   if(!parse_args(argc, argv, &opts))
   {
      return 1;
   }

    debug_print_args(&opts);

    compile(&opts);

    return 0;
}
