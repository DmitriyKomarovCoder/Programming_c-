#include <iostream>

#include "ioperation.hpp"
#include "conveyorParser.hpp"
#include "Error.hpp"
#include "conveyorOperation.hpp"

int main(int argc, char *argv[]) {
    ConveyorParser operationParser;
    try {
        if (argc != 2) {
            throw ArgsError{"Failed argument's empty"};
        }

        std::string args(argv[1]);
 
        operationParser.commandParser(args);
        ConveyorOperation conveyor;
        conveyor.setConveyorPtr(std::move(operationParser.getPtr()));
        
        // раскрутка конвейера
        conveyor.runPipeline();
    } catch (Error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

   return 0;
}