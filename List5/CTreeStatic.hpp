#ifndef LIST5_CTREESTATIC_HPP
#define LIST5_CTREESTATIC_HPP

#include "CNodeStatic.hpp"

class CTreeStatic {
public:
    CTreeStatic();

    ~CTreeStatic();

    CNodeStatic *pcGetRoot();

    void vPrintTree();

    bool bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode);

private:
    CNodeStatic c_root;
};


#endif //LIST5_CTREESTATIC_HPP
