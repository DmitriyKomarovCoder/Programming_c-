#include "conveyor.hpp"

Conveyor::Conveyor(Conveyor&& other) {
    if (other.conveyorPtr_) {
        conveyorPtr_ = std::move(other.conveyorPtr_);
    }
}

Conveyor& Conveyor::operator=(Conveyor&& other) {
    conveyorPtr_ = std::move(other.conveyorPtr_);
    return *this;
}

void Conveyor::setConveyorPtr(std::unique_ptr<Ioperation>&& ptr) {
    conveyorPtr_ = std::move(ptr);
}

void Conveyor::run() {
    conveyorPtr_->handleEndOfInput();
}