#ifndef LIST5_CNODESTATIC_HPP
#define LIST5_CNODESTATIC_HPP

#include <vector>
//#include "CTreeStatic.hpp"

using std::vector;

class CNodeStatic {
public:
    CNodeStatic();

    ~CNodeStatic();

    void vSetValue(int iNewVal);

    int iGetChildrenNumber();

    void vAddNewChild();

    void vAddNewChild(CNodeStatic *pcNewChildNode);

    CNodeStatic *pcGetChild(int iChildOffset);

    void vPrint();

    void vPrintAllBelow();

    void vSetParentNode(CNodeStatic *pc_parent);

    CNodeStatic *pcGetParentNode();

    void vPrintUp();

    int iFindChild(CNodeStatic *child);

    bool bMoveOut(int i);

private:
    vector<CNodeStatic> v_children;
    CNodeStatic *pc_parent_node;
    int i_val;
};


#endif //LIST5_CNODESTATIC_HPP
