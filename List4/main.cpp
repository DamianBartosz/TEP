#include <iostream>
#include "CFileErrorCode.hpp"
#include "CFileLastError.hpp"
#include "CFileThrowEx.hpp"
#include "Car.hpp"
#include "CarException.hpp"

void vOpenFileTenTimesInEveryWay(CString sFileName) {
    for (int i = 0; i < 10; i++) {
        CFileLastError *cFLE = new CFileLastError(sFileName);
        if (CFileLastError::bGetLastError()) {
            cout << "Blad w CFileLastError" << endl;
        }
        delete cFLE;

        try {
            CFileThrowEx *cFTE = new CFileThrowEx(sFileName);
            delete cFTE;
        } catch (bool e) {
            cout << "Blad w CFileThrowEx" << endl;
        }

        bool bErr = false;
        CFileErrCode *cFEC = new CFileErrCode(sFileName, bErr);
        if (bErr) {
            cout << "Blad w CFileErrCode" << endl;
        }
        delete cFEC;
    }
}

int main() {
//    CString sFileName = "file.txt";
//    vOpenFileTenTimesInEveryWay(sFileName);
    Car c;
    try {
        c.move(150);
    } catch (CarException e) {
        cout << e.getMSG() << endl;
    }
}