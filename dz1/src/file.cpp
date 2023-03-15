// Copyright 2023 Kosmatoff
#include "file.hpp"

std::ifstream openFile(const std::string& fileName) {
    std::ifstream file(fileName);
    std::string line;
    std::getline(file, line);
    return file;
}