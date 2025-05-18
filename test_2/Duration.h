//
// Created by Lucas on 3/24/2025.
//

#ifndef DURATION_H
#define DURATION_H

#endif //DURATION_H

#include <iostream>

class Duration{
private:
    int amount;
    char unit;
public:
    Duration(){
        amount = 0;
        unit = 's';
    };

    Duration(int n_amount, char n_unit) {
        if (n_unit!='s' && n_unit!='m' && n_unit!='h') {
            throw std::invalid_argument("Unit is invalid");
        }
        else {
            amount = n_amount;
            unit = n_unit;
        }
    }

    int getSeconds() const;

    int get(const char& n_unit) const;

    friend std::ostream& operator<<(std::ostream& os, const Duration& obj) {
        os << "PT";
        int h = 0, m = 0, s = 0;
        h = obj.amount / 3600;
        m = (obj.amount/60) % 60;
        s = obj.amount % 60;
        if (h!=0) {
            os << h << "H";
        }
        if (m!=0) {
            os << m << "M";
        }
        if (s!=0) {
            os << s << "S";
        }
        return os;
    }

    friend Duration operator+(const Duration& d1, const Duration& d2) {
        return {d1.get('s')+d2.get('s'), 's'};
    }

    friend Duration operator-(const Duration& d1, const Duration& d2) {
        int bias = 1;
        if (d1.get('s') < d2.get('s'))
            bias = -1;
        return {bias*(d1.get('s')-d2.get('s')), 's'};
    }
};