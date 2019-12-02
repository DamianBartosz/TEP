#include "CTreeStatic.hpp"

CTreeStatic::CTreeStatic() {}

CTreeStatic::~CTreeStatic() {}

CNodeStatic *CTreeStatic::pcGetRoot() {
    return (&c_root);
}

void CTreeStatic::vPrintTree(){
    c_root.vPrintAllBelow();
}

bool CTreeStatic::bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode){
    pcParentNode->vAddNewChild(pcNewChildNode);
    CNodeStatic parent =*pcNewChildNode->pcGetParentNode();
    return parent.bMoveOut(parent.iFindChild(pcNewChildNode));
}

