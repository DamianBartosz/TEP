cmake_minimum_required(VERSION 3.15)
project(List5)

set(CMAKE_CXX_STANDARD 98)

add_executable(List5 main.cpp CNodeStatic.hpp CTreeStatic.hpp CNodeDynamic.hpp CTreeDynamic.hpp )