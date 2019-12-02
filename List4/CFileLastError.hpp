#ifndef LIST4_CFILELASTERROR_HPP
#define LIST4_CFILELASTERROR_HPP

#include <cstdio>
#include <atlstr.h>
#include <vector>

using namespace std;

class CFileLastError {
private:
    static bool b_last_error;
public:
    static bool bGetLastError() {
        return b_last_error;
    }

    CFileLastError();

    CFileLastError(CString sFileName);

    ~CFileLastError();

    void vOpenFile(CString sFileName);

    void vCloseFile();

    void vPrintLine(CString sText);

    void vPrintManyLines(vector<CString> sText);

private:
    FILE *pf_file;
};


#endif //LIST4_CFILELASTERROR_HPP
