//
// Created by Lucas on 5/5/2025.
//

#include "BankAccount.h"

BankAccount::BankAccount(long acc, int bal) {
    AccountNumber = acc;
    balance = bal;
}

bool BankAccount::deposit(int amount) {
    if (amount <= 0) {
        return false;
    }
    balance += amount;
    return true;
}

bool BankAccount::withdraw(int amount) {
    if (amount <= 0 || amount > balance) {
        return false;
    }
    balance -= amount;
    return true;
}


