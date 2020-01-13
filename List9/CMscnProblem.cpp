#include "CMscnProblem.h"

CMscnProblem::CMscnProblem() {
    iNumberOfSuppliers = 1;
    iNumberOfFactories = 1;
    iNumberOfMagazines = 1;
    iNumberOfShops = 1;


    ppdMatrixOfCostsSupplier_Factory = new double *[1];
    ppdMatrixOfCostsSupplier_Factory[0] = new double[1];
    ppdMatrixOfCostsSupplier_Factory[0][0] = 3;

    ppdMatrixOfCostsFactory_Magazine = new double *[1];
    ppdMatrixOfCostsFactory_Magazine[0] = new double[1];
    ppdMatrixOfCostsFactory_Magazine[0][0] = 4;

    ppdMatrixOfCostsMagazine_Shop = new double *[1];
    ppdMatrixOfCostsMagazine_Shop[0] = new double[1];
    ppdMatrixOfCostsMagazine_Shop[0][0] = 1;


    pdArrayOfProductionCapacityOfSuppliers = new double[1];
    pdArrayOfProductionCapacityOfSuppliers[0] = 100;

    pdArrayOfProductionCapacityOfFactories = new double[1];
    pdArrayOfProductionCapacityOfFactories[0] = 50;

    pdArrayOfProductionCapacityOfMagazines = new double[1];
    pdArrayOfProductionCapacityOfMagazines[0] = 10.5;

    pdArrayOfMarketDemandOfShops = new double[1];
    pdArrayOfMarketDemandOfShops[0] = 100;


    pdOneTimeCostOfSuppliers = new double[1];
    pdOneTimeCostOfSuppliers[0] = 10;

    pdOneTimeCostOfFactories = new double[1];
    pdOneTimeCostOfFactories[0] = 10;

    pdOneTimeCostOfMagazines = new double[1];
    pdOneTimeCostOfMagazines[0] = 10;


    pdIncomeForItemInShops = new double[1];
    pdIncomeForItemInShops[0] = 100;


    pdSolutionMinimalValues = new double[3];
    pdSolutionMinimalValues[0] = 0;
    pdSolutionMinimalValues[1] = 0;
    pdSolutionMinimalValues[2] = 0;

    pdSolutionMaximalValues = new double[3];
    pdSolutionMaximalValues[0] = 100;
    pdSolutionMaximalValues[1] = 100;
    pdSolutionMaximalValues[2] = 100;
    bFullyCreated = true;
}

CMscnProblem::CMscnProblem(CString path) {
    bFullyCreated = false;
    vLoadProblem(path);
}

CMscnProblem::~CMscnProblem() {
    destruct();
}

bool CMscnProblem::bSetNumberOfSuppliers(int iNumberOfSuppliers) {
    if (iNumberOfSuppliers <= 0) return false;

    double **ppdNewMatrixOfCostsSupplier_Factory = new double *[iNumberOfSuppliers];
    for (int i = 0; i < iNumberOfSuppliers; i++) {
        ppdNewMatrixOfCostsSupplier_Factory[i] = new double[iNumberOfFactories];
        for (int j = 0; j < iNumberOfFactories; j++) {
            if (i < this->iNumberOfSuppliers) {
                ppdNewMatrixOfCostsSupplier_Factory[j][j] = ppdMatrixOfCostsSupplier_Factory[i][j];
            }
        }
    }

    double *pdNewArrayOfProductionCapacityOfSuppliers = new double[iNumberOfSuppliers];
    for (int i = 0; i < iNumberOfSuppliers && i < this->iNumberOfSuppliers; i++) {
        pdNewArrayOfProductionCapacityOfSuppliers[i] = pdArrayOfProductionCapacityOfSuppliers[i];
    }

    for (int i = 0; i < this->iNumberOfSuppliers; i++) {
        delete[] ppdMatrixOfCostsSupplier_Factory[i];
    }
    delete[] ppdMatrixOfCostsSupplier_Factory;
    delete[] pdArrayOfProductionCapacityOfSuppliers;
    delete[] pdOneTimeCostOfSuppliers;
    delete[] pdSolutionMinimalValues;
    delete[] pdSolutionMaximalValues;

    this->iNumberOfSuppliers = iNumberOfSuppliers;
    ppdMatrixOfCostsSupplier_Factory = ppdNewMatrixOfCostsSupplier_Factory;
    pdArrayOfProductionCapacityOfSuppliers = pdNewArrayOfProductionCapacityOfSuppliers;
    pdOneTimeCostOfSuppliers = new double[iNumberOfSuppliers];
    pdSolutionMinimalValues = new double[iNumberOfSuppliers * iNumberOfFactories +
                                         iNumberOfFactories * iNumberOfMagazines + iNumberOfMagazines * iNumberOfShops];
    pdSolutionMaximalValues = new double[iNumberOfSuppliers * iNumberOfFactories +
                                         iNumberOfFactories * iNumberOfMagazines + iNumberOfMagazines * iNumberOfShops];

    return true;
}

