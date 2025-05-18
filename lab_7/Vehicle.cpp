//
// Created by Lucas on 4/7/2025.
//

#include "Vehicle.h"
#include <iostream>

using namespace std;

void Vehicle::display() {
    cout << "Current vehicle displayed: " << this->registrationNumber << endl;
}

string Car::getBodyStyle() {
    return this->BodyStyle;
}

void Car::setBodyStyle(string body_style) {
    this->BodyStyle = move(body_style);
}

void Car::display() {
    cout << "Current car displayed: " << this->registrationNumber << ", Body style: " << this->getBodyStyle() << endl;
}

double Truck::getPayloadCapacity() const {
    return this->payloadCapacity;
}

void Truck::setPayloadCapacity(double capacity) {
    this->payloadCapacity = capacity;
}

void Truck::display() {
    cout << "Current Truck displayed: " << this->registrationNumber << ", Payload capacity: " << this->getPayloadCapacity() << endl;
}
