#include "CTable.h"
#include "consts.hpp"
#include "CTableShallow.h"
#include "proc.hpp"
#include <iostream>

using namespace std;

int main() {
    CTable c_tab_0, c_tab_1;
    c_tab_0.bSetNewSize(i_tab_0_len);
    c_tab_1.bSetNewSize(i_tab_1_len);

    //intitialize table
    for (int i = 0; i < i_tab_0_len; i++) {
        c_tab_0.vSetValueAt(i, i + 1);
    }

    for (int i = 0; i < i_tab_1_len; i++) {
        c_tab_1.vSetValueAt(i, i + 1);
    }
    //end of initialization

    (c_tab_0 + c_tab_1).vPrint();

    int element = c_tab_0(4);
    c_tab_0(1) = 3;

    cout << element << " " << c_tab_0(1) << endl;
}
