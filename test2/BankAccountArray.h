//
// Created by Lucas on 5/5/2025.
//

#ifndef BANKACCOUNTARRAY_H
#define BANKACCOUNTARRAY_H

#include "BankAccount.h"
#include <iostream>

class BankAccountArray {
private:
    BankAccount** accounts;
    int size;
    int capacity;

public:
    BankAccountArray() {
        capacity = 10;
        size = 0;
        accounts = new BankAccount*[capacity];
    }

    ~BankAccountArray() {
        for (int i = 0; i < size; ++i) {
            delete accounts[i];
        }
        delete[] accounts;
        accounts = nullptr;
        size = 0;
        capacity = 0;
    }

    void add(BankAccount* account) {
        if (size >= capacity) {
            int newCapacity = capacity * 2;
            BankAccount** newAccounts = new BankAccount*[newCapacity];

            for (int i = 0; i < size; ++i) {
                newAccounts[i] = accounts[i];
            }

            delete[] accounts;

            accounts = newAccounts;
            capacity = newCapacity;
        }

        accounts[size++] = account;
    }

    BankAccount* get(int index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return accounts[index];
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }
};

#endif //BANKACCOUNTARRAY_H
