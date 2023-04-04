#include "tail.hpp"

void TailOperation::processLine(const std::string& str) {
    buffer_.push_back(str);
    if (buffer_.size() > n_) {
        buffer_.pop_front();
    }
}

void TailOperation::handleEndOfInput() {

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

void TailOperation::setNextOperation(std::unique_ptr<Ioperation>&& next) {
    next_ = std::move(next);
}
