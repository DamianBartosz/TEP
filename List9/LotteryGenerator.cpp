#include "LotteryGenerator.hpp"

LotteryInstance LotteryGenerator::generate(string date, long seed) {
    CRandom cRandom;
    cRandom.vSetSeed(seed);
    bool wolne[maxLiczbaWynikow];
    for(int i=0; i < maxLiczbaWynikow; i++){
        wolne[i]=true;
    }
    int wyniki[liczbaWynikow];
    for (int i = 0; i < liczbaWynikow; i++) {
        int liczba = cRandom.iGetRandomInteger(1,49);
        if(!wolne[liczba-1]) i--;
        else {
            wyniki[i] = liczba;
            wolne[liczba-1] = false;
        }
    }
    Sleep(123);
    return LotteryInstance(wyniki, date);
}
