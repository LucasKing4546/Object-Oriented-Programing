//
// Created by Lucas on 3/24/2025.
//

#ifndef DURATION_H
#define DURATION_H

#endif //DURATION_H

#include <iostream>
#include <string.h>

class Duration{
    private:
        int amount;
        std::string unit;
    public:
       Duration(){
         amount = 0;
         unit = "s";
       };
       int getSeconds(){
         return amount;
       }

};