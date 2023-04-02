// Copyright 2023 Kosmatoff
#pragma once

#include <string>
#include <memory>

#include <deque>
#include <vector>

#include "ioperation.hpp"

class TailOperation : public Ioperation { 
 public:
    explicit TailOperation(const size_t n) : n_(n) {}
    void processLine(const std::string& message) override;
    void handleEndOfInput() override;
    void setNextOperation(std::unique_ptr<Ioperation>&& next) override; // возможен следует передавать lvalue

 private:
    size_t n_;
    std::deque<std::string> buffer_;
    std::unique_ptr<Ioperation> next_;
};
