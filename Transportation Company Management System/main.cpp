/* Mehmet Fatih Çelik – 2385268
I read and accept the submission rules and the extra rules specified in
each question. This is my own work that is done by myself only */

#include <iostream>
using namespace std;
#include "Company.h"

int main() {
    cout << "Welcome to BAYFAMETA Transports" << endl << endl;
    int selection;
    Company c1("BAYFAMETA Transport");
    do {
        cout << endl << "Options:" << endl;
        cout << "1. Add a new branch to the company." << endl;
        cout << "2. Add a new vehicle (car or bus) to a branch." << endl;
        cout << "3. Print all the branches along with their cities and the number of vehicles." << endl;
        cout << "4. Print the details stored as member variables for the vehicles in each branch." << endl;
        cout << "5. Print the details stored as member variables for the vehicles in each branch whose type is a given type." << endl;
        cout << "6. Print the number of each type of vehicle in each branch." << endl;
        cout << "7. Print the details stored as member variables for the vehicles that can carry a given number of people in each branch." << endl;
        cout << "8. Calculate the total annual cost for the company." << endl;
        cout << "9. Exit" << endl;
        cout << "Your selection: ";
        cin >> selection;
        if (selection == 1)
            c1.addBranch();
        else if (selection == 2)
            c1.addVehicle();
        else if (selection == 3)
            c1.printBranches();
        else if (selection == 4)
            c1.printVehicles();
        else if (selection == 5)
            c1.printVehiclesByType();
        else if (selection == 6)
            c1.printTypeStatistics();
        else if (selection == 7)
            c1.printVehiclesBySeat();
        else if (selection == 8)
            c1.printAnnualCost();
        else if (selection == 9)
            cout << "Good Bye!" << endl;
        else
            cout << "Please enter a valid selection!" << endl;

    } while (selection != 9);


    return 0;
}
