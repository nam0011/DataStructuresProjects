cmake_minimum_required(VERSION 3.15)
project(PROGRAM_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PROGRAM_2
        "Program 2.cpp"
        Player.cpp
        Player.h
        PlayerList.cpp
        PlayerList.h NameList.cpp)
