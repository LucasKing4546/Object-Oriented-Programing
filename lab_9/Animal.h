//
// Created by Lucas on 4/28/2025.
//

#ifndef ANIMAL_H
#define ANIMAL_H
#include "Entity.h"

class Animal: public Entity {
private:
    int age;
public:
    int getAge() const;
    void setAge(int age);
    Animal(int r, int c, int age);
    EntityType what() const override = 0;
};

class Fox: public Animal {
public:
    Fox(int r, int c, int age);
    EntityType what() const override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const Fox& f);
};


class Gopher: public Animal {
public:
    Gopher(int r, int c, int age);
    EntityType what() const override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const Gopher& g);
};

#endif //ANIMAL_H
