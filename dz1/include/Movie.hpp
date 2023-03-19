// Copyright 2023 Kosmatoff
#pragma once

#include <iostream>

#include <string>

#include <vector>
#include <algorithm>

// хранит заголовки фильмов и их рейтинг
struct Movie {
    std::string title;
    double rating;
};

// выводит топ фильмы из вектора
void coutTopMovies(std::vector<Movie> movies, const std::string& numberMovies);

// сортировка значения по рейтингу
struct MovieComparator {
    bool operator()(const Movie& a, const Movie& b) const {
        return a.rating > b.rating;
    }
};
