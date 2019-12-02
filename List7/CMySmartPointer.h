#ifndef LIST7_CMYSMARTPOINTER_H
#define LIST7_CMYSMARTPOINTER_H

#include "CRefCounter.h"
#include <iostream>

using namespace std;

template<typename T>
class CMySmartPointer {
public:
    CMySmartPointer(T *pcPointer);

    CMySmartPointer(const CMySmartPointer &pcOther);

    ~CMySmartPointer();

    T &operator*();

    T *operator->();

    void operator=(CMySmartPointer &pcOther);

private:
    CRefCounter *pc_counter;
    T *pc_pointer;

    void vDeletePointer();

    void vCopyPointer(const CMySmartPointer &pcOther);
};//class CMySmartPointer

template<typename T>
CMySmartPointer<T>::CMySmartPointer(T *pcPointer) {
    pc_pointer = pcPointer;
    pc_counter = new CRefCounter();
    pc_counter->iAdd();
}//CMySmartPointer(CSellData *pcPointer)

template<typename T>
CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer &pcOther) {
    vCopyPointer(pcOther);
    cout << "Copying constructor of CMySmartPointer" << endl;
}//CMySmartPointer(const CMySmartPointer &pcOther)

template<typename T>
CMySmartPointer<T>::~CMySmartPointer() {
    vDeletePointer();
}//~CMySmartPointer()

template<typename T>
T &CMySmartPointer<T>::operator*() { return (*pc_pointer); }

template<typename T>
T *CMySmartPointer<T>::operator->() { return (pc_pointer); }

template<typename T>
void CMySmartPointer<T>::operator=(CMySmartPointer &pcOther) {
    vDeletePointer();
    vCopyPointer(pcOther);
}//operator=(const CMySmartPointer &pcOther)

template<typename T>
void CMySmartPointer<T>::vDeletePointer() {
    if (pc_counter->iDec() == 0) {
        delete pc_pointer;
        delete pc_counter;
    }//if (pc_counter->iDec())
}//vDeletePointer()

template<typename T>
void CMySmartPointer<T>::vCopyPointer(const CMySmartPointer &pcOther) {
    pc_pointer = pcOther.pc_pointer;
    pc_counter = pcOther.pc_counter;
    pc_counter->iAdd();
}//vCopyPointer(const CMySmartPointer &pcOther)

#endif //LIST7_CMYSMARTPOINTER_H
