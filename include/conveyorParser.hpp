// Copyright 2023 Kosmatoff
#pragma once

#include <string>
#include <memory>
#include <vector>

#include "ioperation.hpp"

class ConveyorParser {
 public:
    explicit ConveyorParser(char *argv);

    // создает связанную цепочку из операций
    std::unique_ptr<Ioperation> parse();

 private:
    std::string stringCommand;
};