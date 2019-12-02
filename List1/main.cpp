#include "functions.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
    v_alloc_table_add_5(10);

    int **piTable = 0;

    if (b_alloc_table_2_dim(&piTable, 5, 10)) {
        cout << "\nAlokacja przebiegla pomyslnie";
    } else {
        cout << "\nProblem z alokacja";
    }

    if (b_dealloc_table_2_dim(&piTable, 5)) {
        cout << "\nDealokacja przebiegla pomyslnie";
    } else {
        cout << "\nProblem z dealokacja";
    }
}