#include "CTestClass.h"
#include "CMySmartPointer.h"

int main() {
//    CTestClass pc_test;
//    CMySmartPointer<CTestClass> *pc_smartPointer1 = new CMySmartPointer<CTestClass>(&pc_test);
    CMySmartPointer<CTestClass> *pc_smartPointer1 = new CMySmartPointer<CTestClass>(new CTestClass);
    CMySmartPointer<CTestClass> *pc_smartPointer2 = new CMySmartPointer<CTestClass>(*pc_smartPointer1);
    CMySmartPointer<CTestClass> *pc_smartPointer3 = new CMySmartPointer<CTestClass>(new CTestClass);
    *pc_smartPointer1 = *pc_smartPointer3;
    *pc_smartPointer2 = *pc_smartPointer3;

    delete pc_smartPointer1;
    delete pc_smartPointer2;
    delete pc_smartPointer3;
}