bool CMscnProblem::bSetNumberOfFactories(int iNumberOfFactories) {
    if (iNumberOfFactories <= 0) return false;

    double **ppdNewMatrixOfCostsSupplier_Factory = new double *[this->iNumberOfSuppliers];
    double **ppdNewMatrixOfCostsFactory_Magazine = new double *[iNumberOfFactories];

    for (int i = 0; i < this->iNumberOfSuppliers; i++) {
        ppdNewMatrixOfCostsSupplier_Factory[i] = new double[iNumberOfFactories];
        for (int j = 0; j < this->iNumberOfFactories; j++) {
            if (j < iNumberOfFactories) {
                ppdNewMatrixOfCostsSupplier_Factory[i][j] = ppdMatrixOfCostsSupplier_Factory[i][j];
            }
        }
        delete[] ppdMatrixOfCostsSupplier_Factory[i];
    }
    delete[] ppdMatrixOfCostsSupplier_Factory;
    ppdMatrixOfCostsSupplier_Factory = ppdNewMatrixOfCostsSupplier_Factory;

    for (int i = 0; i < iNumberOfFactories; i++) {
        ppdNewMatrixOfCostsFactory_Magazine[i] = new double[this->iNumberOfMagazines];
        for (int j = 0; j < this->iNumberOfMagazines; j++) {
            if (i < this->iNumberOfFactories) {
                ppdNewMatrixOfCostsFactory_Magazine[i][j] = ppdMatrixOfCostsFactory_Magazine[i][j];
            }
        }
    }

    for (int i = 0; i < this->iNumberOfFactories; i++) {
        delete[] ppdMatrixOfCostsFactory_Magazine[i];
    }
    delete[] ppdMatrixOfCostsFactory_Magazine;
    ppdMatrixOfCostsFactory_Magazine = ppdNewMatrixOfCostsFactory_Magazine;

    double *pdNewArrayOfProductionCapacityOfFactories = new double[iNumberOfFactories];
    for (int i = 0; i > this->iNumberOfFactories; i++) {
        if (i < iNumberOfFactories) {
            pdNewArrayOfProductionCapacityOfFactories[i] = pdArrayOfProductionCapacityOfFactories[i];
        }
    }
    delete[] pdArrayOfProductionCapacityOfFactories;
    delete[] pdOneTimeCostOfFactories;
    delete[] pdSolutionMinimalValues;
    delete[] pdSolutionMaximalValues;

    pdArrayOfProductionCapacityOfFactories = pdNewArrayOfProductionCapacityOfFactories;

    this->iNumberOfFactories = iNumberOfFactories;

    pdOneTimeCostOfFactories = new double[iNumberOfFactories];
    pdSolutionMinimalValues = new double[iNumberOfSuppliers * iNumberOfFactories +
                                         iNumberOfFactories * iNumberOfMagazines + iNumberOfMagazines * iNumberOfShops];
    pdSolutionMaximalValues = new double[iNumberOfSuppliers * iNumberOfFactories +
                                         iNumberOfFactories * iNumberOfMagazines + iNumberOfMagazines * iNumberOfShops];

    return true;
}

bool CMscnProblem::bSetNumberOfMagazines(int iNumberOfMagazines) {
    if (iNumberOfMagazines <= 0) return false;

    double **ppdNewMatrixOfCostsFactory_Magazine = new double *[this->iNumberOfFactories];
    double **ppdNewMatrixOfCostsMagazine_Shop = new double *[iNumberOfMagazines];

    for (int i = 0; i < this->iNumberOfFactories; i++) {
        ppdNewMatrixOfCostsFactory_Magazine[i] = new double[iNumberOfMagazines];
        for (int j = 0; j < this->iNumberOfMagazines; j++) {
            if (j < iNumberOfMagazines) {
                ppdNewMatrixOfCostsFactory_Magazine[i][j] = ppdMatrixOfCostsFactory_Magazine[i][j];
            }
        }
        delete[] ppdMatrixOfCostsFactory_Magazine[i];
    }
    delete[] ppdMatrixOfCostsFactory_Magazine;
    ppdMatrixOfCostsFactory_Magazine = ppdNewMatrixOfCostsFactory_Magazine;

    for (int i = 0; i < iNumberOfMagazines; i++) {
        ppdNewMatrixOfCostsMagazine_Shop[i] = new double[this->iNumberOfShops];
        for (int j = 0; j < this->iNumberOfShops; j++) {
            if (i < this->iNumberOfMagazines) {
                ppdNewMatrixOfCostsMagazine_Shop[i][j] = ppdMatrixOfCostsMagazine_Shop[i][j];
            }
        }
    }

    for (int i = 0; i < this->iNumberOfMagazines; i++) {
        delete[] ppdMatrixOfCostsMagazine_Shop[i];
    }
    delete[] ppdMatrixOfCostsMagazine_Shop;
    ppdMatrixOfCostsMagazine_Shop = ppdNewMatrixOfCostsMagazine_Shop;

    double *pdNewArrayOfProductionCapacityOfMagazines = new double[iNumberOfMagazines];
    for (int i = 0; i > this->iNumberOfMagazines; i++) {
        if (i < iNumberOfMagazines) {
            pdNewArrayOfProductionCapacityOfMagazines[i] = pdArrayOfProductionCapacityOfMagazines[i];
        }
    }
    delete[] pdArrayOfProductionCapacityOfMagazines;
    delete[] pdOneTimeCostOfMagazines;
    delete[] pdSolutionMinimalValues;
    delete[] pdSolutionMaximalValues;
    pdArrayOfProductionCapacityOfMagazines = pdNewArrayOfProductionCapacityOfMagazines;

    this->iNumberOfMagazines = iNumberOfMagazines;
    pdOneTimeCostOfMagazines = new double[iNumberOfMagazines];
    pdSolutionMinimalValues = new double[iNumberOfSuppliers * iNumberOfFactories +
                                         iNumberOfFactories * iNumberOfMagazines + iNumberOfMagazines * iNumberOfShops];
    pdSolutionMaximalValues = new double[iNumberOfSuppliers * iNumberOfFactories +
                                         iNumberOfFactories * iNumberOfMagazines + iNumberOfMagazines * iNumberOfShops];

    return true;
}

