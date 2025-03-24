//
// Created by Lucas on 3/23/2025.
//
#include "BankAccount.h"
#include <stdexcept>
#include <utility>
#include <ostream>


BankAccount::BankAccount() {
    account_number = "";
    name = "";
    balance = 0;
}

BankAccount::BankAccount(string name, string account_number, int balance) {
    this->account_number = std::move(account_number);
    this->name = std::move(name);
    this->balance = balance;
}

void BankAccount::deposit(int amount){
    int currentBalance = getBalance();
    currentBalance += amount;
    setBalance(currentBalance);
}

void BankAccount::withdraw(int amount){
    if (this->balance < amount) {
        throw invalid_argument("Balance is less than amount");
    }
    else {
        this->balance -= amount;
    }
}

std::ostream& operator<<(std::ostream& os, const BankAccount& ba) {
    os << ba.getName() << " " << ba.getBalance() << " " << ba.getAccountNumber();
    return os;
}