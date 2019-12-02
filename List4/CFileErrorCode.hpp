#ifndef LIST4_CFILEERRORCODE_HPP
#define LIST4_CFILEERRORCODE_HPP

#include <atlstr.h>
#include <vector>

class CFileErrCode {
public:
    CFileErrCode();

    CFileErrCode(CString sFileName, bool &error);

    ~CFileErrCode();

    bool bOpenFile(CString sFileName);

    bool bCloseFile(CString sFileName);

    bool bPrintLine(CString sText);

    bool bPrintManyLines(std::vector<CString> sText);

private:
    FILE *pf_file;

};


#endif //LIST4_CFILEERRORCODE_HPP
