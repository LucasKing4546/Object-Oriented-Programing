#include <iostream>
#include "Garage.h"

using namespace std;

int main() {
    Garage g;
    Truck t = Truck("AB17FJA",1000);
    Car c = Car("SM75ALB", "Sedan");
    Vehicle* v1{&t};
    Vehicle* v2{&c};
    g.addVehicle(v1);
    g.addVehicle(v2);
    g.display();
}