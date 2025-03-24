//
// Created by Lucas on 3/23/2025.
//

#ifndef BIGINTEGER_H
#define BIGINTEGER_H
#include <string>

#endif //BIGINTEGER_H

class BigInteger {
    public:
    BigInteger() {
        capacity = 10;
        data = new int[capacity];
        length = 1;
        data[0] = 0;
    }
    BigInteger(std::string s){
        capacity = 10;
        data = new int[capacity];
        length = s.length();
        for (int i = 0; i < length; i++) {
            data[i] = s[i] - '0';
        }
    }

    int compare(const BigInteger &N) const {
        if (length != N.length()) {
            if (length > N.length()) {
                return 1;
            }
            return -1;
        }
        for (int i = length-1; i >= 0; i--) {
            if (data[i] != N.data[i]) {
                if (data[i] > N.data[i]) {
                    return 1;
                }
                return -1;
            }
        }
        return 0;
    }

    friend bool operator==(const BigInteger &N1, const BigInteger &N2);
    friend bool operator!=(const BigInteger &N1, const BigInteger &N2);
    friend bool operator<(const BigInteger &N1, const BigInteger &N2);
    friend bool operator>(const BigInteger &N1, const BigInteger &N2);
    friend bool operator<=(const BigInteger &N1, const BigInteger &N2);
    friend bool operator>=(const BigInteger &N1, const BigInteger &N2);

    BigInteger(const BigInteger &other) {
        capacity = other.capacity;
        length = other.length;
        data = new int[capacity];
        for (int i = 0; i < length; i++) {
            data[i] = other.data[i];
        }
    }
    ~BigInteger() {
        delete[] data;
        data = nullptr;
    }

    BigInteger &operator=(const BigInteger &other) {
        if (this != &other) {
            if (data != nullptr) {
                delete[] data;
            }
            capacity = other.capacity;
            length = other.length;
            data = new int[capacity];
            for (int i=0; i<length; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    private:
        int length;
        int capacity;
        int *data;
};