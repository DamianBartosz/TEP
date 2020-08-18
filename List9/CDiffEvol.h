#ifndef LIST9_CDIFFEVOL_H
#define LIST9_CDIFFEVOL_H

#include "CIndividual.h"
#include "CRandom.hpp"

const int iDefaultQuantityOfIndividuals = 20;

class CDiffEvol {
private:
    vector<CIndividual*> *pcIndividuals;
    CMscnProblem *pcProblem;
    int iGenotypeSize;
    int iQuantityOfIndividuals;
    int iNumberOfRatings;
    int iLimit;
    const double dCrossProb = 0.6;
    const double dDiffWeight = 0.9;

    bool bCheckStopCondition();

    CIndividual *cGetRandomInd();

    bool bIndividualsAreDifferent(CIndividual *cInd, CIndividual *cBaseInd, CIndividual *cAddInd0, CIndividual *cAddInd1);

    double dFitness(CIndividual *cInd);

public:
    CDiffEvol(CMscnProblem *pcProblem);

    CDiffEvol(int iQuantityOfIndividuals, CMscnProblem *pcProblem);

    CDiffEvol(vector<double> **ppdInitSolutions, int iQuantityOfIndividuals, CMscnProblem *pcProblem);

    ~CDiffEvol();

    void pcStartToEvole(int iLimit);

    vector<double> *pdGetBestSolution();
};


#endif //LIST9_CDIFFEVOL_H
