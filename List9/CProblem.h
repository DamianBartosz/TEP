//
// Created by Damian on 12.01.2020.
//

#ifndef LIST9_CPROBLEM_H
#define LIST9_CPROBLEM_H

#include <vector>

using namespace std;

class CProblem {
 virtual void vGenerateInstance(int iInstanceSeed);
 virtual bool bConstraintsSatisfied(vector<double> *pdSolution, string &err);
};


#endif //LIST9_CPROBLEM_H
