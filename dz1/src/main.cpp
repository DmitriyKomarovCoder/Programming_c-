// Copyright 2023 Kosmatoff
#include "Parser.hpp"
#include "error.hpp"

int main(int argc, char *argv[]) {
    std::string file_name_title = "";
    std::string file_name_ratings = "";
    std::string file_name_basics = "";
    std::string date = "";

    if (!function_checking_arguments(
        argc, argv, file_name_title,
        file_name_ratings, file_name_basics,
        date)
    ) {
        return 1;
    }
    
    Parser movies_parser;
    
    movies_parser.parse_ratings_file(file_name_ratings);
    movies_parser.parse_title_file(file_name_title);
    movies_parser.parse_basics_file(file_name_basics, date);

    movies_parser.sort();
    
    std::cout << movies_parser << std::endl;
    return 0;
}
