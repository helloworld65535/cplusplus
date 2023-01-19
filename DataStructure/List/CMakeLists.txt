# cmake_minimum_required(VERSION 3.24)
project(List)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(List
        AbstractList.hpp
        ArrayList.hpp
        LinkedList.hpp
        main.cpp)
