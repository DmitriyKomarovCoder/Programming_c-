// Copyright 2023 Kosmatoff

#pragma once

#include <memory>
#include <sstream>
#include <string>

#include <vector>

#include "tail.hpp"
#include "cat.hpp"
#include "echo.hpp"

// убирает пробелы в конце и начале операции
std::string trim(const std::string& str);

// Вернет указатель на ковеер операций
std::vector<std::unique_ptr<Ioperation>> commandParser(int argc, char *argv[]);