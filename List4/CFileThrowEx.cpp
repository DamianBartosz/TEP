#include "CFileThrowEx.hpp"

CFileThrowEx::CFileThrowEx():pf_file(NULL)  {}

CFileThrowEx::CFileThrowEx(CString sFileName):pf_file(NULL)  {
    pf_file = fopen(sFileName, "w+");
    if (pf_file == NULL) {
        throw true;
    }
}

CFileThrowEx::~CFileThrowEx() {
    if (pf_file != NULL) {
        fclose(pf_file);
    }
}

void CFileThrowEx::vOpenFile(CString sFileName) {
    if (pf_file) {
        throw true;
    }
    pf_file = fopen(sFileName, "w+");
    if (!pf_file) {
        throw true;
    }
}

void CFileThrowEx::vCloseFile() {
    if (!pf_file) {
        throw true;
    }
    fclose(pf_file);
}

void CFileThrowEx::vPrintLine(CString sText) {
    if (pf_file == NULL) {
        throw true;
    }
    fprintf(pf_file, sText);
}

void CFileThrowEx::vPrintManyLines(vector<CString> sText) {
    for (int i = 0; i < sText.size(); i++) {
        try {
            vPrintLine(sText[i]);
        } catch (bool e) {
            throw e;
        }
    }
}
