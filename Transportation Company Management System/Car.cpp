#include "Car.h"
#include "Vehicle.h"
#include <iostream>
using namespace std;

/*Since Car Class does not have any hep members, i didn't implement copy constructor, assignment operator, and destructor*/

Car::Car() {
    typeOfCar = None;
}

Car::Car(int vehicleId, char *brand, char *model, char *plateNo, carType typeOfCar) : Vehicle(vehicleId, brand, model, plateNo){
    this->typeOfCar = typeOfCar;
}

carType Car::getTypeOfCar()  {
    return typeOfCar;
}

void Car::setTypeOfCar(carType typeOfCar) {
    Car::typeOfCar = typeOfCar;
}


int Car::getSeatNum() {
    if (getTypeOfCar() == 0)
        return 0;
    else if ((getTypeOfCar() == 1) || (getTypeOfCar() == 2))
        return 5;
    else
        return 6;
}

bool Car::checkSuitability(int numOfPeople) {
    return (numOfPeople <= getSeatNum()) ? true : false;
}

double Car::annualCost() {
    float carKm;
    cout << "Enter the kilometres driven: ";
    cin >> carKm;
    return 10 * carKm;
}

void Car::printVehicle() {
    Vehicle::printVehicle();
    cout << ", Car Type: ";
    if (typeOfCar == 0)
        cout << "None" << endl;
    else if (typeOfCar == 1)
        cout << "Sedan" << endl;
    else if (typeOfCar == 2)
        cout << "Hatchback" << endl;
    else
        cout << "Limousine" << endl;
}

int Car::getType() {
    return 1;
}

