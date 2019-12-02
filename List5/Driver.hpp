#ifndef LIST5_DRIVER_HPP
#define LIST5_DRIVER_HPP


class Vehicle;

class Driver {
private:
    Vehicle *vehicle;
public:
    Driver();

    ~Driver();

    void setVehicle(Vehicle *v);

    Vehicle *getVehicle();
};


#endif //LIST5_DRIVER_HPP