bool CMscnProblem::bSetNumberOfShops(int iNumberOfShops) {
    if (iNumberOfShops <= 0) return false;

    double **ppdNewMatrixOfCostsMagazine_Shop = new double *[this->iNumberOfMagazines];

    for (int i = 0; i < this->iNumberOfMagazines; i++) {
        ppdNewMatrixOfCostsMagazine_Shop[i] = new double[iNumberOfShops];
        for (int j = 0; j < this->iNumberOfShops; j++) {
            if (j < iNumberOfShops) {
                ppdNewMatrixOfCostsMagazine_Shop[i][j] = ppdMatrixOfCostsMagazine_Shop[i][j];
            }
        }
        delete[] ppdMatrixOfCostsMagazine_Shop[i];
    }
    delete[] ppdMatrixOfCostsMagazine_Shop;
    ppdMatrixOfCostsMagazine_Shop = ppdNewMatrixOfCostsMagazine_Shop;

    double *pdNewArrayOfMarketDemandOfShops = new double[iNumberOfShops];
    for (int i = 0; i > this->iNumberOfShops; i++) {
        if (i < iNumberOfShops) {
            pdNewArrayOfMarketDemandOfShops[i] = pdArrayOfMarketDemandOfShops[i];
        }
    }
    delete[] pdArrayOfMarketDemandOfShops;
    delete[] pdIncomeForItemInShops;
    delete[] pdSolutionMinimalValues;
    delete[] pdSolutionMaximalValues;
    pdArrayOfMarketDemandOfShops = pdNewArrayOfMarketDemandOfShops;

    this->iNumberOfShops = iNumberOfShops;

    pdIncomeForItemInShops = new double[iNumberOfShops];
    pdSolutionMinimalValues = new double[iNumberOfSuppliers * iNumberOfFactories +
                                         iNumberOfFactories * iNumberOfMagazines + iNumberOfMagazines * iNumberOfShops];
    pdSolutionMaximalValues = new double[iNumberOfSuppliers * iNumberOfFactories +
                                         iNumberOfFactories * iNumberOfMagazines + iNumberOfMagazines * iNumberOfShops];

    return true;
}

bool CMscnProblem::bSetCostSupplier_Factory(int indexNumberOfSuppliers, int indexNumberOfFactories, double elem) {
    if (indexNumberOfSuppliers >= this->iNumberOfSuppliers) return false;
    if (indexNumberOfFactories >= this->iNumberOfFactories) return false;
    if (elem < 0) return false;

    ppdMatrixOfCostsSupplier_Factory[indexNumberOfSuppliers][indexNumberOfFactories] = elem;
    return true;
}

bool CMscnProblem::bSetCostFactory_Magazine(int indexNumberOfFactories, int indexNumberOfMagazines, double elem) {
    if (indexNumberOfFactories >= this->iNumberOfFactories) return false;
    if (indexNumberOfMagazines >= this->iNumberOfMagazines) return false;
    if (elem < 0) return false;

    ppdMatrixOfCostsFactory_Magazine[indexNumberOfFactories][indexNumberOfMagazines] = elem;
    return true;
}

bool CMscnProblem::bSetCostMagazine_Shop(int indexNumberOfMagazines, int indexNumberOfShops, double elem) {
    if (indexNumberOfMagazines >= this->iNumberOfMagazines) return false;
    if (indexNumberOfShops >= this->iNumberOfShops) return false;
    if (elem < 0) return false;

    ppdMatrixOfCostsMagazine_Shop[indexNumberOfMagazines][indexNumberOfShops] = elem;
    return true;
}

bool CMscnProblem::bSetProductionCapacityOfSupplier(int index, double elem) {
    if (index >= this->iNumberOfSuppliers) return false;
    if (elem < 0) return false;

    pdArrayOfProductionCapacityOfSuppliers[index] = elem;
    return true;
}

bool CMscnProblem::bSetProductionCapacityOfFactorie(int index, double elem) {
    if (index >= this->iNumberOfFactories) return false;
    if (elem < 0) return false;

    pdArrayOfProductionCapacityOfFactories[index] = elem;
    return true;
}

bool CMscnProblem::bSetProductionCapacityOfMagazine(int index, double elem) {
    if (index >= this->iNumberOfMagazines) return false;
    if (elem < 0) return false;

    pdArrayOfProductionCapacityOfMagazines[index] = elem;
    return true;
}

