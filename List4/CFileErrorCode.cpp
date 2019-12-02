#include "CFileErrorCode.hpp"

CFileErrCode::CFileErrCode() : pf_file(NULL) {}

CFileErrCode::CFileErrCode(CString sFileName, bool &error) : pf_file(NULL) {
    pf_file = fopen(sFileName, "w+");
    if (pf_file == NULL) {
        error = true;
    }
}

CFileErrCode::~CFileErrCode() {
    if (pf_file != NULL) {
        fclose(pf_file);
    }
}

bool CFileErrCode::bOpenFile(CString sFileName) {
    if (pf_file) {
        return true;
    }
    pf_file = fopen(sFileName, "w+");
    return !pf_file;
}

bool CFileErrCode::bCloseFile(CString sFileName) {
    if (!pf_file) {
        return true;
    }
    fclose(pf_file);
    return false;
}

bool CFileErrCode::bPrintLine(CString sText) {
    if (pf_file == NULL) {
        return true;
    }
    fprintf(pf_file, sText);
    return false;
}

bool CFileErrCode::bPrintManyLines(std::vector<CString> sText) {
    for (int i = 0; i < sText.size(); i++) {
        if (bPrintLine(sText[i])) return true;
    }
    return false;
}
