#include "CRandomSearch.h"

CRandomSearch::CRandomSearch() {
    bHasProblem = false;
}

CRandomSearch::CRandomSearch(CMscnProblem *pcProblem) {
    this->pcProblem = pcProblem;
    bHasProblem = true;
}

void CRandomSearch::vSetProblem(CMscnProblem *pcProblem) {
    this->pcProblem = pcProblem;
    bHasProblem = true;
}

vector<double> *CRandomSearch::pcFindSolution(double dBreakPoint) {
    vector<double> *pdSolution = new vector<double>();
    CRandom cRandom;
    string err = "";

    do {
        pdSolution->clear();
        int iNumberOfSuppliers = pcProblem->iGetINumberOfSuppliers();
        int iNumberOfFactories = pcProblem->iGetINumberOfFactories();
        int iNumberOfMagazines = pcProblem->iGetINumberOfMagazines();
        int iNumberOfShops = pcProblem->iGetINumberOfShops();

        double *pdArrayOfProductionCapacityOfSuppliers = pcProblem->pdGetPdArrayOfProductionCapacityOfSuppliers();
        double *pdArrayOfProductionCapacityOfFactories = pcProblem->pdGetPdArrayOfProductionCapacityOfFactories();
        double *pdArrayOfProductionCapacityOfMagazines = pcProblem->pdGetPdArrayOfProductionCapacityOfMagazines();
        double *pdArrayOfMarketDemandOfShops = pcProblem->pdGetPdArrayOfMarketDemandOfShops();

        double *pdProductsFromSuppliers = new double[iNumberOfSuppliers];
        double *pdProductsFromFactories = new double[iNumberOfFactories];
        double *pdProductsFromMagazines = new double[iNumberOfMagazines];

        double *pdProductsToFactories = new double[iNumberOfFactories];
        double *pdProductsToMagazines = new double[iNumberOfMagazines];
        double *pdProductsToShops = new double[iNumberOfShops];

        for (int i = 0; i < iNumberOfSuppliers; i++) {
            pdProductsFromSuppliers[i] = 0;
        }

        for (int i = 0; i < iNumberOfFactories; i++) {
            pdProductsFromFactories[i] = 0;
            pdProductsToFactories[i] = 0;
        }

        for (int i = 0; i < iNumberOfMagazines; i++) {
            pdProductsFromMagazines[i] = 0;
            pdProductsToMagazines[i] = 0;
        }

        for (int i = 0; i < iNumberOfShops; i++) {
            pdProductsToShops[i] = 0;
        }

        double *pdSolutionMinimalValues = pcProblem->pdGetPdSolutionMinimalValues();

        double *pdSolutionMaximalValues = pcProblem->pdGetPdSolutionMaximalValues();

        int iCurrentCell = 0;

        for (int i = 0; i < iNumberOfSuppliers; i++) {
            for (int j = 0; j < iNumberOfFactories; j++) {
                double limits[] = {pdSolutionMaximalValues[iCurrentCell],
                                   pdArrayOfProductionCapacityOfSuppliers[i] - pdProductsFromSuppliers[i],
                                   pdArrayOfProductionCapacityOfFactories[j] - pdProductsToFactories[j]};
                double value = cRandom.dGetRandomDouble(pdSolutionMinimalValues[iCurrentCell], dFindMinimal(limits, 3));
                pdProductsFromSuppliers[i] += value;
                pdProductsToFactories[j] += value;
                pdSolution->push_back(value);
                iCurrentCell++;
            }
        }

        for (int i = 0; i < iNumberOfFactories; i++) {
            for (int j = 0; j < iNumberOfMagazines; j++) {
                double limits[] = {pdSolutionMaximalValues[iCurrentCell],
                                   pdProductsToFactories[i] - pdProductsFromFactories[i],
                                   pdArrayOfProductionCapacityOfFactories[i] - pdProductsFromFactories[i],
                                   pdArrayOfProductionCapacityOfMagazines[j] - pdProductsToMagazines[j]};
                double value = cRandom.dGetRandomDouble(pdSolutionMinimalValues[iCurrentCell], dFindMinimal(limits, 4));
                pdProductsFromFactories[i] += value;
                pdProductsToMagazines[j] += value;
                pdSolution->push_back(value);
                iCurrentCell++;
            }
        }

        for (int i = 0; i < iNumberOfMagazines; i++) {
            for (int j = 0; j < iNumberOfShops; j++) {
                double limits[] = {pdSolutionMaximalValues[iCurrentCell],
                                   pdProductsToMagazines[i] - pdProductsFromMagazines[i],
                                   pdArrayOfProductionCapacityOfMagazines[i] - pdProductsFromMagazines[i],
                                   pdArrayOfMarketDemandOfShops[j] - pdProductsToShops[j]};
                double value = cRandom.dGetRandomDouble(pdSolutionMinimalValues[iCurrentCell], dFindMinimal(limits, 4));
                pdProductsFromMagazines[i] += value;
                pdProductsToShops[j] += value;
                pdSolution->push_back(value);
                iCurrentCell++;
            }
        }

        delete[] pdProductsFromSuppliers;
        delete[] pdProductsFromFactories;
        delete[] pdProductsFromMagazines;

        delete[] pdProductsToFactories;
        delete[] pdProductsToMagazines;
        delete[] pdProductsToShops;

    } while (!pcProblem->bConstraintsSatisfied(pdSolution, err) ||
             pcProblem->dGetQuality(pdSolution, err) < dBreakPoint);

    for (int i = 0; i < pdSolution->size(); i++) {
        cout << pdSolution->at(i) << " ";
    }
    cout << endl;


    return pdSolution;
}


double CRandomSearch::dFindMinimal(double *pdNumbers, int iLength) {
    double min = pdNumbers[0];
    for (int i = 0; i < iLength; i++) {
        if (pdNumbers[i] < min) {
            min = pdNumbers[i];
        }
    }

    return min;
}
