cmake_minimum_required(VERSION 3.15)
project(PROJ3TEST)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PROJ3TEST
        Player.cpp
        Player.h
        PlayerList.cpp
        PlayerList.h
        "Program 3.cpp")
