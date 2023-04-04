cmake_minimum_required(VERSION 2.8.12) 
									
project(dz2)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(dz2 
    src/cat.cpp
    src/commandParser.cpp
    src/echo.cpp
    src/main.cpp
    src/openFile.cpp
    src/tail.cpp
)