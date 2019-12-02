#ifndef LIST5_CNODESTATIC_HPP
#define LIST5_CNODESTATIC_HPP

#include <vector>

using std::vector;

class CNodeStatic {
public:
    CNodeStatic();

    ~CNodeStatic();

    void vSetValue(int iNewVal);

    int iGetChildrenNumber();

    void vAddNewChild();

    CNodeStatic *pcGetChild(int iChildOffset);

    void vPrint();

    void vPrintAllBelow();

private:
    vector <CNodeStatic> v_children;
    CNodeStatic *pc_parent_node;
    int i_val;
};


#endif //LIST5_CNODESTATIC_HPP
