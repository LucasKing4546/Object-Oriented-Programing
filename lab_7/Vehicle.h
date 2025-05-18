//
// Created by Lucas on 4/7/2025.
//

#ifndef VEHICLE_H
#define VEHICLE_H

#endif //VEHICLE_H

#include <string>
#include <utility>

using namespace std;

class Vehicle {
protected:
    string registrationNumber;
public:
    Vehicle(string registrationNumber){ this->registrationNumber = std::move(registrationNumber); };
    virtual void display();
};

class Car : public Vehicle {
private:
    string BodyStyle;
public:
    Car(string registration, string BodyStyle) : Vehicle(move(registration)) {
        this->BodyStyle = move(BodyStyle);
    }
    string getBodyStyle();
    void setBodyStyle(string body_style);
    void display() override;
};

class Truck : public Vehicle {
private:
    double payloadCapacity;
public:
    Truck(string registration, double payloadCapacity) : Vehicle(move(registration)) {
        this->payloadCapacity = payloadCapacity;
    }
    double getPayloadCapacity() const;
    void setPayloadCapacity(double capacity);
    void display() override;
};
