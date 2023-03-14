// Copyright 2023 Kosmatoff
#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <fstream>

// проверка файлов
bool function_checking_files(
    const std::string& file_name_title,
    const std::string& file_name_ratings,
    const std::string& file_name_basics);

// происходит проверк аргументов и их объявления
bool function_checking_arguments(
    int num, char *argument[],
    std::string& file_name_title,
    std::string& file_name_ratings,
    std::string& file_name_basics,
    std::string& date);
