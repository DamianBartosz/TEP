#include <iostream>
#include "CTreeDynamic.hpp"
#include "CNodeDynamic.hpp"

using namespace std;

void v_tree_test() {
    CTreeDynamic<string> *c_tree = new CTreeDynamic<string>();
    CNodeDynamic<string> *c_root = c_tree->pcGetRoot();
    c_root->vAddNewChild();
    c_root->vAddNewChild();
    c_root->pcGetChild(0)->vSetValue("1");
    c_root->pcGetChild(1)->vSetValue("2");
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->pcGetChild(0)->vSetValue("11");
    c_root->pcGetChild(0)->pcGetChild(1)->vSetValue("12");
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->pcGetChild(0)->vSetValue("21");
    c_root->pcGetChild(1)->pcGetChild(1)->vSetValue("22");
    c_root->vPrintAllBelow();
    cout << endl;
    c_tree->vPrintTree();
    cout<<endl;
    c_tree->bMoveSubtree(c_root->pcGetChild(1), c_root->pcGetChild(0));
}

int main() {
    v_tree_test();
}