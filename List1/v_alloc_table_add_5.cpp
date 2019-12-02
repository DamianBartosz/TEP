#include <iostream>
#include "consts.h"

using std::cout;

void v_alloc_table_add_5(int iSize) {
    if (iSize < 1) {
        return;
    }
    int *table = new int[iSize];
    for (int i = 0; i < iSize; i++) {
        table[i] = i + ADD_VAL;
    }

    for (int i = 0; i < iSize; i++) {
        cout << table[i] << " ";
    }

    delete[] table;
}