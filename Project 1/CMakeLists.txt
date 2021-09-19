cmake_minimum_required(VERSION 3.15)
project(Project_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project_2
        main.cpp
        PlayerStats.cpp
        PlayerStats.h)
