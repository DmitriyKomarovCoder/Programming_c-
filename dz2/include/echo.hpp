// Copyright 2023 Kosmatoff
#pragma once

#include <string>
#include <memory>

#include <vector> 
#include "ioperation.hpp"

class EchoOperation : public Ioperation {
 public:
    explicit EchoOperation(const std::string& message);
    void processLine(const std::string& message) override;
    void handleEndOfInput() override;
    void setNextOperation(std::unique_ptr<Ioperation>&& next) override; // возможен следует передавать lvalue
    
    friend std::ofstream openFile(const std::string& file_Name);
 private:
    std::vector<std::string> buffer_;
    std::unique_ptr<Ioperation> next_;
};

