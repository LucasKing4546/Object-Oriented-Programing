//
// Created by Lucas on 4/28/2025.
//

#include "Animal.h"

using namespace std;

Animal::Animal(int r, int c, int age) : Entity(r, c), age(age) {};

int Animal::getAge() const {
    return age;
}

void Animal::setAge(int age) {
    this->age = age;
}

Fox::Fox(int r, int c, int age): Animal(r, c, age) {};

Gopher::Gopher(int r, int c, int age): Animal(r, c, age) {}

EntityType Fox::what() const {
    return EntityType::FOX;
}

EntityType Gopher::what() const {
    return EntityType::GOPHER;
}

std::string Fox::toString() const {
    return std::to_string('F');
}

std::string Gopher::toString() const {
    return std::to_string('G');
}

std::ostream& operator<<(std::ostream& os, const Gopher& g) {
    os << g.toString();
}

std::ostream& operator<<(std::ostream& os, const Fox& f) {
    os << f.toString();
}






