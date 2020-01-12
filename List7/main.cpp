#include "CTestClass.h"
#include "CMySmartPointer.h"

#include <iostream>

using namespace std;

int main() {
    CMySmartPointer<CTestClass> pc_smartPointer1(new CTestClass);
    CMySmartPointer<CTestClass> pc_smartPointer2(pc_smartPointer1);
    CMySmartPointer<CTestClass> pc_smartPointer3(new CTestClass);
    pc_smartPointer1 = pc_smartPointer3;
    pc_smartPointer2 = pc_smartPointer3;

    CTestClass *test1 = pc_smartPointer1.release();
    cout<<test1->iGetV()<<endl;
    CMySmartPointer<CTestClass> pc_smartPointer4 = pc_smartPointer1.deepCopy();
    delete test1;
}
