#include "CTable.h"
#include <iostream>

using namespace std;

void v_mod_tab(CTable *pcTab, int iNewSize) {
    pcTab->bSetNewSize(iNewSize);
    cout << pcTab << endl;
}

void v_mod_tab(CTable cTab, int iNewSize) {
    cTab.bSetNewSize(iNewSize);
    cout << &cTab << endl;
}