// Copyright 2023 Kosmatoff

#pragma once

#include <memory>
#include "ioperation.hpp"
#include "conveyorParser.hpp"

class Conveyor {
 public:
    Conveyor() = default;
    Conveyor& operator=(std::unique_ptr<Ioperation>&& ptr);
    void run();
 private:
    std::unique_ptr<Ioperation> conveyorPtr_;
};