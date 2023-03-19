// Copyright 2023 Kosmatoff
#include "Parser.hpp"
#include "error.hpp"
#include "console_parser.hpp"

int main(int argc, char *argv[]) {
    CommandLineArgs args = parseCommandLineArgs(argc, argv);

    if (!checkFiles(
        args.fileNameTitle, args.fileNameRatings, args.fileNameBasics)) {
        return false;
    }

    Parser moviesParser;

    moviesParser.parseRatingsFile(args.fileNameRatings);
    moviesParser.parseTitleFile(args.fileNameTitle);

    std::vector<Movie> movies;
    moviesParser.parseBasicsFile(args.fileNameBasics, args.date, movies);

    std::sort(movies.begin(), movies.end(), MovieComparator());

    coutTopMovies(movies, args.numberMoviesString);
}
