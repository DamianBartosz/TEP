#ifndef LIST9_CINDIVIDUAL_H
#define LIST9_CINDIVIDUAL_H


#include "CMscnProblem.h"
#include "CRandomSearch.h"

class CIndividual {
private:
    vector<double> *pdGenotype;
    CMscnProblem *pcProblem;

    CIndividual(CMscnProblem *pcProblem);

    CIndividual(vector<double> *pdGenotype, CMscnProblem *pcProblem);

    void vRepairGenotype();

    double &at(int i);

    bool equals(CIndividual *cInd);

    friend class CDiffEvol;

public:
    virtual ~CIndividual();
};


#endif //LIST9_CINDIVIDUAL_H
