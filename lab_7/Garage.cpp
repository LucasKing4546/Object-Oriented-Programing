//
// Created by Lucas on 5/1/2025.
//

#include <iostream>
#include "Garage.h"

void Garage::display() {
    std::cout << "Displaying garage:" << std::endl;
    for (int i = 0; i < count; i++) {
        vehicles[i]->display();
    }
}

void Garage::addVehicle(Vehicle *vehicle) {
    if (count < MAX_CAPACITY) {
        vehicles[count++] = vehicle;
    }
    else {
        throw std::overflow_error("Garage full.");
    }
}

