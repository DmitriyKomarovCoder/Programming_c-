// Copyright 2023 Kosmatoff

#pragma once
#include <stdexcept>

struct Error : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

struct FileError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

struct ArgsError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

struct ParserUnknow : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

struct EchoError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};