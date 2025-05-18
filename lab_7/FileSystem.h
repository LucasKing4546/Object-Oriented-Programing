//
// Created by Lucas on 5/1/2025.
//

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>

class FSComponent {
protected:
    std::string path;
public:
    virtual int getSize() const = 0;
    virtual void display() = 0;
    std::string getPath() {
        return path;
    }
};

class File: public FSComponent {
protected:
    int size;
public:
    int getSize() const override;
};

class Folder: public FSComponent {
protected:
    static int const MAX_CAPACITY = 100;
    FSComponent* components[100]{};
    int count;
public:
    int getSize() const override;
    void display() override;
};

#endif //FILESYSTEM_H
