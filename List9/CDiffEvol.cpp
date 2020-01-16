//
// Created by Damian on 16.01.2020.
//

#include "CDiffEvol.h"


CDiffEvol::CDiffEvol() {
    iQuantityOfInviduals = iDefaultQuantityOfIndividuals;
    ppcIndividuals = new CIndividual[iQuantityOfInviduals];
}

CDiffEvol::CDiffEvol(int iQuantityOfInviduals) {

}

CDiffEvol::CDiffEvol(vector<double> **ppdInitSolutions, int iQuantityOfInviduals) {

}
