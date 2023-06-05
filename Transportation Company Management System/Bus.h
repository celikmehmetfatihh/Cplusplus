#ifndef ASSIGNMENT_2_BUS_H
#define ASSIGNMENT_2_BUS_H
#include "Vehicle.h"

class Bus : public Vehicle{
private:
    int seatNum;
public:
    int getSeatNum() override;
    void setSeatNum(int seatNum);
    Bus();
    Bus(int vehicleId, char *brand, char *model, char *plateNo, int seatNum);
    bool checkSuitability(int numOfPeople) override;
    double annualCost() override;
    void printVehicle() override;
    int getType() override;
};


#endif //ASSIGNMENT_2_BUS_H
