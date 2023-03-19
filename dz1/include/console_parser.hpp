// Copyright 2023 Kosmatoff
#pragma once

#include <string>
#include <iostream>
#include <string>
#include <getopt.h>

struct CommandLineArgs {
    std::string fileNameTitle;
    std::string fileNameRatings;
    std::string fileNameBasics;
    std::string date;
    std::string numberMoviesString;
};

CommandLineArgs parseCommandLineArgs(int argc, char *argv[]);
