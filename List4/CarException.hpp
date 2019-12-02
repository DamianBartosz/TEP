#ifndef LIST4_CAREXCEPTION_HPP
#define LIST4_CAREXCEPTION_HPP

#include <string>

using std::string;

class CarException {
private:
    string msg;
    double notDrivenMeters;
public:
    CarException();

    CarException(double nDMeters);

    string getMSG();
};


#endif //LIST4_CAREXCEPTION_HPP
