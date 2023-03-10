#include "../include/read.hpp"
#include "../include/error.hpp"

int main(int argc, char *argv[]) {
    std::string file_name = "";
    std::string date = "";

    if(!checking_arguments(argc, argv, file_name, date)) {
        return 1;
    }
    
    std::vector<Entity> entity;
    if (!read_file(file_name, date, entity)) { // чтение из файла и парсинг значений
        std::cout<<"ERROR:file doesn't open\n";
        return 1;
    }
    output_entity(entity); // вывод значений на экран

    return 0;
}