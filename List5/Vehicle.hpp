//
// Created by Damian on 19.11.2019.
//

#ifndef LIST5_VEHICLE_HPP
#define LIST5_VEHICLE_HPP

#include "Wheel.hpp"
#include "Driver.hpp"
#include <string>

using namespace std;

class Vehicle {
private:
    Driver *driver;
    Wheel []wheels;
    string type;
public:
    Vehicle();
    Vehicle(string vehicleType);
    ~Vehicle();
    void setDriver(Driver *d);
    Driver *getDriver();

};

class Driver {
private:
    Vehicle *vehicle;
public:
    Driver();

    ~Driver();

    void setVehicle(Vehicle *v);

    Vehicle *getVehicle();
};

#endif //LIST5_VEHICLE_HPP
