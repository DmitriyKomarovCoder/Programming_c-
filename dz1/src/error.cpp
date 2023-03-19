#include "error.hpp"

// является ли строка числом
bool isStringDigit(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

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
        std::cerr << "ERROR: file doesn't open"<< std::endl;
        return false;
    }

    return true;
}