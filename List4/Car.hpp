//
// Created by Damian on 12.11.2019.
//

#ifndef LIST4_CAR_HPP
#define LIST4_CAR_HPP

const double mFMC = 10;

class Car {
private:
    double m_fuel;
    double m_meter;
    double m_consumption;
public:
    Car();

    Car(double fuel, double meter, double consumption);

    double dGetM_fuel();

    double dGetM_meter();

    double dGetM_consumption();

    void vSetM_fuel(double fuel);

    void vSetM_meter(double meter);

    void vSetM_consumption(double consumption);

    void move(double distance);
};


#endif //LIST4_CAR_HPP
