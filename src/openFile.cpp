#include "openFile.hpp"
#include "Error.hpp"

std::ifstream openFile(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        file.close();
        throw FileError{"Failed to open file"};
    }
    return file;
}