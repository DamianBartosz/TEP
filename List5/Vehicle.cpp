#include "Vehicle.hpp"

Vehicle::Vehicle() {
    type = "dwuslad";
    Wheel w1, w2, w3, w4;
    wheels = {w1, w2, w3, w4};
}

Vehicle::Vehicle(string vehicleType){
    type = vehicleType;
    if(type=="jednoslad"){
        Wheel w1, w2;
        wheels = {w1, w2};
    }else{
        Wheel w1, w2, w3, w4;
        wheels = {w1,w2,w3,w4};
    }

}

Vehicle::~Vehicle(){
    if(driver) {
        driver->setVehicle(NULL);
    }
}

void Vehicle::setDriver(Driver *d) {
    if(driver->getVehicle() == this){
        driver->setVehicle(NULL);
    }
    driver = d;
    if(driver->getVehicle() != this){
        driver->setVehicle(this);
    }
}

Driver *Vehicle::getDriver() {
    return driver;
}



