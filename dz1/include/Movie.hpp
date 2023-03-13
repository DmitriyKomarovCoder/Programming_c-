// Copyright 2023 Kosmatoff
#pragma once

#include <iostream>

#include <string>

#include <vector>
#include <algorithm>

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

// вывод значений на экран
void cout_movie(std::vector<Movie>& movies);
