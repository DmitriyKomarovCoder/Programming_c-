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

// перегрузка оператора вывода для Movie
std::ostream& operator<<(std::ostream& os, const std::vector<Movie>& movies);

// сортировка значения по рейтингу
struct MovieComparator {
    bool operator()(const Movie& a, const Movie& b) const {
        return a.rating > b.rating;
    }
};

