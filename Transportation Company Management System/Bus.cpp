#include "Bus.h"
#include <iostream>
using namespace std;

/*Since Bus Class does not have any heap member, i didn't implement copy constructor, assignment operator, and destructor*/

int Bus::getSeatNum() {
    return seatNum;
}

void Bus::setSeatNum(int seatNum) {
    Bus::seatNum = seatNum;
}

Bus::Bus() {
    seatNum = 0;
}

Bus::Bus(int vehicleId, char *brand, char *model, char *plateNo, int seatNum) :Vehicle(vehicleId, brand, model, plateNo){
    this->seatNum = seatNum;
}

bool Bus::checkSuitability(int numOfPeople) {
    return (numOfPeople <= getSeatNum()) ? true : false;
}

double Bus::annualCost() {
    float maintenanceCost;
    int servicedTime;
    cout << "Enter the maintenance cost: ";
    cin >> maintenanceCost;
    cout << "Enter the number of times bus has been serviced: ";
    cin >> servicedTime;
    return maintenanceCost * servicedTime;
}

void Bus::printVehicle() {
    Vehicle::printVehicle();
     cout << ", Car Type: Bus, Number of seats: " << seatNum << endl;
}

int Bus::getType() {
    return 2;
}
