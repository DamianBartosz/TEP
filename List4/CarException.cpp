#include "CarException.hpp"
#include <iostream>
#include <sstream>


using namespace std;

CarException::CarException() {
    notDrivenMeters = 0;
    msg = "Domyslny blad";
}

CarException::CarException(double nDMeters) {
    notDrivenMeters = nDMeters;
    ostringstream convert;
    convert << notDrivenMeters;
    msg = "Nie wystarczylo paliwa, samochod nie przejechal ostatnich " + convert.str() + " kilometrow.";
}

string CarException::getMSG() {
    return msg;
}
