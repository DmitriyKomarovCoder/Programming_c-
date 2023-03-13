// Copyright 2023 Kosmatoff
#pragma once

#include <string>
#include <fstream>
#include <sstream>

#include <vector>
#include <unordered_map>
#include <algorithm>

#include "Movie.hpp"
#include "movie_const.hpp"

// читает файл с рейтингом и парсит значений в title_rating
bool read_ratings_file(
    const std::string& file_name_ratings,
    std::unordered_map<std::string, float>& title_rating);

// читает файл с русскими значениями и парсит значений в title_rus
bool read_title_file(
    const std::string& file_name_title,
    std::unordered_map<std::string, std::string>& title_rus);

// читает файл с основной информацией и парсит значений в movies
bool read_basics_file(
    const std::string& file_name_basics,
    const std::string& date,
    const std::unordered_map<std::string, float>& title_rating,
    const std::unordered_map<std::string, std::string>& title_rus,
    std::vector<Movie>& movies);
