#ifndef LIST7_CTESTCLASS_H
#define LIST7_CTESTCLASS_H

int static iVersion = 1;

class CTestClass {
public:
    CTestClass();

    ~CTestClass();

    int iGetV();

private:
    int v;
};


#endif //LIST7_CTESTCLASS_H
