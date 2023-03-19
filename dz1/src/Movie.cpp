// Copyright 2023 Kosmatoff

#include "Movie.hpp"
#include "movie_const.hpp"
#include "error.hpp"

void coutTopMovies(std::vector<Movie> movies,
                   const std::string& numberMoviesString
) {
    int numberMovies = topMovies;
    if (!numberMoviesString.empty() && isStringDigit(numberMoviesString)) {
        numberMovies = std::stoi(numberMoviesString);
    }

    if (numberMovies > movies.size()) {
        numberMovies = movies.size();
    }

    for (int i = 0; i < numberMovies; i++) {
        std::cerr << movies[i].title << " : " << movies[i].rating << std::endl;
    }
}
