#include "Branch.h"
#include <string.h>
#include "Car.h"
#include <iostream>
using namespace std;

Branch::Branch() {
    branchId = -1;
    city = new char[10];
    strcpy(city,"Undefined");
    vehiclesNum = 0;
}

Branch::Branch(int branchId, char *city) {
    this->branchId = branchId;
    this->city = new char[strlen(city) + 1];
    strcpy(this->city, city);
    vehiclesNum = 0;
}

int Branch::getBranchId() const {
    return branchId;
}

void Branch::setBranchId(int branchId) {
    Branch::branchId = branchId;
}

char *Branch::getCity() const {
    return city;
}

void Branch::setCity(char *city) {
    delete[] this->city;
    this->city = new char[strlen(city) + 1];
    strcpy(this->city, city);
}

Vehicle *const *Branch::getVehicles() const {
    return vehicles;
}

int Branch::getVehiclesNum() const {
    return vehiclesNum;
}

void Branch::setVehiclesNum(int vehiclesNum) {
    Branch::vehiclesNum = vehiclesNum;
}

Branch::~Branch() {
    delete[] city;
    //We shouldn't delete vehicles here like we delete branches in Company class' destrucor because if we delete Branch, Vehicles still need to continue to live.
}

Branch::Branch(const Branch &branch) {
    city = new char[strlen(branch.city) + 1];
    strcpy(city, branch.city);
    branchId = branch.branchId;
    vehiclesNum = branch.vehiclesNum;

    for (int i = 0; i < vehiclesNum; i++) // Deleting old vehicles if there is any.
        delete vehicles[i];

    for(int i= 0; i< vehiclesNum; i++)
        vehicles[i] = new Vehicle(*branch.vehicles[i]);
}

void Branch::operator=(const Branch &branch) {
    delete[] city;

    city = new char[strlen(branch.city) + 1];
    strcpy(city, branch.city);
    branchId = branch.branchId;
    vehiclesNum = branch.vehiclesNum;

    for (int i = 0; i < vehiclesNum; i++) // Deleting old vehicles if there is any.
        delete vehicles[i];

    for(int i= 0; i< vehiclesNum; i++)
        vehicles[i] = new Vehicle(*branch.vehicles[i]);
}

void Branch::addVehicle() {
    if (vehiclesNum == 30)
        cout << "Vehicles capacity for this branch is full!" << endl;
    else {
        int choice;
        cout << "What kind of vehicle would You like to add? " << endl;
        cout << "Possible options: (0) Bus, (1) Sedan, (2) Hatchback, (3) Limousine" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();

        int vehicleId;
        char brand[100], model[100], plateNo[100];

        /*In the sample output, you provided model of the vehicle like 8 Series, there is a space
* if I read it with cin, plateNumber wouldnt have been asked, and have taken from the input buffer. That's why I googled this, to read the spaces too, I found
* a method using cin.getline. This is like gets() in C.*/
        if (choice <0 || choice >3)
            cout << "Please enter a valid choice!" << endl;
        else {

            cout << "Please enter the ID of the vehicle: ";
            cin >> vehicleId;
            cin.ignore();

            cout << "Please enter the brand of the vehicle: ";
            cin.getline(brand, 100);

            cout << "Please enter the model of the vehicle: ";
            cin.getline(model, 100);

            cout << "Please enter the plate number of the vehicle: ";
            cin.getline(plateNo, 100);


            if (choice == 0) {
                int seatNum;;
                cout << "Please enter the number of seats on the Bus: ";
                cin >> seatNum;
                Bus *b1 = new Bus(vehicleId, brand, model, plateNo, seatNum);
                vehicles[vehiclesNum] = b1;
                vehiclesNum++;
                cout << "Vehicle is successfully added!" << endl;
            } else if (choice == 1) {
                Car *c1 = new Car(vehicleId, model, brand, plateNo, Sedan);
                vehicles[vehiclesNum] = c1;
                vehiclesNum++;
                cout << "Vehicle is successfully added!" << endl;
            } else if (choice == 2) {
                Car *c1 = new Car(vehicleId, model, brand, plateNo, Hatchback);
                vehicles[vehiclesNum] = c1;
                vehiclesNum++;
                cout << "Vehicle is successfully added!" << endl;
            } else if (choice == 3) {
                Car *c1 = new Car(vehicleId, model, brand, plateNo, Limousine);
                vehicles[vehiclesNum] = c1;
                vehiclesNum++;
                cout << "Vehicle is successfully added!" << endl;
            }
        }
    }
}

void Branch::printBranch() {
    cout << endl << "City: " << city << ", Number of vehicles: " << vehiclesNum << endl;
}

void Branch::printVehicles() {
    cout << "Vehicles at Branch with ID " << branchId << ":" << endl;
    for(int i= 0; i< vehiclesNum; i++)
        vehicles[i]->printVehicle();
}

void Branch::printVehiclesByType(int choice) {
    for(int i= 0; i< vehiclesNum; i++) {
        if ((choice == 0 && vehicles[i]->getType() == 2) || (choice == 1 && vehicles[i]->getType() == 1)) { /* print vehicle if choice=0 (bus) and  vehicles[i]->getType() == 2
 * (bus)      OR      choice == 1 (car) and  vehicles[i]->getType() == 1 (car)*/
            cout << endl << "Vehicle at Branch with ID: " << branchId << endl;
            vehicles[i]->printVehicle();
        }
    }
}

void Branch::printTypeStatistics() {
    int carNum = 0, busNum = 0;
    for(int i= 0; i< vehiclesNum; i++) {
        if (vehicles[i]->getType() == 1) //car
            carNum++;
        else if(vehicles[i]->getType() == 2) //bus
            busNum++;
    }
    cout << endl << "At Branch with ID: " << branchId << " there are:" << endl;
    cout << "    " << busNum << " bus(es)" << endl;
    cout << "    " << carNum << " car(s)" << endl;
}

void Branch::printVehiclesBySeat(int peopleNum) {
    for(int i= 0; i< vehiclesNum; i++) {
        if (vehicles[i]->checkSuitability(peopleNum) == true) { // if peopleNum provided lesser or equal to the seats on the vehicle
            cout << "Vehicle at Branch with ID: " << branchId << endl;
            vehicles[i]->printVehicle();
        }
    }
}

float Branch::printAnnualCost() {
    float maintenanceCost, totalCost = 0, carKm;
    int servicedTime=0;
    cout << endl << "Vehicles at Branch with ID " << branchId << ":" << endl;
    for(int i= 0; i< vehiclesNum; i++) {
        cout << "Vehicle " << (i + 1) << ":" << endl;
        if (vehicles[i]->getType() == 2) // bus
            totalCost += vehicles[i]->annualCost();
        else if (vehicles[i]->getType() == 1) // car
            totalCost += vehicles[i]->annualCost();
    }
    cout << "Total Annual Cost for Branch with ID:" << branchId << " is " << totalCost << endl;
    return totalCost;
}