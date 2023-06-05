#include "Company.h"
#include <string.h>
#include <iostream>
using namespace std;

char *Company::getName() const {
    return name;
}

void Company::setName(char *name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Company::Company() {
    name = new char[10];
    strcpy(name, "Undefined");
    branchesNum = 0;
}

Company::Company(char *name) {
    this->name = new char[10];
    strcpy(this->name, name);
    branchesNum = 0;
}

Branch *const *Company::getBranches() const {
    return branches;
}

int Company::getBranchesNum() const {
    return branchesNum;
}

void Company::setBranchesNum(int branchesNum) {
    Company::branchesNum = branchesNum;
}

Company::~Company() { // Destructor
    delete[] name;

    for (int i = 0; i < branchesNum; i++)
        delete branches[i]; //If we delete Company, we need to delete its branches too.
}

Company::Company(const Company &company) { //Copy constructor
    name = new char[strlen(company.name) + 1];
    strcpy(name, company.name);
    branchesNum = company.branchesNum;

    for (int i = 0; i < branchesNum; i++)
        delete branches[i];

    for (int i=0; i< branchesNum; i++)
        branches[i] = new Branch(*company.branches[i]);
}

void Company::operator=(const Company &company) { // Assignment operator
    delete[] name;
    name = new char[strlen(company.name) + 1];
    strcpy(name, company.name);
    branchesNum = company.branchesNum;

    for (int i = 0; i < branchesNum; i++)
        delete branches[i];

    for (int i=0; i< branchesNum; i++)
        branches[i] = new Branch(*company.branches[i]);
}

void Company::addBranch() {
    cout << "Please enter branch's ID: ";
    int branchId;
    cin >> branchId;
    cin.ignore();
    cout << "Please enter the city, where branch is located: ";
    char city[100]; // I assumed that a city name will be maximum of 100 characters.
    cin.getline(city, 100);

    branches[branchesNum] = new Branch(branchId, city);
    branchesNum++;
}

void Company::printBranches() {
    for(int i= 0; i< branchesNum; i++)
        branches[i]->printBranch();
}

void Company::printVehicles() {
    cout << endl;
    for(int i= 0; i< branchesNum; i++)
        branches[i]->printVehicles();
}

void Company::printVehiclesByType() {
    cout << "Please select the type of the vehicles, You want to see: (0) Bus, (1) Car" << endl;
    cout << "Your choice: ";
    int choice;
    cin >> choice;

    if (choice == 0 || choice == 1) {
        for(int i= 0; i< branchesNum; i++)
            branches[i]->printVehiclesByType(choice);
    }
    else
        cout << "Please enter a valid choice!" << endl;
}

void Company::printTypeStatistics() {
    for(int i= 0; i< branchesNum; i++)
        branches[i]->printTypeStatistics();
}

void Company::printVehiclesBySeat() {
    int peopleNum;
    cout << "Please enter the number of passengers vehicle should be able to carry: ";
    cin >> peopleNum;

    for(int i= 0; i< branchesNum; i++)
        branches[i]->printVehiclesBySeat(peopleNum);
}

void Company::printAnnualCost() {
    float totalCost = 0;
    for(int i= 0; i< branchesNum; i++)
        totalCost += branches[i]->printAnnualCost();
    cout << "-------------------------" << endl;
    cout << "Total Annual Cost for " << name << " is " << totalCost << endl;
}

void Company::addVehicle() {
    int branchId, foundFlag = 0; // This flag is 1 when branchId from the user found in the Branches array.
    cout << "Please enter the ID of the Branch: ";
    cin >> branchId;

    for(int i= 0; i< branchesNum; i++) {
        if (branches[i]->getBranchId() == branchId) {
            branches[i]->addVehicle();
            foundFlag = 1;
        }
    }
    if (foundFlag == 0)
        cout << "There is no branch with ID " << branchId << " at " << name << endl;
}