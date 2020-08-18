#include "CIndividual.h"

CIndividual::CIndividual(CMscnProblem *pcProblem) {
    this->pcProblem = pcProblem;
    CRandomSearch cRandomSearch = CRandomSearch(pcProblem);
    pdGenotype = cRandomSearch.pcFindSolution(1);
}

CIndividual::CIndividual(vector<double> *pdGenotype, CMscnProblem *pcProblem) {
    this->pdGenotype = pdGenotype;
    this->pcProblem = pcProblem;
    string err;
    if (!pcProblem->bConstraintsSatisfied(pdGenotype, err)) {
        vRepairGenotype();
    }
}

CIndividual::~CIndividual() {
    delete pdGenotype;
}

double &CIndividual::at(int i) {
    return pdGenotype->at(i);
}

void CIndividual::vRepairGenotype() {
    CRandomSearch cRandomSearch;
    cRandomSearch.pcFindSolution(1);
}

bool CIndividual::equals(CIndividual *cInd) {
    int iGenotypeSize = pcProblem->iGetSolutionSize();
    for (int i = 0; i < iGenotypeSize; i++) {
        if (pdGenotype->at(i) != cInd->pdGenotype->at(i)) return false;
    }
    return true;
}

