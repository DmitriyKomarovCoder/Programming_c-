// Copyright 2023 Kosmatoff
#pragma once

#include <string>
#include <fstream>
#include <sstream>

#include <vector>
#include <unordered_map>

#include "Movie.hpp"

class Parser {
 public:
    // читает файл с рейтингом и парсит значений в titleRating
    void parseRatingsFile(const std::string& fileNameRatings);

    // читает файл с русскими значениями и парсит значений в titleRus
    void parseTitleFile(const std::string& fileNameTitle);

    // читает файл с основной информацией и парсит значений в movies
    void parseBasicsFile(
      const std::string& fileNameBasics,
      const std::string& date, 
      std::vector<Movie>& movies);

 private:
    /* titleRating - ассоциативный массив, сопоставляющий
       названиям фильмов с их рейтингом. */
    std::unordered_map<std::string, float> titleRating;
    /* titleRus - ассоциативный массив, сопоставляющий
       названиям фильмов на английском языке их переводы
       на русский язык. */
    std::unordered_map<std::string,  std::string> titleRus;
};
