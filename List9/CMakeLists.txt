cmake_minimum_required(VERSION 3.15)
project(List9)

set(CMAKE_CXX_STANDARD 98)

add_executable(List9 main.cpp CMscnProblem.cpp CMscnProblem.h CRandom.cpp CRandom.hpp CRandomSearch.cpp CRandomSearch.h LotteryGenerator.cpp LotteryGenerator.hpp LotteryInstance.cpp LotteryInstance.hpp CDiffEvol.cpp CDiffEvol.h CIndividual.cpp CIndividual.h)