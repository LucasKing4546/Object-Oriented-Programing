//
// Created by Lucas on 4/7/2025.
//

#ifndef GARAGE_H
#define GARAGE_H

#endif //GARAGE_H

#include "Vehicle.h"
#include <iostream>

using namespace std;

class Garage {
private:
    static const int MAX_CAPACITY = 100;
    Vehicle* vehicles[MAX_CAPACITY]{};
    int count = 0;
public:
    void display();
    void addVehicle(Vehicle* vehicle);
};