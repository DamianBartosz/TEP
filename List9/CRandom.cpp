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
    if(iStart>iEnd) {
        int iTemporary = iStart;
        iStart = iEnd;
        iEnd = iTemporary;
    }
    int iQuantity = iEnd - iStart + 1;
    return rand() % iQuantity + iStart;
}

double CRandom::dGetRandomDouble(double dStart, double dEnd) {
    if(dStart>dEnd) {
        double dTemporary = dStart;
        dStart = dEnd;
        dEnd = dTemporary;
    }
    dStart *= 1000;
    dEnd *= 1000;
    int iQuantity = dEnd - dStart + 1;
    return (rand() % iQuantity) / 1000.0 + dStart / 1000;
}
