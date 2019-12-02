//
// Created by Damian on 19.11.2019.
//

#include "Driver.hpp"

Driver::Driver() {}

Driver::~Driver() {
    if(vehicle){
        vehicle->setDriver(NULL);
    }
}

void Driver::setVehicle(Vehicle *v) {
    if(vehicle->getDriver()==this){
        vehicle->setDriver(NULL);
    }
    vehicle = v;
    if(vehicle->getDriver()!=this){
        vehicle->setDriver(this);
    }
}

Vehicle *Driver::getVehicle() {
    return vehicle;
}
