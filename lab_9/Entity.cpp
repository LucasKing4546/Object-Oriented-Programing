//
// Created by Lucas on 4/28/2025.
//

#include "Entity.h"

Entity::Entity(int row, int column) {
    this->row = row;
    this->column = column;
}

Plant::Plant(int row, int column): Entity(row, column) {}

EntityType Plant::what() const {
    return EntityType::PLANT;
}

std::string Plant::toString() const {
    return std::to_string('P');
}

std::ostream& operator<<(std::ostream& os, const Plant& p) {
    return os << p.toString();
}

Empty::Empty(int row, int column): Entity(row, column) {}

EntityType Empty::what() const {
    return EntityType::EMPTY;
}

std::string Empty::toString() const {
    return std::to_string('E');
}

std::ostream& operator<<(std::ostream& os, const Empty& e) {
    return os << e.toString();
}







