#include "consts.hpp"
#include "CTable.h"
#include <iostream>
#include "CTableShallow.h"

using namespace std;

CTable CTableShallow::*m_tab;

CTableShallow::CTableShallow(int tabSize) {
    m_tab = new CTable(s_default_name, tabSize);
}

CTableShallow::CTableShallow() {
    m_tab = new CTable();
}

CTableShallow::CTableShallow(const CTableShallow &other) {
    m_tab = other.m_tab;
    m_tab->increaseIndicator();
}

CTableShallow::~CTableShallow() {
    m_tab->decreaseIndicator();
    if (m_tab->getIndicators() == 0) {
        delete m_tab;
        cout << "Usuwam CTable" << endl;
    }
    cout << "Usuwam CTableShallow" << endl;
}

