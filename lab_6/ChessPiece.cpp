//
// Created by Lucas on 3/31/2025.
//
#include "ChessPiece.h"

std::string ChessPiece::get_name() {
    return this->name;
}

unsigned int ChessPiece::get_X() const {
    return this->positionX;
}

unsigned int ChessPiece::get_Y() const{
    return this->positionY;
}

char ChessPiece::get_color() const {
    return this->color;
}


void ChessPiece::set_name(std::string name) {
    this->name = move(name);
}

void ChessPiece::set_X(unsigned int x) {
    this->positionX = x;
}

void ChessPiece::set_Y(unsigned int y) {
    this->positionY = y;
}

void ChessPiece::set_color(char color) {
    this->color = color;
}

bool ChessPiece::movePiece(unsigned int newX, unsigned int newY) {
    return false;
}




