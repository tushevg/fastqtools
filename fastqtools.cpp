#include <iostream>
#include "version.h"

int main_stats(const int argc, const char *argv[]);

int print_usage();
int print_version();
int print_contact();

int main(const int argc, const char *argv[]) {
    
    if (argc < 2)
        return print_usage();
    
    const std::string subcommand = std::string(argv[1]);

    if (subcommand == "-h" || subcommand == "--help") return print_usage();

    else if (subcommand == "-v" || subcommand == "--version") return print_version();

    else if (subcommand == "-c" || subcommand == "--contact") return print_contact();

    else if (subcommand == "stats") return main_stats(argc - 1, argv + 1);

    else {
        std::cerr << "ribotools::error, unknown subcommand " << subcommand << std::endl;
        return print_usage();
    }

    return 0;
}


int print_usage() {
    std::cerr << "fastqtools" << std::endl;
    std::cerr << "a toolset to profile FASTQ/FASTA files" << std::endl;
    print_version();
    std::cerr << std::endl;
    std::cerr << "usage: fastqtools <subcommand> [-h|--help -v|--version -c|--contact]" << std::endl;
    std::cerr << std::endl;
    std::cerr << "[subcommands]" << std::endl;
    std::cerr << "    stats    count records and report sequence length" << std::endl;
    std::cerr << std::endl;
    std::cerr << "[options]" << std::endl;
    std::cerr << "    -h, --help     print this help message" << std::endl;
    std::cerr << "    -v, --version  what major.minor.build version of ribotools is used" << std::endl;
    std::cerr << "    -c, --contact  feature requests, bugs, mailing lists, etc." << std::endl;
    std::cerr << std::endl;
    return 0;
}


int print_version() {
    std::cerr << "version ";
    std::cerr << version_major;
    std::cerr <<  ".";
    std::cerr << version_minor;
    std::cerr <<  ".";
    std::cerr << version_build;
    std::cerr << std::endl;
    return 0;
}


int print_contact() {
    std::cerr << "Scientific Computing and Data Visualisation Facility" << std::endl;
    std::cerr << "Max Planck Institute for Brain Research" << std::endl;
    std::cerr << "Frankfurt am Main, Germany" << std::endl;
    std::cerr << "repository: https://github.com/tushevg/fastqtools" << std::endl;
    std::cerr << "bug reports: sciclist@brain.mpg.de" << std::endl;
    std::cerr << "author: georgi a. tushev" << std::endl;
    return 0;
}