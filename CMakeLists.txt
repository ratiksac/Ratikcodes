cmake_minimum_required(VERSION 3.15)
project(createteams)

set(CMAKE_CXX_STANDARD 14)

add_executable(createteams main.cpp teamdata.cpp teamdata.h priorityqueue.cpp priorityqueue.h)