#include "../include/read.hpp"

static const std::string movie = "movie";
static const std::string movie_tv = "tvMovie";

bool read_file(std::string& file_name)
{
    std::ifstream file(file_name);
    std::string line;

    if (!file.is_open()) 
    {
        return false;
    }
    while (std::getline(file, line)) 
    {
        std::cout << line << std::endl;
    }
    file.close();
    return true;
}
