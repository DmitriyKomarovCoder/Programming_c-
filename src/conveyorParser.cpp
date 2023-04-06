#include <sstream>

#include "conveyorParser.hpp"
#include "Error.hpp"

#include "tail.hpp"
#include "cat.hpp"
#include "echo.hpp"


const char pipe = '|';
const std::string catOperation = "cat";
const std::string echoOperation = "echo";
const std::string tailOperation = "tail";

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

void ConveyorParser::commandParser(const std::string& stringCommand) {
    std::stringstream ss(stringCommand);
    std::string operationStr;
    std::vector<std::unique_ptr<Ioperation>> pipeLine;
    while (std::getline(ss, operationStr, pipe)) {
        operationStr = trim(operationStr);
        std::stringstream operationStream(operationStr);
        std::string operationType;
        operationStream >> operationType;

        if (operationType == catOperation) {
            std::string fileName;
            operationStream >> fileName;
            pipeLine.push_back(std::make_unique<CatOperation>(fileName));
        
        } else if (operationType == echoOperation) {
            std::string line;
            operationStream >> line;
            
            if (line.empty()) {
                throw EchoError{"Argument echo empty"};
            }

            pipeLine.push_back(std::make_unique<EchoOperation>(line));
        
        } else if (operationType == tailOperation) {
            int n;
            operationStream >> n;
            pipeLine.push_back(std::make_unique<TailOperation>(n));
        
        } else {
            throw ParserUnknow{"Operation empty or unknow"};
        }

    }

    // связываение всех элементов
    for(int i = pipeLine.size() - 2; i >= 0; --i) {
        pipeLine[i]->setNextOperation(std::move(pipeLine[i+1]));
    }
    firstPtr = std::move(pipeLine[0]);

}