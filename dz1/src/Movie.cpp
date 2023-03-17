// Copyright 2023 Kosmatoff

#include "Movie.hpp"
#include "movie_const.hpp"

void coutTopMovies(std::vector<Movie> movies,
                   const std::string& numberMoviesString
) {
    int numberMovies = topMovies;
    if (!numberMoviesString.empty()) {
//!!!!!!!!!!!!! добавить проверку на число !!!!!!!!!!!!!!!!!!
        numberMovies = std::stoi(numberMoviesString);
    }
    for (int i = 0; i < numberMovies; i++) {
        std::cout << movies[i].title << " :" << movies[i].rating << std::endl;
    }
}
