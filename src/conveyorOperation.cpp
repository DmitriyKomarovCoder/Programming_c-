#include "conveyorOperation.hpp"

void ConveyorOperation::setConveyorPtr(std::unique_ptr<Ioperation>&& conveyorPtr) {
    conveyorPtr_ = std::move(conveyorPtr);
}

void ConveyorOperation::runPipeline() {
    conveyorPtr_->handleEndOfInput();
}