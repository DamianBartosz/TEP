#include "Car.hpp"
#include "CarException.hpp"


Car::Car() {
    m_fuel = mFMC;
    m_meter = mFMC;
    m_consumption = mFMC;
}

Car::Car(double fuel, double meter, double consumption) {
    if (fuel >= 0) {
        m_fuel = fuel;
    }
    if (meter >= 0) {
        m_meter = meter;
    }
    if (consumption >= 0) {
        m_consumption = consumption;
    }
}

double Car::dGetM_fuel() {
    return m_fuel;
}

double Car::dGetM_meter() {
    return m_meter;
}

double Car::dGetM_consumption() {
    return m_consumption;
}

void Car::vSetM_fuel(double fuel) {
    if (fuel >= 0) {
        m_fuel = fuel;
    }
}

void Car::vSetM_meter(double meter) {
    if (meter >= 0) {
        m_meter = meter;
    }
}

void Car::vSetM_consumption(double consumption) {
    if (consumption >= 0) {
        m_consumption = consumption;
    }
}

void Car::move(double distance) {
    double posible_distance = m_fuel / m_consumption * 100;
    if (posible_distance < distance) {
        m_fuel = 0;
        m_meter += posible_distance;
        throw CarException(distance - posible_distance);
    }

    m_fuel -= distance * m_consumption;
    m_meter += distance;
}