bool CMscnProblem::bSetMarketDemandOfShop(int index, double elem) {
    if (index >= this->iNumberOfShops) return false;
    if (elem < 0) return false;

    pdArrayOfMarketDemandOfShops[index] = elem;
    return true;
}

double CMscnProblem::dGetQuality(vector<double> *pdSolution, string &err) {
    if (!bCheckSolution(pdSolution, err)) return 0;

    double dIncome = 0;
    double dProductionCost = 0;
    double dPermamentContractsCost = 0;

    int iNumberOfElementsInSupplier_FactoryMatrix = iNumberOfSuppliers * iNumberOfFactories;
    int iNumberOfElementsInFactory_MagazineMatrix = iNumberOfFactories * iNumberOfMagazines;

    for (int i = 0; i < iNumberOfMagazines; i++) {
        for (int j = 0; j < iNumberOfShops; j++) {
            dIncome += pdIncomeForItemInShops[j] * pdSolution->at(
                    iNumberOfElementsInSupplier_FactoryMatrix + iNumberOfElementsInFactory_MagazineMatrix +
                    i * iNumberOfShops + j);
        }
    }

    for (int i = 0; i < iNumberOfSuppliers; i++) {
        for (int j = 0; j < iNumberOfFactories; j++) {
            dProductionCost += ppdMatrixOfCostsSupplier_Factory[i][j] * pdSolution->at(i * iNumberOfFactories + j);
        }
    }

    for (int i = 0; i < iNumberOfFactories; i++) {
        for (int j = 0; j < iNumberOfMagazines; j++) {
            dProductionCost += ppdMatrixOfCostsFactory_Magazine[i][j] *
                               pdSolution->at(iNumberOfElementsInSupplier_FactoryMatrix + i * iNumberOfMagazines + j);
        }
    }

    for (int i = 0; i < iNumberOfMagazines; i++) {
        for (int j = 0; j < iNumberOfShops; j++) {
            dProductionCost += ppdMatrixOfCostsMagazine_Shop[i][j] * pdSolution->at(
                    iNumberOfElementsInSupplier_FactoryMatrix + iNumberOfElementsInFactory_MagazineMatrix +
                    i * iNumberOfShops + j);
        }
    }

    for (int i = 0; i < iNumberOfSuppliers; i++) {
        int iEpsilon = dNumberOfItemsFrom(pdSolution, i * iNumberOfSuppliers, iNumberOfFactories) > 0;
        dPermamentContractsCost += iEpsilon * pdOneTimeCostOfSuppliers[i];
    }

    for (int i = 0; i < iNumberOfFactories; i++) {
        int iEpsilon =
                dNumberOfItemsFrom(pdSolution, iNumberOfElementsInSupplier_FactoryMatrix + i * iNumberOfFactories,
                                   iNumberOfMagazines) > 0;
        dPermamentContractsCost += iEpsilon * pdOneTimeCostOfFactories[i];
    }

    for (int i = 0; i < iNumberOfMagazines; i++) {
        int iEpsilon = dNumberOfItemsFrom(pdSolution, iNumberOfElementsInSupplier_FactoryMatrix +
                                                      iNumberOfElementsInFactory_MagazineMatrix +
                                                      i * iNumberOfMagazines, iNumberOfShops) > 0;
        dPermamentContractsCost += iEpsilon * pdOneTimeCostOfMagazines[i];
    }

    return dIncome - dProductionCost - dPermamentContractsCost;
}

bool CMscnProblem::bConstraintsSatisfied(vector<double> *pdSolution, string &err) {
    int iNumberOfElementsInSupplier_FactoryMatrix = iNumberOfSuppliers * iNumberOfFactories;
    int iNumberOfElementsInFactory_MagazineMatrix = iNumberOfFactories * iNumberOfMagazines;

    if (!bCheckSolution(pdSolution, err)) return false;

    for (int i = 0; i < iNumberOfSuppliers; i++) {
        if (dNumberOfItemsFrom(pdSolution, i * iNumberOfSuppliers, iNumberOfFactories) >
            pdArrayOfProductionCapacityOfSuppliers[i])
            return false;
    }

    for (int i = 0; i < iNumberOfFactories; i++) {
        if (dNumberOfItemsFrom(pdSolution, iNumberOfElementsInSupplier_FactoryMatrix + i * iNumberOfFactories,
                               iNumberOfMagazines) >
            pdArrayOfProductionCapacityOfFactories[i])
            return false;
    }

    for (int i = 0; i < iNumberOfMagazines; i++) {
        if (dNumberOfItemsFrom(pdSolution, iNumberOfElementsInSupplier_FactoryMatrix +
                                           iNumberOfElementsInFactory_MagazineMatrix +
                                           i * iNumberOfMagazines, iNumberOfShops) >
            pdArrayOfProductionCapacityOfMagazines[i])
            return false;
    }

    for (int i = 0; i < iNumberOfShops; i++) {
        double dNumberOfItemsToShop = 0;
        for (int j = 0; j < iNumberOfMagazines; j++) {
            dNumberOfItemsToShop += pdSolution->at(
                    iNumberOfElementsInSupplier_FactoryMatrix + iNumberOfElementsInFactory_MagazineMatrix +
                    j * iNumberOfShops + i);
        }
        if (dNumberOfItemsToShop > pdArrayOfMarketDemandOfShops[i]) return false;
    }

    for (int i = 0; i < iNumberOfFactories; i++) {
        double dNumberOfItemsToFactory = 0;
        for (int j = 0; j < iNumberOfMagazines; j++) {
            dNumberOfItemsToFactory += pdSolution->at(
                    j * iNumberOfFactories + i);
        }
        if (dNumberOfItemsToFactory <
            dNumberOfItemsFrom(pdSolution, iNumberOfElementsInSupplier_FactoryMatrix + i * iNumberOfFactories,
                               iNumberOfMagazines))
            return false;
    }

    for (int i = 0; i < iNumberOfMagazines; i++) {
        double dNumberOfItemsToMagazine = 0;
        for (int j = 0; j < iNumberOfFactories; j++) {
            dNumberOfItemsToMagazine += pdSolution->at(
                    j * iNumberOfMagazines + i);
        }
        if (dNumberOfItemsToMagazine <
            dNumberOfItemsFrom(pdSolution, iNumberOfElementsInSupplier_FactoryMatrix +
                                           iNumberOfElementsInFactory_MagazineMatrix +
                                           i * iNumberOfMagazines, iNumberOfShops))
            return false;
    }
    for (int i = 0; i < pdSolution->size(); i++) {
        if (pdSolution->at(i) < pdSolutionMinimalValues[i] || pdSolution->at(i) > pdSolutionMaximalValues[i])
            return false;
    }

    return true;

}

