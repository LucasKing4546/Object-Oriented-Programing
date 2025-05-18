//
// Created by Lucas on 5/1/2025.
//


#include "FileSystem.h"

#include <bits/stdc++.h>

int File::getSize() const {
    return this->size;
}

int Folder::getSize() const {
    int folder_size = 0;
    for (int i = 0; i < count; i++) {
        folder_size += components[i]->getSize();
    }
    return folder_size;
}


void Folder::display() {
    std::cout << "Folder:" << std::endl;
    for (int i = 0; i < count; i++) {
        std::stringstream ss(components[i]->getPath());
        char del = '\\';
        std::string t, name;
        while (std::getline(ss, t, del)) {
            name = t;
        }
        std::cout << '\n' + name << " Size: " << components[i]->getSize() << std::endl;
    }
}

