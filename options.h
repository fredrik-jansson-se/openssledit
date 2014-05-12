#pragma once

#include <string>

struct Options {
    static Options parse(int argv, const char* argc[]);

    std::string configFile;
    std::string outputFile;
};
