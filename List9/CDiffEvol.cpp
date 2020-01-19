//
// Created by Damian on 16.01.2020.
//

#include "CDiffEvol.h"

CDiffEvol::CDiffEvol(CMscnProblem* pcProblem) {
	this->pcProblem = pcProblem;
	iGenotypeSize = pcProblem->iGetSolutionSize();
	iQuantityOfIndividuals = iDefaultQuantityOfIndividuals;
	pcIndividuals = new vector<CIndividual*>();
	for (int i = 0; i < iQuantityOfIndividuals; i++) {
		pcIndividuals->push_back(new CIndividual(this->pcProblem));
	}
}

CDiffEvol::CDiffEvol(int iQuantityOfIndividuals, CMscnProblem* pcProblem) {
	this->pcProblem = pcProblem;
	iGenotypeSize = pcProblem->iGetSolutionSize();
	this->iQuantityOfIndividuals = iQuantityOfIndividuals;
	pcIndividuals = new vector<CIndividual*>();
	for (int i = 0; i < iQuantityOfIndividuals; i++) {
		pcIndividuals->push_back(new CIndividual(this->pcProblem));
	}
}

CDiffEvol::CDiffEvol(vector<double>** ppdInitSolutions, int iQuantityOfIndividuals, CMscnProblem* pcProblem) {
	this->pcProblem = pcProblem;
	iGenotypeSize = pcProblem->iGetSolutionSize();
	this->iQuantityOfIndividuals = iQuantityOfIndividuals;
	pcIndividuals = new vector<CIndividual*>();
	for (int i = 0; i < iQuantityOfIndividuals; i++) {
		pcIndividuals->push_back(new CIndividual(ppdInitSolutions[i], this->pcProblem));
	}
}

CDiffEvol::~CDiffEvol() {
	delete pcIndividuals;
}

void CDiffEvol::pcStartToEvole(int iLimit) {
	CRandom cRand;
	this->iLimit = iLimit;
	while (bCheckStopCondition()) {
	    cout<<"okok"<<endl<<endl;
		for (int i = 0; i < iQuantityOfIndividuals; i++) {
			CIndividual* cBaseInd = cGetRandomInd();
			CIndividual* cAddInd0 = cGetRandomInd();
			CIndividual* cAddInd1 = cGetRandomInd();
			if (bIndividualsAreDifferent(pcIndividuals->at(i), cBaseInd, cAddInd0, cAddInd1)) {
				CIndividual* indNew = new CIndividual(pcProblem);
				for (int iGeneOffset = 0; iGeneOffset < iGenotypeSize; iGeneOffset++) {
					if (cRand.dGetRandomDouble(0, 1) < dCrossProb) {
						indNew->at(iGeneOffset) =
							cBaseInd->at(iGeneOffset) +
							dDiffWeight * (cAddInd0->at(iGeneOffset) - cAddInd1->at(iGeneOffset));
					}
					else indNew->at(iGeneOffset) = pcIndividuals->at(i)->at(iGeneOffset);
				}
				string err;
				if (pcProblem->bConstraintsSatisfied(indNew->pdGenotype, err) &&dFitness(indNew) >= dFitness(pcIndividuals->at(i))) {
					delete pcIndividuals->at(i);
					pcIndividuals->at(i) = indNew;
				}
				else {
					delete indNew;
				}
			}
		}
	}
}

vector<double> *CDiffEvol::pdGetBestSolution() {
	vector<double>* pdBestSolution;
	pdBestSolution = pcIndividuals->at(0)->pdGenotype;
	string err;
	double dBestResult = pcProblem->dGetQuality(pdBestSolution, err);
	for (int i = 1; i < iQuantityOfIndividuals; i++) {
		vector<double>* pdCurrentSolution = pcIndividuals->at(i)->pdGenotype;
		double dCurrentResult = pcProblem->dGetQuality(pdCurrentSolution, err);
		if (dCurrentResult > dBestResult) {
			pdBestSolution = pdCurrentSolution;
			dBestResult = dCurrentResult;
		}
	}

	vector<double> *pdBestSolutionCopy = new vector<double>();
	for (int i = 0; i < iGenotypeSize; i++) {
		pdBestSolutionCopy->push_back(pdBestSolution->at(i));
	}
	return pdBestSolutionCopy;
}

bool CDiffEvol::bCheckStopCondition() {
	return iNumberOfRatings < iLimit;
}

CIndividual* CDiffEvol::cGetRandomInd() {
	CRandom cRand;
	return pcIndividuals->at(cRand.iGetRandomInteger(0, iQuantityOfIndividuals - 1));
}

bool CDiffEvol::bIndividualsAreDifferent(CIndividual* cInd, CIndividual* cBaseInd, CIndividual* cAddInd0,
	CIndividual* cAddInd1) {
	if (cInd->equals(cBaseInd)) return false;
	if (cInd->equals(cAddInd0)) return false;
	if (cInd->equals(cAddInd1)) return false;

	if (cBaseInd->equals(cAddInd0)) return false;
	if (cBaseInd->equals(cAddInd1)) return false;

	return !cAddInd0->equals(cAddInd1);

}

double CDiffEvol::dFitness(CIndividual* cInd) {
	iNumberOfRatings++;
	string err;
	return pcProblem->dGetQuality(cInd->pdGenotype, err);
}
