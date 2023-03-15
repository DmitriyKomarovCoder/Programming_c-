// Copyright 2023 Kosmatoff
#include "Parser.hpp"
#include "error.hpp"

int main(int argc, char *argv[]) {
    std::string fileNameTitle = "";
    std::string fileNameRatings = "";
    std::string fileNameBasics = "";
    std::string date = "";

    if (!argumentsChecking(
        argc, argv, fileNameTitle,
        fileNameRatings, fileNameBasics,
        date)
    ) {
        return 1;
    }
    
    Parser moviesParser;
    
    moviesParser.ParseRatingsFile(fileNameRatings);
    moviesParser.ParseTitleFile(fileNameTitle);

    std::vector<Movie> movies;
    moviesParser.ParseBasicsFile(fileNameBasics, date, movies);

    std::sort(movies.begin(), movies.end(), MovieComparator());


    std::cout << movies << std::endl;
    return 0;
}
