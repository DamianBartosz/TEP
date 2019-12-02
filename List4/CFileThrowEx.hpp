#ifndef LIST4_CFILETHROWEX_HPP
#define LIST4_CFILETHROWEX_HPP

#include <atlstr.h>
#include <vector>

using namespace std;

class CFileThrowEx {
public:
    CFileThrowEx();

    CFileThrowEx(CString sFileName);

    ~CFileThrowEx();

    void vOpenFile(CString sFileName);

    void vCloseFile();

    void vPrintLine(CString sText);

    void vPrintManyLines(vector<CString> sText);

private:
    FILE *pf_file;
};


#endif //LIST4_CFILETHROWEX_HPP
