#ifndef ASSIGNMENT_2_COMPANY_H
#define ASSIGNMENT_2_COMPANY_H

#include "Branch.h"

class Company {
private:
    char *name;
    Branch *branches[10];
    int branchesNum;
public:
    Company();
    Company(char *name);
    char *getName() const;
    void setName(char *name);
    Branch *const *getBranches() const;
    int getBranchesNum() const;
    void setBranchesNum(int branchesNum);
    ~Company();
    Company(const Company &company);
    void operator=(const Company &company);
    void addBranch();
    void printBranches();
    void printVehicles();
    void printVehiclesByType();
    void printTypeStatistics();
    void printVehiclesBySeat();
    void printAnnualCost();
    void addVehicle();
};


#endif //ASSIGNMENT_2_COMPANY_H
