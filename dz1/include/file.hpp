// Copyright 2023 Kosmatoff
#pragma once

#include <string>
#include <fstream>

//  пропускает 1 строку и возвращает поток
std::ifstream openFile(const std::string& fileName);