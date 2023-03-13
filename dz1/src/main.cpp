// Copyright 2023 Kosmatoff
#include "parcer.hpp"
#include "error.hpp"

int main(int argc, char *argv[]) {
    std::string file_name_title = "";
    std::string file_name_ratings = "";
    std::string file_name_basics = "";
    std::string date = "";

    if (!checking_arguments(
        argc, argv, file_name_title,
        file_name_ratings, file_name_basics,
        date)
    ) {
        return 1;
    }
    
    std::unordered_map<std::string, float> title_rating;
    if (!read_ratings_file(file_name_ratings, title_rating)) {
        std::cout << "ERROR: file ratings doesn't open\n";
        return 1;
    }

    std::unordered_map<std::string,  std::string> title_rus;
    if (!read_title_file(file_name_title, title_rus)) {
        std::cout << "ERROR: file name_file doesn't open\n";
        return 1;
    }

    std::vector<Movie> movies;
    if (!read_basics_file(file_name_basics,
                          date, title_rating, title_rus, movies)) {
        std::cout << "ERROR: file basics_file doesn't open\n";
        return 1;
    }

    cout_movie(movies);

    return 0;
}
