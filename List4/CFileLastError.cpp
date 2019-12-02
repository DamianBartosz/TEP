#include "CFileLastError.hpp"

bool CFileLastError::b_last_error = false;

CFileLastError::CFileLastError() : pf_file(NULL) {
    b_last_error = false;
}

CFileLastError::CFileLastError(CString sFileName) : pf_file(NULL) {

    b_last_error = false;
    pf_file = fopen(sFileName, "w+");
    if (pf_file == NULL) {
        b_last_error = true;
    }

}

CFileLastError::~CFileLastError() {
    if (pf_file != NULL) {
        fclose(pf_file);
    }
}

void CFileLastError::vOpenFile(CString sFileName) {
    b_last_error = false;
    if (pf_file) {
        b_last_error = true;
        return;
    }
    pf_file = fopen(sFileName, "w+");
    if (!pf_file) {
        b_last_error = true;
        return;
    }
}

void CFileLastError::vCloseFile() {
    b_last_error = false;
    if (!pf_file) {
        b_last_error = true;
        return;
    }
    fclose(pf_file);
}

void CFileLastError::vPrintLine(CString sText) {
    b_last_error = false;
    if (pf_file == NULL) {
        b_last_error = true;
        return;
    }
    fprintf(pf_file, sText);
}

void CFileLastError::vPrintManyLines(vector<CString> sText) {
    b_last_error = false;
    for (int i = 0; i < sText.size(); i++) {
        vPrintLine(sText[i]);
        if (!bGetLastError()) {
            return;
        }
    }
}


