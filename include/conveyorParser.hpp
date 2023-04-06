// Copyright 2023 Kosmatoff
#pragma once

#include <string>
#include <memory>
#include <vector>

#include "ioperation.hpp"

class ConveyorParser {
 public:
    // создает связанную цепочку из операций
    void commandParser(const std::string& stringCommand);
    std::unique_ptr<Ioperation> getPtr() {
        return std::move(firstPtr);
    }
 private:
    // хранит указатель на первую операцию
    std::unique_ptr<Ioperation> firstPtr;
};