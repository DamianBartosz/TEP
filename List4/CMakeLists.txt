cmake_minimum_required(VERSION 3.15)
project(List4)

set(CMAKE_CXX_STANDARD 98)

add_executable(List4 main.cpp CFileLastError.cpp CFileLastError.hpp CFileThrowEx.cpp CFileThrowEx.hpp CFileErrorCode.cpp CFileErrorCode.hpp Car.cpp Car.hpp CarException.cpp CarException.hpp)