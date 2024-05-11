cmake_minimum_required(VERSION 3.26.4)
project(StructArraySorting)

set(CMAKE_CXX_STANDARD 17)

add_executable(StructArraySorting main.cpp
        required.cpp
        required.hpp
        helper.cpp
        helper.hpp)
