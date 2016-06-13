cmake_minimum_required(VERSION 3.5)
project(Sorting_11_06)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Sorting.h)
add_executable(Sorting_11_06 ${SOURCE_FILES})