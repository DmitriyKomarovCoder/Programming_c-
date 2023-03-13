// Copyright 2023 Kosmatoff
#include "Movie.hpp"

void cout_movie(std::vector<Movie>& movies) {
    std::sort(movies.begin(), movies.end(), Comparator_Movie());
    for (int i = 0; i < movies.size(); i++) {
        std::cout << movies[i].title << std::endl;
    }
}