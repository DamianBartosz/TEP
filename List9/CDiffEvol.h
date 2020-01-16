//
// Created by Damian on 16.01.2020.
//

#ifndef LIST9_CDIFFEVOL_H
#define LIST9_CDIFFEVOL_H

#include "CIndividual.h"

const int iDefaultQuantityOfIndividuals = 50;

class CDiffEvol {
private:
    CIndividual **ppcIndividuals;
    int iQuantityOfInviduals;
public:
    CDiffEvol();

    CDiffEvol(int iQuantityOfInviduals);

    CDiffEvol(vector<double> **ppdInitSolutions, int iQuantityOfInviduals);
};


#endif //LIST9_CDIFFEVOL_H
