//
// Created by Damian on 16.01.2020.
//

#ifndef LIST9_CINDIVIDUAL_H
#define LIST9_CINDIVIDUAL_H


#include "CMscnProblem.h"
#include "CRandomSearch.h"

class CIndividual {
private:
    int iNumberOfRatings = 0;
    vector<double> *pdGenotype;
    CMscnProblem *pcProblem;

    CIndividual(CMscnProblem *pcProblem);

    CIndividual(vector<double> *pdGenotype, CMscnProblem *pcProblem);

    friend class CDiffEvol;

public:
    virtual ~CIndividual();

    double &operator[](int i);

    void vRepairGenotype();

};


#endif //LIST9_CINDIVIDUAL_H
