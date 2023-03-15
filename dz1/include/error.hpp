// Copyright 2023 Kosmatoff
#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <fstream>

// проверка файлов
bool filesChecking(
    const std::string& fileNameTitle,
    const std::string& fileNameRatings,
    const std::string& fileNameBasics);

// происходит проверк аргументов и их объявления
bool argumentsChecking(
    int num, char *argument[],
    std::string& fileNameTitle,
    std::string& fileNameRatings,
    std::string& fileNameBasics,
    std::string& date);
