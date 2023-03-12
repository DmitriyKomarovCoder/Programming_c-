#include "../include/parcer.hpp"
#include "../include/error.hpp"

int main(int argc, char *argv[]) {

    std::string file_name_title = "";
    std::string file_name_ratings = "";
    std::string file_name_basics = "";
    std::string date = "";

    if(!checking_arguments(argc, argv, file_name_title, file_name_ratings, file_name_basics, date)) { // происходит проверка аргументов и их объявления
        return 1;
    }
    
    std::unordered_map<std::string, float> title_rating;
    if (!read_ratings_file(file_name_ratings, title_rating)) { // читает файл с рейтингом и парсит значений в title_rating 
        std::cout<<"ERROR: file ratings doesn't open\n";
        return 1;
    }

    std::unordered_map<std::string,  std::string> title_rus;
    if (!read_title_file(file_name_title, title_rus)) { // читает файл с русскими значениями и парсит значений в title_rus
        std::cout<<"ERROR: file name_file doesn't open\n";
        return 1;
    }

    std::vector<Movie> movies;
    if (!read_basics_file(file_name_basics, date, title_rating, title_rus, movies)) { // читает файл с основной информацией и парсит значений в movies
        std::cout<<"ERROR: file basics_file doesn't open\n";  
        return 1;
    }

    cout_movie(movies); // вывод значений на экран

    return 0;
}