#include "../include/read.hpp"
#include "../include/error.hpp"

int main(int argc, char *argv[]) 
{
    std::string file_name;
    std::string year;
    
    if(!checking_arguments(argc, argv, file_name, year)) {
        return 1;
    }
    
    if (!read_file(file_name)) 
    {
        std::cout<<"ERROR: doesn't open\n";
        return 1;
    }
    return 0;
}