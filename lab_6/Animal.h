//
// Created by Lucas on 3/31/2025.
//

#ifndef ANIMAL_H
#define ANIMAL_H

#endif //ANIMAL_H

#include <iostream>
#include <string>

class Animal {
protected:
    std::string commonName;
    std::string scientificName;
public:
    Animal(std::string commonName, std::string scientificName) {
        this->commonName = move(commonName);
        this->scientificName = move(scientificName);
    }
    void DisplayInfo() {
        std::cout << "Animal (" << commonName << ", " << scientificName << ")" << '\n';
    }
};

class Mammal: public Animal {
private:
    bool isAquatic;
    unsigned char gestationPeriod;
public:
    Mammal(bool isAquatic, unsigned char gestationPeriod): Animal(commonName, scientificName) {
        this->gestationPeriod = gestationPeriod;
        this->isAquatic = isAquatic;
    }
    void DisplayInfo() {
        std::cout << "Mammal: " << '\n' << '\t';
        Animal::DisplayInfo();
        std::cout <<"\tAtributes: (Aquatic: " << isAquatic << ", Gestation period:" << gestationPeriod << ")\n";
    }

};

class Bird: public Animal {
    private:
    unsigned int wingSpan;
    public:
    Bird(unsigned int wingSpan): Animal(commonName, scientificName) {
        this->wingSpan = wingSpan;
    }
    void DisplayInfo() {
        std::cout << "Bird: " << '\n' << '\t';
        Animal::DisplayInfo();
        std::cout <<"\tAtributes: (Wing Span: " << wingSpan << ")\n";
    }

};

class Reptile: public Animal {
private:
     bool isVenomous;
public:
    Bird(bool isVenomous): Animal(commonName, scientificName) {
        this->isVenomous = isVenomous;
    }
    void DisplayInfo() {
        std::cout << "Reptile: " << '\n' << '\t';
        Animal::DisplayInfo();
        std::cout <<"\tAtributes: (Venomous: " << isVenomous << ")\n";
    }

};