#include <iostream>

#include "echo.hpp"

void EchoOperation::processLine(const std::string& message) {
    buffer_.push_back(message);
}

void EchoOperation::handleEndOfInput() {
    
    processLine(echo_str);

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

void EchoOperation::setNextOperation(std::unique_ptr<Ioperation>&& next) {
    next_ = std::move(next);
}
