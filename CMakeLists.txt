cmake_minimum_required(VERSION 3.15)
project(exec2)

set(CMAKE_CXX_STANDARD 11)

add_executable(exec2 consistentresultverification.cpp mergesort.cpp mergesort.h quicksort.cpp quicksort.h insertionsort.cpp insertionsort.h consistentresultverification.cpp)