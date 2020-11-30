cmake_minimum_required(VERSION 3.17)
project(wgu)

set(CMAKE_CXX_STANDARD 14)

add_executable(wgu main.cpp Student.cpp Student.h degree.h Roster.cpp Roster.h)