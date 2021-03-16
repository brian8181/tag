#include <iostream>
#include <string>
#include <getopt.h>
#include "bash_color.h"

using namespace std;

static struct option long_options[] =
{
    {"verbose", no_argument, 0, 'v'},
    {"help", no_argument, 0, 'h'},
    {"file", no_argument, 0, 'f'}
};

/*

 tag [opts] [INPUT] ... ]

*/

void print_help();

const int DEFAULT_ARGC = 3;

int main(int argc, char *argv[])
{
    int opt = 0;
    int option_index = 0;
    bool file_flag = false;
    bool verbose_flag = false;
    
    optind = 0;
    while((opt = getopt_long(argc, argv, "hvf", long_options, &option_index)) != -1)
    {
        switch (opt)
        {
        case 'h':
            print_help();
            return 0;
        case 'v':
            verbose_flag = true;
            break;
        case 'f':
            file_flag = true;
            break;
        default: // unknown option before args
            fprintf(stderr, "Unexpected option, -h for help\n");
            return EXIT_FAILURE;
        }
    }

    if (optind != (argc - DEFAULT_ARGC)) // not correct number of args
    {
        fprintf(stderr, "Expected argument after options, -h for help\n");
        exit(EXIT_FAILURE);
    }
          
    if (verbose_flag)
    {
        print_help();
    }

    if (!file_flag)
    {
        
    }
}

void 
print_help()
{
    cout << "\n"
         << FMT_BOLD << "scanpf" << FMT_RESET << " "
         << "[OPTIONS] "
         << FMT_UNDERLINE << "INPUT_PATTERN" << FMT_RESET << " "
         << FMT_UNDERLINE << "OUTPUT_PATTERN" << FMT_RESET << " "
         << FMT_UNDERLINE << "[INPUT ...]" << FMT_RESET << "\n\n";
}
