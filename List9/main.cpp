#include <iostream>
#include "CMscnProblem.h"
#include "CRandom.hpp"
#include "CRandomSearch.h"
#include "LotteryGenerator.hpp"

int main() {
    CMscnProblem *pcTest = new CMscnProblem();
//
////    pcTest->bSetNumberOfMagazines(2);
////    pcTest->bSetNumberOfShops(4);
////
////    pcTest->vGenerateInstance(time(NULL));
////
////    pcTest->vSaveProblem("test2.txt", true);
//    string err = "";
//
//    CRandomSearch cRandomSearch;
//    cRandomSearch.vSetProblem(pcTest);
//    vector<double> *pcFoundSolution = cRandomSearch.pcFindSolution(900);
//    cout<<pcTest->dGetQuality(pcFoundSolution, err)<<endl;
//
//
//    delete pcTest;

//    LotteryGenerator lotteryGenerator;
//    LotteryInstance lotteryInstance = lotteryGenerator.generate("14.01.2020", 12345775);
//    LotteryInstance lotteryInstance2 = lotteryGenerator.generate("16.01.2020", 124162);
//    LotteryInstance lotteryInstance3 = lotteryGenerator.generate("18.01.2020", 134371461723);
//
//    lotteryInstance.print();
//    lotteryInstance2.print();
//    lotteryInstance3.print();
//
//    int wynik[] = {1,2,3,4,5,6};

//    LotteryInstance lIErr = LotteryInstance(wynik, "testowa data");
}
