#include <iostream>
#include "CTab.hpp"
#include "CTable.h"

using namespace std;

int main() {
    CTab pc_CTabTest1;
    CTab pc_CTabTest2 = std::move(pc_CTabTest1);
    CTab c_tab;
    c_tab = std::move(pc_CTabTest2);

    cout << endl << endl;

    CTable pc_CTableTest1;
    CTable pc_CTableTest2;
    CTable c_table = pc_CTableTest1 + pc_CTableTest2;

    return 0;
}
