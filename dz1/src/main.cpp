// Copyright 2023 Kosmatoff
#include "Parser.hpp"
#include "error.hpp"

int main(int argc, char *argv[]) {
    std::string fileNameTitle = "";
    std::string fileNameRatings = "";
    std::string fileNameBasics = "";
    std::string date = "";
    std::string numberMoviesString = "";

    if (!checkArguments(
        argc, argv, fileNameTitle,
        fileNameRatings, fileNameBasics,
        date, numberMoviesString)
    ) {
        return 1;
    }

    if (!checkFiles(
        fileNameTitle, fileNameRatings, fileNameBasics)) {
        return false;
    }

    Parser moviesParser;

    moviesParser.parseRatingsFile(fileNameRatings);
    moviesParser.parseTitleFile(fileNameTitle);

    std::vector<Movie> movies;
    moviesParser.parseBasicsFile(fileNameBasics, date, movies);

    std::sort(movies.begin(), movies.end(), MovieComparator());

    coutTopMovies(movies, numberMoviesString);
}
