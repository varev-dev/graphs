cmake_minimum_required(VERSION 3.26)
project(graphs)

set(CMAKE_CXX_STANDARD 17)

add_executable(graphs main.cpp
        src/Graph.cpp
        include/Graph.h
        include/Vector.h
        src/Vector.tpp)
