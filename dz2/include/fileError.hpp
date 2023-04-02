// Copyright 2023 Kosmatoff

#pragma once
#include <stdexcept>

struct FileError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};