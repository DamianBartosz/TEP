#ifndef LIST5_CNODEDYNAMIC_HPP
#define LIST5_CNODEDYNAMIC_HPP

#include <vector>

using namespace std;

template<typename T>
class CNodeDynamic {
public:
    CNodeDynamic();

    CNodeDynamic(CNodeDynamic<T> *parent);

    ~CNodeDynamic();

    void vSetValue(T iNewVal);

    int iGetChildrenNumber();

    void vAddNewChild();

    void vAddNewChild(CNodeDynamic<T> *pcNewChildNode);


    CNodeDynamic<T> *pcGetChild(int iChildOffset);

    void vPrint();

    void vPrintAllBelow();

    int iFindChild(CNodeDynamic<T> *child);

    bool bMoveOut(int i);

    CNodeDynamic<T> *pcGetParentNode();

private:
    vector<CNodeDynamic<T> *> v_children;
    CNodeDynamic<T> *pc_parent_node;
    T t_val;
};


using namespace std;

template<typename T>
CNodeDynamic<T>::CNodeDynamic() {
    pc_parent_node = NULL;
};

template<typename T>
CNodeDynamic<T>::CNodeDynamic(CNodeDynamic<T> *parent) {
    pc_parent_node = parent;
}

template<typename T>
CNodeDynamic<T>::~CNodeDynamic() {
    for (int i = 0; i < v_children.size(); i++) {
        delete v_children[i];
    }
}

template<typename T>
void CNodeDynamic<T>::vSetValue(T iNewVal) {
    t_val = iNewVal;
}

template<typename T>
int CNodeDynamic<T>::iGetChildrenNumber() {
    return (v_children.size());
}

template<typename T>
void CNodeDynamic<T>::vAddNewChild() {
    v_children.push_back(new CNodeDynamic(this));
}

template<typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcGetChild(int iChildOffset) {
    if (iChildOffset < 0 || iChildOffset >= v_children.size()) {
        return NULL;
    }
    return v_children[iChildOffset];
}

template<typename T>
void CNodeDynamic<T>::vPrint() {
    cout << " " << t_val;
}

template<typename T>
void CNodeDynamic<T>::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < v_children.size(); i++) {
        v_children[i]->vPrintAllBelow();
    }
}

template<typename T>
int CNodeDynamic<T>::iFindChild(CNodeDynamic<T> *child) {
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        if (v_children[i] == child) {
            return i;
        }
    }
    return iGetChildrenNumber();
}

template<typename T>
void CNodeDynamic<T>::vAddNewChild(CNodeDynamic<T> *pcNewChildNode) {
    v_children.push_back(pcNewChildNode);
}

template<typename T>
bool CNodeDynamic<T>::bMoveOut(int i) {
    if (i < iGetChildrenNumber()) {
        v_children.erase(v_children.begin() + i);
        return true;
    }
    return false;
}

template<typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcGetParentNode() {
    return pc_parent_node;
}


#endif //LIST5_CNODEDYNAMIC_HPP
