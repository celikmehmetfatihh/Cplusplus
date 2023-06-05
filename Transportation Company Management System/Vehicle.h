#ifndef ASSIGNMENT_2_VEHICLE_H
#define ASSIGNMENT_2_VEHICLE_H

enum carType { None, Sedan, Hatchback, Limousine};

class Vehicle {
private:
    int vehicleId;
    char *brand;
    char *model;
    char *plateNo;
public:
    Vehicle();
    Vehicle(int vehicleId, char *brand, char *model, char *plateNo);
    int getVehicleId() const;
    void setVehicleId(int vehicleId);
    char *getBrand() const;
    void setBrand(char *brand);
    char *getModel() const;
    void setModel(char *model);
    char *getPlateNo() const;
    void setPlateNo(char *plateNo);
    ~Vehicle();
    Vehicle(const Vehicle &vehicle);
    void operator=(const Vehicle &vehicle);
    virtual void printVehicle();
    virtual int getSeatNum(); // I added this virtual function to override it in the Bus class, so that I can access getSeatNum function from Branch class' printVehicle() function.
    virtual carType getTypeOfCar(); // I added this virtual function to override it in the Car class, so that I can access getTypeOfCar function from Branch class' printVehicle() function.
    virtual int getType(); // I added this virtual function to override and use it in Branch class whether the vehicle's type car or bus.
    virtual double annualCost(); // I added this virtual function to override and use it in Branch class to calculate annualCost
    virtual bool checkSuitability(int numOfPeople); // I added this virtual function to override and use it in Branch class' printVehiclesBySeat function, to check if the vehicle is suitable or not according to provided people num
};


#endif //ASSIGNMENT_2_VEHICLE_H