double *CMscnProblem::pdGetMinValuesOfSolution() {
    return pdSolutionMinimalValues;
}

double *CMscnProblem::pdGetMaxValuesOfSolution() {
    return pdSolutionMaximalValues;
}

bool CMscnProblem::vSaveProblem(CString path, bool bReadOnly) {
    FILE *pfFileToLoad = fopen(path, "w");
    if (!pfFileToLoad) return false;

    if(bReadOnly){
        fprintf(pfFileToLoad, "Number of suppliers: ");
    }
    fprintf(pfFileToLoad, "%d\n", iNumberOfSuppliers);

    if(bReadOnly){
        fprintf(pfFileToLoad, "Number of factories: ");
    }
    fprintf(pfFileToLoad, "%d\n", iNumberOfFactories);

    if(bReadOnly){
        fprintf(pfFileToLoad, "Number of magazines: ");
    }
    fprintf(pfFileToLoad, "%d\n", iNumberOfMagazines);

    if(bReadOnly){
        fprintf(pfFileToLoad, "Number of shops: ");
    }
    fprintf(pfFileToLoad, "%d\n", iNumberOfShops);

    for (int i = 0; i < iNumberOfSuppliers; i++) {
        for (int j = 0; j < iNumberOfFactories; j++) {
            if(bReadOnly){
                fprintf(pfFileToLoad, "Cost supplier->factory[%d][%d]: ", i, j);
            }
            fprintf(pfFileToLoad, "%lf\n", ppdMatrixOfCostsSupplier_Factory[i][i]);
        }
    }

    for (int i = 0; i < iNumberOfFactories; i++) {
        for (int j = 0; j < iNumberOfMagazines; j++) {
            if(bReadOnly){
                fprintf(pfFileToLoad, "Cost factory->magazine[%d][%d]: ", i, j);
            }
            fprintf(pfFileToLoad, "%lf\n", ppdMatrixOfCostsFactory_Magazine[i][i]);
        }
    }

    for (int i = 0; i < iNumberOfMagazines; i++) {
        for (int j = 0; j < iNumberOfShops; j++) {
            if(bReadOnly){
                fprintf(pfFileToLoad, "Cost magazine->shop[%d][%d]: ", i, j);
            }
            fprintf(pfFileToLoad, "%lf\n", ppdMatrixOfCostsMagazine_Shop[i][i]);
        }
    }


    for (int i = 0; i < iNumberOfSuppliers; i++) {
        if(bReadOnly){
            fprintf(pfFileToLoad, "Production capacity of supplier[%d]: ", i);
        }
        fprintf(pfFileToLoad, "%lf\n", pdArrayOfProductionCapacityOfSuppliers[i]);
    }

    for (int i = 0; i < iNumberOfFactories; i++) {
        if(bReadOnly){
            fprintf(pfFileToLoad, "Production capacity of factory[%d]: ", i);
        }
        fprintf(pfFileToLoad, "%lf\n", pdArrayOfProductionCapacityOfFactories[i]);
    }

    for (int i = 0; i < iNumberOfMagazines; i++) {
        if(bReadOnly){
            fprintf(pfFileToLoad, "Production capacity of magazine[%d]: ", i);
        }
        fprintf(pfFileToLoad, "%lf\n", pdArrayOfProductionCapacityOfMagazines[i]);
    }

    for (int i = 0; i < iNumberOfShops; i++) {
        if(bReadOnly){
            fprintf(pfFileToLoad, "Market demand of shop[%d]: ", i);
        }
        fprintf(pfFileToLoad, "%lf\n", pdArrayOfMarketDemandOfShops[i]);
    }


    for (int i = 0; i < iNumberOfSuppliers; i++) {
        if(bReadOnly){
            fprintf(pfFileToLoad, "One time cost of supplier[%d]: ", i);
        }
        fprintf(pfFileToLoad, "%lf\n", pdOneTimeCostOfSuppliers[i]);
    }

    for (int i = 0; i < iNumberOfFactories; i++) {
        if(bReadOnly){
            fprintf(pfFileToLoad, "One time cost of factory[%d]: ", i);
        }
        fprintf(pfFileToLoad, "%lf\n", pdOneTimeCostOfFactories[i]);
    }

    for (int i = 0; i < iNumberOfMagazines; i++) {
        if(bReadOnly){
            fprintf(pfFileToLoad, "One time cost of magazine[%d]: ", i);
        }
        fprintf(pfFileToLoad, "%lf\n", pdOneTimeCostOfMagazines[i]);
    }


    for (int i = 0; i < iNumberOfShops; i++) {
        if(bReadOnly){
            fprintf(pfFileToLoad, "Income for item in shop[%d]: ", i);
        }
        fprintf(pfFileToLoad, "%lf\n", pdIncomeForItemInShops[i]);
    }


    int iNumberOfElemsInSolution = iNumberOfSuppliers * iNumberOfFactories + iNumberOfFactories * iNumberOfMagazines +
                                   iNumberOfMagazines * iNumberOfShops;


    for (int i = 0; i < iNumberOfElemsInSolution; i++) {
        if(bReadOnly){
            fprintf(pfFileToLoad, "Minimal value of solution element[%d]: ", i);
        }
        fprintf(pfFileToLoad, "%lf\n", pdSolutionMinimalValues[i]);
    }

    for (int i = 0; i < iNumberOfElemsInSolution; i++) {
        if(bReadOnly){
            fprintf(pfFileToLoad, "Maximal value of solution element[%d]: ", i);
        }
        fprintf(pfFileToLoad, "%lf\n", pdSolutionMaximalValues[i]);
    }

    fclose(pfFileToLoad);
    return true;
}

