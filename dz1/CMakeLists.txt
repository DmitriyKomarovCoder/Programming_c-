cmake_minimum_required(VERSION 3.0) 
									
project(dz1)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(dz1 
    src/main.cpp
    src/error.cpp
    src/Movie.cpp
    src/parcer.cpp
)
