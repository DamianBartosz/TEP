#include <iostream>
#include "CMscnProblem.h"
#include "CRandom.hpp"
#include "CRandomSearch.h"
#include "LotteryGenerator.hpp"
#include "CDiffEvol.h"

int main() {
    srand(time(NULL));
    CMscnProblem *pcTest = new CMscnProblem();

    string err = "";

    CDiffEvol cDiffEvol = CDiffEvol(pcTest);
    cDiffEvol.pcStartToEvole(100);
    vector<double> *pcFoundSolution = cDiffEvol.pdGetBestSolution();
    cout << pcTest->dGetQuality(pcFoundSolution, err) << endl;


    delete pcTest;
}
