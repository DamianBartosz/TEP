#ifndef LIST5_CTREEDYNAMIC_HPP
#define LIST5_CTREEDYNAMIC_HPP

#include "CNodeDynamic.hpp"

template <typename T> class CTreeDynamic {
public:
    CTreeDynamic();

    CTreeDynamic(CNodeDynamic<T>* root);

    ~CTreeDynamic();

    CNodeDynamic<T> *pcGetRoot();

    void vPrintTree();

    bool bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode);
private:
    CNodeDynamic<T> *pc_root;
};

template <typename T>
CTreeDynamic<T>::CTreeDynamic(){
    pc_root = new CNodeDynamic<T>();
}

template <typename T>
CTreeDynamic<T>::CTreeDynamic(CNodeDynamic<T>* root){
    pc_root = root;
}

template <typename T>
CTreeDynamic<T>::~CTreeDynamic(){
    delete pc_root;
}

template <typename T>
CNodeDynamic<T> *CTreeDynamic<T>::pcGetRoot() {
    return (pc_root);
}

template <typename T>
void CTreeDynamic<T>::vPrintTree(){
    pc_root->vPrintAllBelow();
}

template <typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode){
    pcParentNode->vAddNewChild(pcNewChildNode);
    CNodeDynamic<T> parent =*pcNewChildNode->pcGetParentNode();
    return (parent.bMoveOut(parent.iFindChild(pcNewChildNode)));
}

#endif //LIST5_CTREEDYNAMIC_HPP
