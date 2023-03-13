// Copyright 2023 Kosmatoff
#pragma once

#include <iostream>
#include <string>
#include <vector>

// происходит проверк аргументов и их объявления
bool checking_arguments(
    int num, char *argument[],
    std::string& file_name_title,
    std::string& file_name_ratings,
    std::string& file_name_basics,
    std::string& date);
