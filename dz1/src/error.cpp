#include "../include/error.hpp"

bool checking_arguments(int num, char* argument[], std::string& file_name, std::string& year) {
    if (num < 3) { // проверка на пустоту (аргументы не ввели)
        std::cout << "ERROR: Command line arguments are not specified"<< std::endl;
        return false;
    }
    file_name.append(argument[1]);
    year.append(argument[2]);
    if (file_name.empty()) { // проверка на пустоту первого аргумента
        std::cout << "ERROR: Argument 1 is empty" << std::endl;
        return false;
    }

    if (year.empty()) { // проверка на пустоту второго аргумента
        std::cout << "ERROR: Argument 2 is empty" << std::endl;
        return false;
    }

    try { // проверка агрумента, который отвечает за дату
        int value = std::stoi(year);
    } catch (std::invalid_argument& e) {
        std::cout << "ERROR: Argumet 2 is not year" << std::endl;
        return false;
    }
    return true;
}