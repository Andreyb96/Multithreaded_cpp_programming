cmake_minimum_required (VERSION 2.8.11)

project (final)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-std=c++11 -pthread")

add_executable (final getopt.h server.cpp)