bool CMscnProblem::vLoadProblem(CString path) {
    destruct();

    FILE *pfFileToLoad = fopen(path, "r");
    if (!pfFileToLoad) return false;


    if (!feof(pfFileToLoad))fscanf(pfFileToLoad, "%d", &iNumberOfSuppliers);
    else {
        fclose(pfFileToLoad);
        return false;
    }

    if (!feof(pfFileToLoad))fscanf(pfFileToLoad, "%d", &iNumberOfFactories);
    else {
        fclose(pfFileToLoad);
        return false;
    }

    if (!feof(pfFileToLoad))fscanf(pfFileToLoad, "%d", &iNumberOfMagazines);
    else {
        fclose(pfFileToLoad);
        return false;
    }

    if (!feof(pfFileToLoad))fscanf(pfFileToLoad, "%d", &iNumberOfShops);
    else {
        fclose(pfFileToLoad);
        return false;
    }

    ppdMatrixOfCostsSupplier_Factory = new double *[iNumberOfSuppliers];
    for (int i = 0; i < iNumberOfSuppliers; i++) {
        ppdMatrixOfCostsSupplier_Factory[i] = new double[iNumberOfFactories];
        for (int j = 0; j < iNumberOfFactories; j++) {
            if (!feof(pfFileToLoad))fscanf(pfFileToLoad, "%lf", &ppdMatrixOfCostsSupplier_Factory[i][j]);
            else {
                fclose(pfFileToLoad);
                return false;
            }
        }
    }

    ppdMatrixOfCostsFactory_Magazine = new double *[iNumberOfFactories];
    for (int i = 0; i < iNumberOfFactories; i++) {
        ppdMatrixOfCostsFactory_Magazine[i] = new double[iNumberOfMagazines];
        for (int j = 0; j < iNumberOfMagazines; j++) {
            if (!feof(pfFileToLoad))fscanf(pfFileToLoad, "%lf", &ppdMatrixOfCostsFactory_Magazine[i][j]);
            else {
                fclose(pfFileToLoad);
                return false;
            }
        }
    }


    ppdMatrixOfCostsMagazine_Shop = new double *[iNumberOfMagazines];
    for (int i = 0; i < iNumberOfMagazines; i++) {
        ppdMatrixOfCostsMagazine_Shop[i] = new double[iNumberOfShops];
        for (int j = 0; j < iNumberOfShops; j++) {
            if (!feof(pfFileToLoad))fscanf(pfFileToLoad, "%lf", &ppdMatrixOfCostsMagazine_Shop[i][j]);
            else {
                fclose(pfFileToLoad);
                return false;
            }
        }
    }


    pdArrayOfProductionCapacityOfSuppliers = new double[iNumberOfSuppliers];
    for (int i = 0; i < iNumberOfSuppliers; i++) {
        if (!feof(pfFileToLoad))fscanf(pfFileToLoad, "%lf", &pdArrayOfProductionCapacityOfSuppliers[i]);
        else {
            fclose(pfFileToLoad);
            return false;
        }
    }

    pdArrayOfProductionCapacityOfFactories = new double[iNumberOfFactories];
    for (int i = 0; i < iNumberOfFactories; i++) {
        if (!feof(pfFileToLoad))fscanf(pfFileToLoad, "%lf", &pdArrayOfProductionCapacityOfFactories[i]);
        else {
            fclose(pfFileToLoad);
            return false;
        }
    }

    pdArrayOfProductionCapacityOfMagazines = new double[iNumberOfMagazines];
    for (int i = 0; i < iNumberOfMagazines; i++) {
        if (!feof(pfFileToLoad))fscanf(pfFileToLoad, "%lf", &pdArrayOfProductionCapacityOfMagazines[i]);
        else {
            fclose(pfFileToLoad);
            return false;
        }
    }

    pdArrayOfMarketDemandOfShops = new double[iNumberOfShops];
    for (int i = 0; i < iNumberOfShops; i++) {
        if (!feof(pfFileToLoad))fscanf(pfFileToLoad, "%lf", &pdArrayOfMarketDemandOfShops[i]);
        else {
            fclose(pfFileToLoad);
            return false;
        }
    }


    pdOneTimeCostOfSuppliers = new double[iNumberOfSuppliers];
    for (int i = 0; i < iNumberOfSuppliers; i++) {
        if (!feof(pfFileToLoad))fscanf(pfFileToLoad, "%lf", &pdOneTimeCostOfSuppliers[i]);
        else {
            fclose(pfFileToLoad);
            return false;
        }
    }

    pdOneTimeCostOfFactories = new double[iNumberOfFactories];
    for (int i = 0; i < iNumberOfFactories; i++) {
        if (!feof(pfFileToLoad))fscanf(pfFileToLoad, "%lf", &pdOneTimeCostOfFactories[i]);
        else {
            fclose(pfFileToLoad);
            return false;
        }
    }

    pdOneTimeCostOfMagazines = new double[iNumberOfMagazines];
    for (int i = 0; i < iNumberOfMagazines; i++) {
        if (!feof(pfFileToLoad))fscanf(pfFileToLoad, "%lf", &pdOneTimeCostOfMagazines[i]);
        else {
            fclose(pfFileToLoad);
            return false;
        }
    }


    pdIncomeForItemInShops = new double[iNumberOfShops];
    for (int i = 0; i < iNumberOfShops; i++) {
        if (!feof(pfFileToLoad))fscanf(pfFileToLoad, "%lf", &pdIncomeForItemInShops[i]);
        else {
            fclose(pfFileToLoad);
            return false;
        }
    }


    int iNumberOfElemsInSolution = iNumberOfSuppliers * iNumberOfFactories + iNumberOfFactories * iNumberOfMagazines +
                                   iNumberOfMagazines * iNumberOfShops;

    pdSolutionMinimalValues = new double[iNumberOfElemsInSolution];
    for (int i = 0; i < iNumberOfElemsInSolution; i++) {
        if (!feof(pfFileToLoad))fscanf(pfFileToLoad, "%lf", &pdSolutionMinimalValues[i]);
        else {
            fclose(pfFileToLoad);
            return false;
        }
    }
    pdSolutionMaximalValues = new double[iNumberOfElemsInSolution];
    for (int i = 0; i < iNumberOfElemsInSolution; i++) {
        if (!feof(pfFileToLoad))fscanf(pfFileToLoad, "%lf", &pdSolutionMaximalValues[i]);
        else {
            fclose(pfFileToLoad);
            return false;
        }
    }

    bFullyCreated = true;
    fclose(pfFileToLoad);
    return true;
}

