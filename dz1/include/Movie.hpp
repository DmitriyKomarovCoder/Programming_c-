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

// сортировка значения по рейтингу
struct Comparator_Movie {
    bool operator()(const Movie& a, const Movie& b) const {
        return a.rating > b.rating;
    }
};