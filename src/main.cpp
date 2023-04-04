#include <iostream>

#include "commandParser.hpp"
#include "Error.hpp"

int main(int argc, char *argv[]) {
   std::vector<std::unique_ptr<Ioperation>> conveyorOperation;
   try {
      conveyorOperation = commandParser(argc, argv);
      // раскрутка конвейера
      conveyorOperation[0]->handleEndOfInput();
   } catch (Error& e) {
      std::cerr << e.what() << std::endl;
      return 1;
   }

   return 0;
}