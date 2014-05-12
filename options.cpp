#include <iostream>
#include <boost/program_options.hpp>
#include <boost/log/trivial.hpp>

#include "options.h"

namespace po = boost::program_options;

Options Options::parse(int argc, const char* argv[]) {
    Options opts;

    po::options_description desc("Allowed options");

    desc.add_options()
        ("help,h", "show help")
        ("in,i", po::value<std::string>(&opts.configFile)->default_value("openssl.cnf"), "Configuration file")
        ("out,o", po::value<std::string>(&opts.outputFile), "Output, if not set the result is written back to the configuration file")
        ;

    try {
        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.count("help")) {
            std::cout << desc << "\n";
            exit(1);
        }

        if (opts.outputFile.empty()) {
            opts.outputFile = opts.configFile;
        }
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n" << desc;
        exit(1);
    }

    return opts;
}

