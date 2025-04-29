//
// Created by Lucas on 4/28/2025.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <string>

enum class EntityType {
    EMPTY,
    FOX,
    GOPHER,
    PLANT
};

class Entity {
protected:
    int row;
    int column;
public:
    Entity(int row, int column);
    virtual EntityType what() const = 0;
    virtual std::string toString() const;
    virtual ~Entity() = default;
};

class Plant: public Entity {
    public:
    Plant(int row, int column);
    EntityType what() const override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const Plant& p);
};

class Empty: public Entity {
    public:
    Empty(int row, int column);
    EntityType what() const override;
    std::string toString() const override;
    friend std::ostream& operator<<(std::ostream& os, const Empty& p);
};

#endif //ENTITY_H
