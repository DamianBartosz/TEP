//
// Created by Damian on 16.01.2020.
//

#include "CIndividual.h"

CIndividual::CIndividual(CMscnProblem *pcProblem) {
    this->pcProblem = pcProblem;
    CRandomSearch cRandomSearch;
    while (!pdGenotype) {
        pdGenotype = cRandomSearch.pcFindSolution(1);
    }
}

CIndividual::CIndividual(vector<double> *pdGenotype, CMscnProblem *pcProblem) {
    this->pdGenotype = pdGenotype;
    this->pcProblem = pcProblem;
    string err;
    if(!pcProblem->bConstraintsSatisfied(pdGenotype, err)){
        vRepairGenotype();
    }
}

CIndividual::~CIndividual() {
    delete pcProblem;
    delete pdGenotype;
}

double &CIndividual::operator[](int i) {
    return pdGenotype->at(i);
}

void CIndividual::vRepairGenotype() {
    CRandomSearch cRandomSearch;
    cRandomSearch.pcCheckSolution(pdGenotype, true); 
}

