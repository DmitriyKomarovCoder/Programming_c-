// Copyright 2023 Kosmatoff
#pragma once

#include <string>
#include <memory>
#include <vector> 

#include "ioperation.hpp"

class EchoOperation : public Ioperation {
 public:
    explicit EchoOperation(const std::string& message)  : echo_str(message) {}
    void processLine(const std::string& message) override;
    void handleEndOfInput() override;
    void setNextOperation(std::unique_ptr<Ioperation>&& next) override;
    
 private:
    std::string echo_str;
    std::vector<std::string> buffer_;
    std::unique_ptr<Ioperation> next_;
};

