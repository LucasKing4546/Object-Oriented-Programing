//
// Created by Lucas on 3/31/2025.
//

#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#endif //CHESSPIECE_H
#include <string>

class ChessPiece {
private:
    char color;
protected:
    unsigned int positionX;
    unsigned int positionY;
    std::string name;
public:
    ChessPiece(unsigned int positionX, unsigned int positionY, std::string name, char color) {
        this->positionX = positionX;
        this->positionY = positionY;
        this->name = move(name);
        this->color = color;
    }

    void set_X(unsigned int x);
    void set_Y(unsigned int y);
    void set_name(std::string name);
    void set_color(char color);

    unsigned int get_X() const;
    unsigned int get_Y() const;
    std::string get_name();
    char get_color() const;

    bool movePiece(unsigned int newX, unsigned int newY) {
        return false;
    }
};

class Bishop: public ChessPiece {
public:
    Bishop(unsigned int positionX, unsigned int positionY, char color):
    ChessPiece(positionX, positionY, "Bishop", color){};
    bool movePiece(unsigned int newX, unsigned int newY) {
        if (abs(positionX - newX) == abs(positionY - newY)) {
            return true;
        }
        return false;
    };
};

class Rook: public ChessPiece {
    Rook(unsigned int positionX, unsigned int positionY, char color):
    ChessPiece(positionX, positionY, "Rook", color){};
    bool movePiece(unsigned int newX, unsigned int newY) {
        if ((abs(positionX - newX) !=0 && abs(positionY - newY) == 0) ||
            abs(positionX - newX) ==0 && abs(positionY - newY) != 0()) {
            return true;
        }
        return false;
    }
};

class Horse: public ChessPiece {

};

class Pawn: public ChessPiece {

};

class Queen: public ChessPiece {

};

class King: public ChessPiece {

};