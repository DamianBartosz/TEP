#ifndef LIST9_CMSCNPROBLEM_H
#define LIST9_CMSCNPROBLEM_H

#include <iostream>
#include <vector>
#include <atlstr.h>
#include "CRandom.hpp"
#include "CProblem.h"

using namespace std;

class CMscnProblem : CProblem{
private:
    const double dMinProductionCost = 1;
    const double dMaxProductionCost = 200;

    const double dMinCapacityDemand = 200;
    const double dMaxCapacityDemand = 1000;

    const double dMinOneTimeCost = 1;
    const double dMaxOneTimeCost = 50;

    const double dMinIncomeForItem = 5;
    const double dMaxIncomeForItem = 300;

    const double dDefaultMinimalValue = 0;
    const double dDefaultMaximalValue = 200;

    int iNumberOfSuppliers, iNumberOfFactories, iNumberOfMagazines, iNumberOfShops;

    double **ppdMatrixOfCostsSupplier_Factory;
    double **ppdMatrixOfCostsFactory_Magazine;
    double **ppdMatrixOfCostsMagazine_Shop;

    double *pdArrayOfProductionCapacityOfSuppliers;
    double *pdArrayOfProductionCapacityOfFactories;
    double *pdArrayOfProductionCapacityOfMagazines;
    double *pdArrayOfMarketDemandOfShops;

    double *pdOneTimeCostOfSuppliers;
    double *pdOneTimeCostOfFactories;
    double *pdOneTimeCostOfMagazines;

    double *pdIncomeForItemInShops;

    double *pdSolutionMinimalValues;
    double *pdSolutionMaximalValues;
    bool bFullyCreated;

    bool bCheckSolution(vector<double> *pdSulution, string &err);

    double dNumberOfItemsFrom(vector<double> *pdSolution, int iStart, int iNumberOfElements);

    void destruct();

public:
    CMscnProblem();

    CMscnProblem(CString path);

    ~CMscnProblem();

    bool bSetNumberOfSuppliers(int iNumberOfSuppliers);

    bool bSetNumberOfFactories(int iNumberOfFactories);

    bool bSetNumberOfMagazines(int iNumberOfMagazines);

    bool bSetNumberOfShops(int iNumberOfShops);

    bool bSetCostSupplier_Factory(int indexNumberOfSuppliers, int indexNumberOfFactories, double elem);

    bool bSetCostFactory_Magazine(int indexNumberOfFactories, int indexNumberOfMagazines, double elem);

    bool bSetCostMagazine_Shop(int indexNumberOfMagazines, int indexNumberOfShops, double elem);

    bool bSetProductionCapacityOfSupplier(int index, double elem);

    bool bSetProductionCapacityOfFactorie(int index, double elem);

    bool bSetProductionCapacityOfMagazine(int index, double elem);

    bool bSetMarketDemandOfShop(int index, double elem);

    double dGetQuality(vector<double> *pdSolution, string &err);

    bool bConstraintsSatisfied(vector<double> *pdSolution, string &err) override;

    double *pdGetMinValuesOfSolution();

    double *pdGetMaxValuesOfSolution();

    bool vSaveProblem(CString path);

    bool vLoadProblem(CString path);

    void vGenerateInstance(int iInstanceSeed) override;
};


#endif //LIST9_CMSCNPROBLEM_H
