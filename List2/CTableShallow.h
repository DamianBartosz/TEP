
#ifndef LIST2_CTABLESHALLOW_H
#define LIST2_CTABLESHALLOW_H


#include "CTable.h"

class CTableShallow {
private:
    CTable *m_tab;
public:
    CTableShallow(int tabSize);

    CTableShallow();

    CTableShallow(const CTableShallow &other);

    ~CTableShallow();
};


#endif //LIST2_CTABLESHALLOW_H
