// Copyright 2023 Kosmatoff
#include "error.hpp"

bool function_checking_files(
    const std::string& file_name_title,
    const std::string& file_name_ratings,
    const std::string& file_name_basics
) {

    std::ifstream file_ratings(file_name_ratings);
    std::ifstream file_basics(file_name_basics);
    std::ifstream file_title(file_name_title);

    if (!file_ratings.is_open() ||
        !file_title.is_open() ||
        !file_basics.is_open()) {
        std::cout << "ERROR: file doesn't open"<< std::endl;
        return false;
    }
    
    return true;
}

bool function_checking_arguments(
    int num, char *argument[], std::string& file_name_title,
    std::string& file_name_ratings, std::string& file_name_basics,
    std::string& date
) {
    if (num < 5) {  // проверка на пустоту (аргументы не ввели)
        std::cout << "ERROR: Command line arguments are not specified"<< std::endl;
        return false;
    }

    std::vector<std::string> check_arguments = {argument[1], argument[2],
    argument[3], argument[4]};
    
    for (int i = 0; i < check_arguments.size(); i++) {
        if (check_arguments[i].empty()) {
            std::cout << "ERROR: Argument " << i << " is empty" << std::endl;
            return false;
        }
    }
    
    file_name_title.append(argument[1]);
    file_name_ratings.append(argument[2]);
    file_name_basics.append(argument[3]);
    date.append(argument[4]);
   
    if (!function_checking_files(
        file_name_title, file_name_ratings, file_name_basics)) {
        return false;
    }
    
    return true;
}