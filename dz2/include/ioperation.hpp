// Copyright 2023 Kosmatoff

#pragma once

#include <iostream>
#include <string>

class Ioperation {
 public:
    virtual ~Ioperation() {}
    virtual void processLine(const std::string& str);
    virtual void handleEndOfInput() = 0;
    virtual void setNextOperation(std::unique_ptr<Ioperation>&& next) = 0;
};
