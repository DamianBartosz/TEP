#include <iostream>
#include "CMscnProblem.h"
#include "CRandom.hpp"

int main() {
//    CMscnProblem *pcTest = new CMscnProblem();
//
//    vector<double> *pdTest = new vector<double>();
//    pdTest->push_back(1);
//    pdTest->push_back(1);
//    pdTest->push_back(1);
//
//    string err;
//
//
//    double dTestResultQuality = pcTest->dGetQuality(pdTest, err);
//    if (dTestResultQuality == 0) cout << err;
//    else cout << dTestResultQuality << endl;
//
//    bool btestResultSatisfied = pcTest->bConstraintsSatisfied(pdTest, err);
//    if (btestResultSatisfied == 0) cout << err;
//    else cout << btestResultSatisfied << endl;
//
//    pcTest->vSaveProblem("test2.txt");
//    double *pdMin = pcTest->pdGetMinValuesOfSolution();
//    double *pdMax = pcTest->pdGetMaxValuesOfSolution();
//    for(int i=0; i<3; i++){
//        cout<<pdMin[i]<<" "<<pdMax[i]<<endl;
//    }
//
//    delete pcTest;

    CRandom rand;

    cout<<rand.iGetRandomInteger(100, 5000)<<endl;
    cout<<rand.dGetRandomDouble( 5000, 1000)<<endl;
}