bool CMscnProblem::bCheckSolution(vector<double> *pdSolution, string &err) {
    if (pdSolution == NULL) {
        err = "Array address is NULL";
        return false;
    }

    if ((iNumberOfSuppliers * iNumberOfFactories + iNumberOfFactories * iNumberOfMagazines +
         iNumberOfMagazines * iNumberOfShops) != pdSolution->size()) {
        err = "Wrong number of elements in the array";
        return false;
    }

    for (int i = 0; i < pdSolution->size(); i++) {
        if (pdSolution->at(i) < 0) {
            err = "One or more elements have a value less than 0";
            return false;
        }
    }

    return true;
}

double CMscnProblem::dNumberOfItemsFrom(vector<double> *pdSolution, int iStart, int iNumberOfElements) {
    double dNumberOfItemsFrom = 0;
    for (int j = 0; j < iNumberOfElements; j++) {
        dNumberOfItemsFrom += pdSolution->at(iStart + j);
    }
    return dNumberOfItemsFrom;
}

void CMscnProblem::destruct() {
    if (bFullyCreated) {

        if (ppdMatrixOfCostsSupplier_Factory != NULL) {
            for (int i = 0; i < iNumberOfSuppliers; i++) {
                if (ppdMatrixOfCostsSupplier_Factory[i] != NULL)delete[] ppdMatrixOfCostsSupplier_Factory[i];
            }
            delete[] ppdMatrixOfCostsSupplier_Factory;
        }
        if (ppdMatrixOfCostsFactory_Magazine) {
            for (int i = 0; i < iNumberOfFactories; i++) {
                if (ppdMatrixOfCostsFactory_Magazine[i]) delete[] ppdMatrixOfCostsFactory_Magazine[i];
            }
            delete[] ppdMatrixOfCostsFactory_Magazine;
        }

        if (ppdMatrixOfCostsMagazine_Shop) {
            for (int i = 0; i < iNumberOfMagazines; i++) {
                if (ppdMatrixOfCostsMagazine_Shop[i])delete[] ppdMatrixOfCostsMagazine_Shop[i];
            }
            delete[] ppdMatrixOfCostsMagazine_Shop;
        }

        if (pdArrayOfProductionCapacityOfSuppliers) delete[] pdArrayOfProductionCapacityOfSuppliers;
        if (pdArrayOfProductionCapacityOfFactories) delete[] pdArrayOfProductionCapacityOfFactories;
        if (pdArrayOfProductionCapacityOfMagazines) delete[] pdArrayOfProductionCapacityOfMagazines;
        if (pdArrayOfMarketDemandOfShops) delete[] pdArrayOfMarketDemandOfShops;

        if (pdOneTimeCostOfSuppliers) delete[] pdOneTimeCostOfSuppliers;
        if (pdOneTimeCostOfFactories) delete[] pdOneTimeCostOfFactories;
        if (pdOneTimeCostOfMagazines) delete[] pdOneTimeCostOfMagazines;

        if (pdIncomeForItemInShops) delete[] pdIncomeForItemInShops;

        if (pdSolutionMinimalValues) delete[] pdSolutionMinimalValues;
        if (pdSolutionMaximalValues) delete[] pdSolutionMaximalValues;


    }
    bFullyCreated = false;
}

