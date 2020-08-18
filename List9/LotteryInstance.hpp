
#ifndef LIST9_LOTTERYINSTANCE_HPP
#define LIST9_LOTTERYINSTANCE_HPP


#include <wtypes.h>
#include <xstring>
#include <iostream>

using namespace std;
const int liczbaWynikow = 6;
const int maxLiczbaWynikow = 49;

class LotteryInstance {
private:
    int wyniki[liczbaWynikow];
    string  date;
    LotteryInstance(int *wyniki, string date);
    friend class LotteryGenerator;
public:
    void print();
};


#endif //LIST9_LOTTERYINSTANCE_HPP
