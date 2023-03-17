// Copyright 2023 Kosmatoff
#include "error.hpp"

bool checkFiles(
    const std::string& fileNameTitle,
    const std::string& fileNameRatings,
    const std::string& fileNameBasics
) {

    std::ifstream fileRatings(fileNameRatings);
    std::ifstream fileBasics(fileNameBasics);
    std::ifstream fileTitle(fileNameTitle);

    if (!fileRatings.is_open() ||
        !fileTitle.is_open() ||
        !fileBasics.is_open()) {
        std::cout << "ERROR: file doesn't open"<< std::endl;
        return false;
    }

    return true;
}

bool checkArguments(
    int num, char *argument[], std::string& fileNameTitle,
    std::string& fileNameRatings, std::string& fileNameBasics,
    std::string& date, std::string& numberMoviesString
) {
    if (num < 5) {  // проверка на пустоту (аргументы не ввели)
        std::cout << "ERROR: Command line arguments are not specified"<< std::endl;
        return false;
    }

    std::vector<std::string> arguments = {argument[1], argument[2],
    argument[3], argument[4]};

    for (int i = 0; i < arguments.size(); i++) {
        if (arguments[i].empty()) {
            std::cout << "ERROR: Argument " << i << " is empty" << std::endl;
            return false;
        }
    }
    
    if (num == 6) {
        numberMoviesString.append(argument[5]);
    }
    fileNameTitle.append(argument[1]);
    fileNameRatings.append(argument[2]);
    fileNameBasics.append(argument[3]);
    date.append(argument[4]);

    return true;
}