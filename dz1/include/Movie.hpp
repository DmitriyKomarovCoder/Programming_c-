#pragma once

#include <iostream>

#include <vector>
#include <algorithm>

struct Movie {
    std::string title;
    double rating;
};

struct Comparator_Movie {
    bool operator()(const Movie& a, const Movie& b) const {
        return a.rating > b.rating;
    }
};

void cout_movie(std::vector<Movie>& movies);