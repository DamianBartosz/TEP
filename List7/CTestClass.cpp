#include "CTestClass.h"
#include <iostream>

using namespace std;

CTestClass::CTestClass() {
    v = iVersion;
    cout << "Construct object nr " << v << endl;
    iVersion++;
}

CTestClass::~CTestClass() {
    cout << "Destruct object nr " << v << endl;
}

int CTestClass::iGetV() {
    return v;
}
