#include <iostream>
#include "CMscnProblem.h"
#include "CRandom.hpp"

int main() {
    CMscnProblem *pcTest = new CMscnProblem();

    cout<<pcTest->vLoadProblem("test.txt")<<endl;

    vector<double> *pdTest = new vector<double>();
    pdTest->push_back(1);
    pdTest->push_back(1);
    pdTest->push_back(1);

    string err;

//    pcTest->bSetNumberOfSuppliers(1);
//    pcTest->bSetNumberOfFactories(2);
//    pcTest->bSetNumberOfMagazines(1);
//    pcTest->bSetNumberOfShops(4);
//
//    pcTest->bSetCostSupplier_Factory(0, 0, 3);
//    pcTest->bSetCostSupplier_Factory(0, 1, 5);
//
//    pcTest->bSetCostFactory_Magazine(0, 0, 7);
//    pcTest->bSetCostFactory_Magazine(1, 0, 4);
//
//    pcTest->bSetCostMagazine_Shop(0, 0, 1);
//    pcTest->bSetCostMagazine_Shop(0, 1, 1.2);
//    pcTest->bSetCostMagazine_Shop(0, 2, 0.8);
//    pcTest->bSetCostMagazine_Shop(0, 3, 0.5);
//
//    pcTest->bSetProductionCapacityOfSupplier(0, 190);
//
//    pcTest->bSetProductionCapacityOfFactorie(0, 50.3);
//    pcTest->bSetProductionCapacityOfFactorie(1, 105.8);
//
//    pcTest->bSetProductionCapacityOfMagazine(0, 130.6);
//
//    pcTest->bSetMarketDemandOfShop(0, 5.5);
//    pcTest->bSetMarketDemandOfShop(1, 62);
//    pcTest->bSetMarketDemandOfShop(2, 11);
//    pcTest->bSetMarketDemandOfShop(3, 23.8);

    double dTestResultQuality = pcTest->dGetQuality(pdTest, err);
    if (dTestResultQuality == 0) cout << err;
    else cout << dTestResultQuality << endl;

    bool btestResultSatisfied = pcTest->bConstraintsSatisfied(pdTest, err);
    if (btestResultSatisfied == 0) cout << err;
    else cout << btestResultSatisfied << endl;

    pcTest->vSaveProblem("test2.txt");
    double *pdMin = pcTest->pdGetMinValuesOfSolution();
    double *pdMax = pcTest->pdGetMaxValuesOfSolution();
    for(int i=0; i<3; i++){
        cout<<pdMin[i]<<" "<<pdMax[i]<<endl;
    }

    delete pcTest;
}
