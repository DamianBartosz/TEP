#include "consts.hpp"
#include <xstring>
#include <iostream>
#include "CTable.h"

using std::string;
using std::cout;
using std::endl;


CTable::CTable() {
    s_name = s_default_name;
    cout << "bezp: '" + s_name + "'" << endl;
    i_table_length = i_default_table_length;
    i_table = new int[i_table_length];
    i_indicators = 1;
}

CTable::CTable(string sName, int iTableLen) {
    if (iTableLen < 1) {
        iTableLen = 1;
    }
    s_name = sName;
    cout << "parametr: '" + s_name + "'" << endl;
    i_table_length = iTableLen;
    i_table = new int[i_table_length];
    i_indicators = 1;
}

CTable::CTable(CTable &pcOther) {
    s_name = pcOther.s_name + "_copy";
    cout << "kopiuj: '" + s_name + "'" << endl;
    i_table_length = pcOther.i_table_length;
    i_table = new int[i_table_length];
    for (int i = 0; i < pcOther.i_table_length; i++) {
        i_table[i] = pcOther.i_table[i];
    }
    i_indicators = 1;
}

CTable::CTable(CTable &&pcOther) {
    s_name = pcOther.s_name;
    cout<<"move: '" + s_name + "'"<<endl;
    i_table_length = pcOther.i_table_length;
    i_table = pcOther.i_table;
    pcOther.i_table = NULL;
    i_indicators = pcOther.i_indicators;
}

CTable::~CTable() {
    if(i_table!=NULL) {
        delete[] i_table;
    }
    cout << "usuwam: '" + s_name + "'" << endl;
}

void CTable::vSetName(string sName) {
    s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
    if (iTableLen < 1) {
        return false;
    }
    int *i_table_new = new int[iTableLen];

    for (int i = 0; i < iTableLen && i < i_table_length; i++) {
        i_table_new[i] = i_table[i];
    }

    delete[] i_table;
    i_table = i_table_new;
    i_table_length = iTableLen;
    return true;
}

CTable *CTable::pcClone() {
    return new CTable(*this);
}

void CTable::increaseIndicator() {
    i_indicators++;
}

void CTable::decreaseIndicator() {
    i_indicators--;
}

int CTable::getIndicators() {
    return i_indicators;
}


void CTable::vSetValueAt(int iOffset, int iNewVal) {
    if (iOffset < 0 || iOffset >= i_table_length) {
        return;
    }
    i_table[iOffset] = iNewVal;
}

void CTable::vPrint() {
    for (int i = 0; i < i_table_length; i++) {
        cout << i_table[i] << ", ";
    }
    cout << endl;
}

string CTable::sGetName() {
    return s_name;
}

int CTable::iGetLength() {
    return i_table_length;
}

int CTable::iGetValAt(int iOffset) {
    if (iOffset < 0 || iOffset >= i_table_length) {
        return 0;
    }
    return i_table[iOffset];
}

CTable CTable::operator+(CTable &pcNewTab) {
    CTable c_tab_new;
    c_tab_new.vSetName("Concat " + s_name + " and " + pcNewTab.sGetName());
    c_tab_new.bSetNewSize(i_table_length + pcNewTab.iGetLength());
    for (int i = 0; i < i_table_length; i++) {
        c_tab_new.vSetValueAt(i, i_table[i]);
    }
    for (int i = 0; i < pcNewTab.iGetLength(); i++) {
        c_tab_new.vSetValueAt(i + i_table_length, pcNewTab.iGetValAt(i));
    }
    return std::move(c_tab_new);
}

int &CTable::operator()(int iOffset) {
    if (iOffset < 0 || iOffset >= i_table_length) {
        return i_invalid_iOffset;
    }
    return i_table[iOffset];
}
