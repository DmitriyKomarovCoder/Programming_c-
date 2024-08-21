// Copyright 2023 Kosmatoff

#pragma once
#include <stdexcept>

struct Error : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

struct FileError : public Error {
    using Error::Error;
};

struct ArgsError : public Error {
    using Error::Error;
};

struct ParserUnknow : public Error {
    using Error::Error;
};

struct EchoError : public Error {
    using Error::Error;
};