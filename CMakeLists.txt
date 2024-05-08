cmake_minimum_required(VERSION 3.28)
project(StructArraySorting)

set(CMAKE_CXX_STANDARD 17)

add_executable(StructArraySorting main.cpp
        required.cpp
        required.h
        helper.cpp
        helper.h)
