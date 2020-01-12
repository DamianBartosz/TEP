#ifndef LIST9_CRANDOM_HPP
#define LIST9_CRANDOM_HPP

#include <stdlib.h>
#include <time.h>

class CRandom {
public:
    CRandom();
    CRandom(long lSeed);
    ~CRandom();
    void vSetSeed(long lSeed);
    int iGetRandomInteger(int iStart, int iEnd);
    double dGetRandomDouble(double dStart, double dEnd);
};


#endif //LIST9_CRANDOM_HPP
