//
// Created by Lucas on 3/24/2025.
//
#include "Duration.h"

int Duration::getSeconds() const {
    int new_amount = amount;
    if (unit == 'h') {
        new_amount = 3600*amount;
    }
    else if (unit == 'm'){
        new_amount = 60*amount;
    }
    return new_amount;
}

int Duration::get(const char &n_unit) const {
    if (n_unit!='s' && n_unit!='m' && n_unit!='h') {
        throw std::invalid_argument("Unit is invalid");
    }
    else {
        if (unit == n_unit) {
            return amount;
        }
        else {
            int new_amount = amount;
            if (unit == 'h') {
                new_amount = 3600*amount;
            }
            else if (unit == 'm'){
                new_amount = 60*amount;
            }
            if (n_unit == 'h') {
                new_amount = new_amount/3600;
            }
            else if (n_unit == 'm'){
                new_amount = new_amount/60 ;
            }
            return new_amount;
        }
    }
}
