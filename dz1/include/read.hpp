#pragma once
#include <iostream>
#include <string>
#include <fstream>

bool read_file(std::string& file);

struct Entity
{
    std::string title_movie;
    bool rus;
};