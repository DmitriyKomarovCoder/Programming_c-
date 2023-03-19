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
// проверка строки на число
bool isStringDigit(const std::string& str);
