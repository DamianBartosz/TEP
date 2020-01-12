#include "CRandom.hpp"
#include <iostream>

using namespace std;

CRandom::CRandom() {
    srand(time(NULL));
}

CRandom::CRandom(long lSeed) {
    srand(lSeed);
}

CRandom::~CRandom() {}

void CRandom::vSetSeed(long lSeed) {
    srand(lSeed);
}

int CRandom::iGetRandomInteger(int iStart, int iEnd) {
    int iQuantity = iEnd - iStart + 1;
    return rand() % iQuantity + iStart;
}

double CRandom::dGetRandomDouble(double dStart, double dEnd) {
    dStart *= 1000;
    dEnd *= 1000;
    int iQuantity = dEnd - dStart + 1;
    return (rand() % iQuantity) / 1000.0 + dStart / 1000;
}
