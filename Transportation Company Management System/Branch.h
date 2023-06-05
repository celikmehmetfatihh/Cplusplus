#ifndef ASSIGNMENT_2_BRANCH_H
#define ASSIGNMENT_2_BRANCH_H

#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"

class Branch {
private:
    int branchId;
    char* city;
    Vehicle *vehicles[30];
    int vehiclesNum;
public:
    Branch();
    Branch(int branchId, char* city);
    int getBranchId() const;
    void setBranchId(int branchId);
    char *getCity() const;
    void setCity(char *city);
    Vehicle *const *getVehicles() const;
    int getVehiclesNum() const;
    void setVehiclesNum(int vehiclesNum);
    ~Branch();
    Branch(const Branch &branch);
    void operator=(const Branch &branch);
    void addVehicle();
    void printBranch();
    void printVehicles();
    void printVehiclesByType(int choice);
    void printTypeStatistics();
    void printVehiclesBySeat(int peopleNum);
    float printAnnualCost();
};


#endif //ASSIGNMENT_2_BRANCH_H
