#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "read.hpp"
#include <locale>

void parcer_line(std::string& line, std::string& date, std::vector<Entity>& entity);

bool is_rus(const std::string& str); 