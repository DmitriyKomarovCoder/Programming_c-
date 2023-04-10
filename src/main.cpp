#include <iostream>

#include "ioperation.hpp"
#include "conveyorParser.hpp"
#include "Error.hpp"
#include "conveyor.hpp"

int main(int argc, char *argv[]) {
    try {
        if (argc != 2) {
            throw ArgsError{"Failed argument's empty"};
        }
 
        ConveyorParser opParser(argv[1]);
        Conveyor conv;
        conv = opParser.parse();
        // раскрутка конвейера
        conv.run();
        
        // раскрутка конвейера
    } catch (Error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

   return 0;
}