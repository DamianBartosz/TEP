cmake_minimum_required(VERSION 3.15)
project(List7)

set(CMAKE_CXX_STANDARD 98)

add_executable(List7 main.cpp CMySmartPointer.h CRefCounter.cpp CRefCounter.h CTestClass.cpp CTestClass.h)