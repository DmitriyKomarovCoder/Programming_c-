#include <iostream>

#include "cat.hpp"

void CatOperation::processLine(const std::string& str) {
    buffer_.push_back(str);
}

void CatOperation::handleEndOfInput() {
    std::ifstream fileCat = std::move(openFile(fileName_));
    std::string line;

    while (std::getline(fileCat, line)) {
        processLine(line);
    }

    for (const auto& line : buffer_) {
        if (next_) {
            next_->processLine(line);
        } else {
            std::cout << line << std::endl;
        }
    }
    if (next_) {
        next_->handleEndOfInput();
    }
}

void CatOperation::setNextOperation(std::unique_ptr<Ioperation>&& next) {
    next_ = std::move(next);
}

