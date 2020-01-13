#include <iostream>
#include "CMscnProblem.h"
#include "CRandom.hpp"
#include "CRandomSearch.h"

int main() {
    CMscnProblem *pcTest = new CMscnProblem();

//    pcTest->bSetNumberOfMagazines(2);
//    pcTest->bSetNumberOfShops(4);
//
//    pcTest->vGenerateInstance(time(NULL));
//
//    pcTest->vSaveProblem("test2.txt", true);
    string err = "";

    CRandomSearch cRandomSearch;
    cRandomSearch.vSetProblem(pcTest);
    vector<double> *pcFoundSolution = cRandomSearch.pcFindSolution(900);
    cout<<pcTest->dGetQuality(pcFoundSolution, err)<<endl;


    delete pcTest;
}
