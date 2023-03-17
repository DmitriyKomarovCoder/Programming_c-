// Copyright 2023 Kosmatoff
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <fstream>

// проверка файлов
bool checkFiles(
    const std::string& fileNameTitle,
    const std::string& fileNameRatings,
    const std::string& fileNameBasics);

// происходит проверк аргументов и их объявления
bool checkArguments(
    int num, char *argument[],
    std::string& fileNameTitle,
    std::string& fileNameRatings,
    std::string& fileNameBasics,
    std::string& date,
    std::string& numberMoviesString);

bool isStringDigit(const std::string& number);