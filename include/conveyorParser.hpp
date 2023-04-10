// Copyright 2023 Kosmatoff
#pragma once

#include "ioperation.hpp"
#include "conveyor.hpp"

class ConveyorParser {
 public:
    explicit ConveyorParser(char *argv);

    // создает связанную цепочку из операций
    Conveyor parse();

 private:
    std::string stringCommand;
};