#ifndef LIST9_LOTTERYGENERATOR_HPP
#define LIST9_LOTTERYGENERATOR_HPP


#include "LotteryInstance.hpp"
#include "CRandom.hpp"

class LotteryGenerator {
public:
    LotteryInstance generate(string date, long seed);
};


#endif //LIST9_LOTTERYGENERATOR_HPP
