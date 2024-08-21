// Copyright 2023 Kosmatoff

#pragma once

#include <memory>
#include "ioperation.hpp"

class Conveyor {
 public:
    Conveyor() = default;

    Conveyor(Conveyor&& other);
    
    Conveyor& operator=(Conveyor&& other);

    void setConveyorPtr(std::unique_ptr<Ioperation>&& ptr);

    void run();
 private:
    std::unique_ptr<Ioperation> conveyorPtr_;
};