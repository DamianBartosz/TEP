#ifndef LIST9_CRANDOMSEARCH_H
#define LIST9_CRANDOMSEARCH_H


#include "CMscnProblem.h"

class CRandomSearch {
private:
    CMscnProblem *pcProblem;
    bool bHasProblem;

    double dFindMinimal(double *pdNumbers, int iLength);

public:
    CRandomSearch();

    CRandomSearch(CMscnProblem *pcProblem);

    ~CRandomSearch(){}

    void vSetProblem(CMscnProblem *pcProblem);

    vector<double> *pcFindSolution(int iIterationLimit);

};


#endif //LIST9_CRANDOMSEARCH_H
