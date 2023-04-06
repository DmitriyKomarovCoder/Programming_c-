#include <iostream>

#include "ioperation.hpp"
#include "conveyorParser.hpp"
#include "Error.hpp"

int main(int argc, char *argv[]) {
   ConveyorParser conveyorOperation;
   try {
      if (argc != 2) {
        throw ArgsError{"Failed argument's empty"};
      }

      std::string stringCommand(argv[1]);
 
      conveyorOperation.commandParser(stringCommand);
      std::unique_ptr<Ioperation> conveyorPtr = conveyorOperation.getPtr();
      
      // раскрутка конвейера
      conveyorPtr->handleEndOfInput();
   } catch (Error& e) {
      std::cerr << e.what() << std::endl;
      return 1;
   }

   return 0;
}