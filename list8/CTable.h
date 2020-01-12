#ifndef LIST2_CTABLE_H
#define LIST2_CTABLE_H


#include <string>

using std::string;

class CTable {
private:
    string s_name;
    int *i_table;
    int i_table_length;
    int i_indicators;
    int i_invalid_iOffset = 0;
public:
    CTable();

    CTable(string sName, int iTableLen);

    CTable(CTable &pcOther);

    CTable(CTable &&pcOther);

    ~CTable();

    void vSetName(string sName);

    bool bSetNewSize(int iTableLen);

    CTable *pcClone();

    void increaseIndicator();

    void decreaseIndicator();

    int getIndicators();

    void vSetValueAt(int iOffset, int iNewVal);

    void vPrint();

    string sGetName();

    int iGetLength();

    int iGetValAt(int iOffset);

    CTable operator+(CTable &pcNewTab);

    int &operator()(int iOffset);
};


#endif //LIST2_CTABLE_H
