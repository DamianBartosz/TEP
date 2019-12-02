cmake_minimum_required(VERSION 3.15)
project(List2)

set(CMAKE_CXX_STANDARD 98)

add_executable(List2 main.cpp CTable.cpp CTable.h CTableShallow.cpp CTableShallow.h consts.hpp proc.cpp proc.hpp)