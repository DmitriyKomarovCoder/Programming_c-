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
    // читает файл с рейтингом и парсит значений в title_rating
    void parse_ratings_file(std::string file_name_ratings);

    // читает файл с русскими значениями и парсит значений в title_rus
    void parse_title_file(std::string file_name_title);

    // читает файл с основной информацией и парсит значений в movies
    void parse_basics_file(std::string file_name_basics, std::string date);

    // сортирует вектор по рейтингу
    void sort();

    // для получения movies, т.к. private

    friend std::ostream& operator<<(std::ostream& os, const Parser& parser);

    // вывод значения movie на экран
    const std::vector<Movie>& get_movies() const {
        return movies;
    }

 private:
    /* title_rating - ассоциативный массив, сопоставляющий
       названиям фильмов с их рейтингом. */
    std::unordered_map<std::string, float> title_rating;
    /* title_rus - ассоциативный массив, сопоставляющий
       названиям фильмов на английском языке их переводы
       на русский язык. */
    std::unordered_map<std::string,  std::string> title_rus;
    // массив структуры movies
    std::vector<Movie> movies;
};
