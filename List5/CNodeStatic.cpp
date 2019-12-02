#include "CNodeStatic.hpp"
#include <iostream>

using std::cout;

CNodeStatic::CNodeStatic() {
    i_val = 0;
    pc_parent_node = NULL;
}

CNodeStatic::~CNodeStatic() {}

void CNodeStatic::vSetValue(int iNewVal) {
    i_val = iNewVal;
}

int CNodeStatic::iGetChildrenNumber() {
    return (v_children.size());
}

void CNodeStatic::vPrint() {
    cout << " " << i_val;
}

void CNodeStatic::vAddNewChild() {
    CNodeStatic node;
    node.vSetParentNode(this);
    v_children.push_back(node);
}

CNodeStatic *CNodeStatic::pcGetChild(int iChildOffset) {
    if (iChildOffset < 0 || iChildOffset >= iGetChildrenNumber()) {
        return NULL;
    }
    return &v_children[iChildOffset];
}

void CNodeStatic::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        v_children[i].vPrintAllBelow();
    }
}

void CNodeStatic::vSetParentNode(CNodeStatic *pc_parent) {
    pc_parent_node = pc_parent;
}

void CNodeStatic::vPrintUp(){
    vPrint();
    if(pc_parent_node){
        pc_parent_node->vPrintUp();
    }
}

void CNodeStatic::vAddNewChild(CNodeStatic *pcNewChildNode){
    v_children.push_back(*pcNewChildNode);
}

CNodeStatic *CNodeStatic::pcGetParentNode(){
    return pc_parent_node;
}

int CNodeStatic::iFindChild(CNodeStatic *child) {
    for( int i = 0; i<iGetChildrenNumber(); i++){
        if(&v_children[i]==child){
            return i;
        }
    }
    return iGetChildrenNumber();
}

bool CNodeStatic::bMoveOut(int i) {
    if(i<iGetChildrenNumber()){
        v_children.erase(v_children.begin()+i);
        return true;
    }
    return false;
}