//======================================================================================
//========================================List10========================================
//======================================================================================

void CMscnProblem::vGenerateInstance(int iInstanceSeed) {
    CRandom pcRand(iInstanceSeed);

    for (int i = 0; i < iNumberOfSuppliers; i++) {
        for (int j = 0; j < iNumberOfFactories; j++) {
            ppdMatrixOfCostsSupplier_Factory[i][j] = pcRand.dGetRandomDouble(dMinProductionCost, dMaxProductionCost);
        }
        pdArrayOfProductionCapacityOfSuppliers[i] = pcRand.dGetRandomDouble(dMinCapacityDemand, dMaxCapacityDemand);
        pdOneTimeCostOfSuppliers[i] = pcRand.dGetRandomDouble(dMinOneTimeCost, dMaxOneTimeCost);
    }

    for (int i = 0; i < iNumberOfFactories; i++) {
        for (int j = 0; j < iNumberOfMagazines; j++) {
            ppdMatrixOfCostsFactory_Magazine[i][j] = pcRand.dGetRandomDouble(dMinProductionCost, dMaxProductionCost);
        }

        pdArrayOfProductionCapacityOfFactories[i] = pcRand.dGetRandomDouble(dMinCapacityDemand, dMaxCapacityDemand);
        pdOneTimeCostOfFactories[i] = pcRand.dGetRandomDouble(dMinOneTimeCost, dMaxOneTimeCost);
    }

    for (int i = 0; i < iNumberOfMagazines; i++) {
        for (int j = 0; j < iNumberOfShops; j++) {
            ppdMatrixOfCostsMagazine_Shop[i][j] = pcRand.dGetRandomDouble(dMinProductionCost, dMaxProductionCost);
        }
        pdArrayOfProductionCapacityOfMagazines[i] = pcRand.dGetRandomDouble(dMinCapacityDemand, dMaxCapacityDemand);
        pdOneTimeCostOfMagazines[i] = pcRand.dGetRandomDouble(dMinOneTimeCost, dMaxOneTimeCost);
    }

    for (int i = 0; i < iNumberOfShops; i++) {

        pdArrayOfMarketDemandOfShops[i] = pcRand.dGetRandomDouble(dMinCapacityDemand, dMaxCapacityDemand);
        pdIncomeForItemInShops[i] = pcRand.dGetRandomDouble(dMinIncomeForItem, dMaxIncomeForItem);
    }

    int iResultQuantity = iNumberOfSuppliers * iNumberOfFactories + iNumberOfFactories * iNumberOfMagazines +
                          iNumberOfMagazines * iNumberOfShops;

    for (int i =0; i<iResultQuantity; i++){
        pdSolutionMinimalValues[i] = dDefaultMinimalValue;
        pdSolutionMaximalValues[i] = dDefaultMaximalValue;
    }
}

int CMscnProblem::iGetINumberOfSuppliers() const {
    return iNumberOfSuppliers;
}

int CMscnProblem::iGetINumberOfFactories() const {
    return iNumberOfFactories;
}

int CMscnProblem::iGetINumberOfMagazines() const {
    return iNumberOfMagazines;
}

int CMscnProblem::iGetINumberOfShops() const {
    return iNumberOfShops;
}

double *CMscnProblem::pdGetPdArrayOfProductionCapacityOfSuppliers() const {
    return pdArrayOfProductionCapacityOfSuppliers;
}

double *CMscnProblem::pdGetPdArrayOfProductionCapacityOfFactories() const {
    return pdArrayOfProductionCapacityOfFactories;
}

double *CMscnProblem::pdGetPdArrayOfProductionCapacityOfMagazines() const {
    return pdArrayOfProductionCapacityOfMagazines;
}

double *CMscnProblem::pdGetPdArrayOfMarketDemandOfShops() const {
    return pdArrayOfMarketDemandOfShops;
}

double *CMscnProblem::pdGetPdSolutionMinimalValues() const {
    return pdSolutionMinimalValues;
}

double *CMscnProblem::pdGetPdSolutionMaximalValues() const {
    return pdSolutionMaximalValues;
}
