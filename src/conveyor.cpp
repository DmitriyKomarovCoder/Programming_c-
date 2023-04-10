#include "conveyor.hpp"

Conveyor& Conveyor::operator=(std::unique_ptr<Ioperation>&& ptr) {
    conveyorPtr_ = std::move(ptr);
    return *this;
}

void Conveyor::run() {
    conveyorPtr_->handleEndOfInput();
}