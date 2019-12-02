cmake_minimum_required(VERSION 3.15)
project(List1)

set(CMAKE_CXX_STANDARD 98)

add_executable(List1 main.cpp v_alloc_table_add_5.cpp functions.h consts.h "b_alloc_table_2_dim.cpp" b_dealloc_table_2_dim.cpp)