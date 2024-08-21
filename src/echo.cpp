#include <iostream>

#include "echo.hpp"


void EchoOperation::handleEndOfInput() {
     
    if (next_) {
        next_->processLine(echo_str);
    } else {
        std::cout << echo_str << std::endl;
    }

    if (next_) {
        next_->handleEndOfInput();
    }
}

void EchoOperation::setNextOperation(std::unique_ptr<Ioperation>&& next) {
    next_ = std::move(next);
}
