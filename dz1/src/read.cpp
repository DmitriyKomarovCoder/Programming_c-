#include "../include/read.hpp"
#include "../include/parcer.hpp"


bool read_file(std::string& file_name, std::string& date, std::vector<Entity>& entity) {

    std::ifstream file(file_name);
    std::string line;

    if (!file.is_open()) {
        return false;
    }
    while (std::getline(file, line)) {
        if (!line.empty()) {
        parcer_line(line, date, entity);
    }
        //std::cout << line << std::endl;
    }
    file.close();
    return true;
}

void output_entity(std::vector<Entity>& entity) {
    std::sort(entity.begin(), entity.end(), Comparator_Entity());
    bool flag_rus = entity[0].rus;
    int i = 0;
    if (flag_rus == true) {
        while(entity[i].rus && i < entity.size()) {
            std::cout<<entity[i].title << std::endl;
            i ++;
        }
    } else 
    {
        while(i < entity.size()) {
            std::cout<<entity[i].title << std::endl;
            i ++;
        }
    }
}

