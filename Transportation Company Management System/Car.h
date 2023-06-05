#ifndef ASSIGNMENT_2_CAR_H
#define ASSIGNMENT_2_CAR_H
#include "Vehicle.h"

class Car : public Vehicle {
private:
    carType typeOfCar;
public:
    Car();
    Car(int vehicleId, char *brand, char *model, char *plateNo, carType typeOfCar);
    carType getTypeOfCar() override;
    void setTypeOfCar(carType typeOfCar);
    bool checkSuitability(int numOfPeople) override;
    double annualCost() override; /*I put an extra parameter called int someParameter to make a virtual function from Vehicle class. Since Bus's
 * and Vehicle's annualCost function has different parameters, I tried to make them as the same to do the encapsulation principle with overriding.*/
    void printVehicle() override;
    int getSeatNum() override;
    int getType() override;
};


#endif //ASSIGNMENT_2_CAR_H
