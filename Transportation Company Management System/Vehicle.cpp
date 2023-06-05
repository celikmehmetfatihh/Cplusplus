#include "Vehicle.h"
#include <string.h>
#include <iostream>
using namespace std;

Vehicle::Vehicle() {
    vehicleId = -1;
    brand = new char[10];
    model = new char[10];
    plateNo = new char[10];
    strcpy(brand,"Undefined");
    strcpy(model, "Undefined");
    strcpy(plateNo, "Undefined");
}

Vehicle::Vehicle(int vehicleId, char *brand, char *model, char *plateNo) {
    this->vehicleId = vehicleId;
    this->brand = new char[strlen(brand) + 1];
    this->model = new char[strlen(model) + 1];
    this->plateNo = new char[strlen(plateNo) + 1];
    strcpy(this->brand, brand);
    strcpy(this->model, model);
    strcpy(this->plateNo, plateNo);
}

Vehicle::~Vehicle() { //Destructor since Vehicle class has heap members.
    delete[] brand;
    delete[] model;
    delete[] plateNo;
}

Vehicle::Vehicle(const Vehicle &vehicle) { // Copy constructor since Vehicle class has heap members.
    brand = new char[strlen(vehicle.brand) + 1];
    model = new char[strlen(vehicle.model) + 1];
    plateNo = new char[strlen(vehicle.plateNo) + 1];

    strcpy(brand, vehicle.brand);
    strcpy(model, vehicle.model);
    strcpy(plateNo, vehicle.plateNo);
    vehicleId = vehicle.vehicleId;
}

void Vehicle::operator=(const Vehicle &vehicle) { // Assignment operator since Vehicle class has heap members.
    delete[] brand;
    delete[] model;
    delete[] plateNo;

    brand = new char[strlen(vehicle.brand) + 1];
    model = new char[strlen(vehicle.model) + 1];
    plateNo = new char[strlen(vehicle.plateNo) + 1];

    strcpy(brand, vehicle.brand);
    strcpy(model, vehicle.model);
    strcpy(plateNo, vehicle.plateNo);
    vehicleId = vehicle.vehicleId;
}

int Vehicle::getVehicleId() const {
    return vehicleId;
}

void Vehicle::setVehicleId(int vehicleId) {
    Vehicle::vehicleId = vehicleId;
}

char *Vehicle::getBrand() const {
    return brand;
}

void Vehicle::setBrand(char *brand) {
    delete[] this->brand;
    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);
}

char *Vehicle::getModel() const {
    return model;
}

void Vehicle::setModel(char *model) {
    delete[] this->model;
    this->model = new char[strlen(model) + 1];
    strcpy(this->model, model);
}

char *Vehicle::getPlateNo() const {
    return plateNo;
}

void Vehicle::setPlateNo(char *plateNo) {
    delete[] this->plateNo;
    this->plateNo = new char[strlen(plateNo) + 1];
    strcpy(this->plateNo, plateNo);
}

void Vehicle::printVehicle() {
    cout << "Vehicle ID: " << vehicleId << ", Brand: " << brand << ", Model: " << model << ", Plate Number: " << plateNo << endl;
}

int Vehicle::getSeatNum() { // I added this virtual function to override it in the Bus class, so that I can access getNumSeats function from Branch class' printVehicle() function.
    return 0;
}

carType Vehicle::getTypeOfCar() { // I added this virtual function to override it in the Car class, so that I can access getTypeOfCar function from Branch class' printVehicle() function.
    return None;
}

int Vehicle::getType() {
    return -1;
}

double Vehicle::annualCost() {
    return -1.0;
}

bool Vehicle::checkSuitability(int numOfPeople) {
    return false;
}
