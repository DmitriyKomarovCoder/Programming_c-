// Copyright 2023 Kosmatoff

#pragma once

#include <memory>
#include "ioperation.hpp"

class ConveyorOperation {
 public:
    void setConveyorPtr(std::unique_ptr<Ioperation>&& conveyorPtr);
    void runPipeline();
 private:
    std::unique_ptr<Ioperation> conveyorPtr_;
};