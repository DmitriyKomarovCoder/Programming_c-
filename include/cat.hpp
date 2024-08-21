// Copyright 2023 Kosmatoff
#pragma once

#include <string>
#include <memory>

#include <vector>
#include "ioperation.hpp"
#include "openFile.hpp"

class CatOperation : public Ioperation { 
 public:
    explicit CatOperation(const std::string& fileName)
        : fileName_(fileName) {}
    
    void processLine(const std::string& fileName) override;
    void handleEndOfInput() override;
    void setNextOperation(std::unique_ptr<Ioperation>&& next) override; // возможен следует передавать lvalue
    
    friend std::ifstream openFile(const std::string& file_Name);
 private:
    std::string fileName_;
    std::vector<std::string> buffer_;
    std::unique_ptr<Ioperation> next_;
};
