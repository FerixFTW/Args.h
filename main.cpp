//////////////////////////
// ARGUMENT DEFINITIONS //
//////////////////////////

#define ARGS_INIT
#define ARGS_LIST \
    REQUIRED_ARG(file, std::string, "Input file to be processed") \
    OPTIONAL_ARG(process, int, "Process type to use {1, 2, 3}", 1) \
    LIST_ARG(opts, float, "Optional coeffs", false)

#define ARGS_PROGRAM_DESCRIPTION "This is a test program"

#include "args.h"
#include <algorithm>
   
int main (int argc, char *argv[]) {
    args_t args;

    if(!parse_args(argc, argv, &args))
    {
        return 1;
    }else{ // args parsed we good to go
        std::cout << "file: " << args.file << std::endl;
        std::cout << "process: " << args.process << std::endl;
        std::cout << "opts: ";
        std::for_each(args.opts.begin(), args.opts.end(), [](float c) {
                std::cout << c << ", ";
                });

        std::cout << std::endl;
    }

    return 0;
}
