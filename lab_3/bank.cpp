//
// Created by Lucas on 3/10/2025.
//
#include "bank.h"
#include <utility>

BankAccount::BankAccount() {
    accountNumber = 0;
    accountName = "";
    balance = 0;
}
BankAccount::BankAccount(std::string a_name, int a_num, int b) {
    accountName = std::move(a_name);
    accountNumber = a_num;
    balance = b;
}

void BankAccount::deposit(int inserted_sum) {
    int current_balance = getBalance();
    current_balance += inserted_sum;
    setBalance(current_balance);
}

void BankAccount::withdraw(int requested_sum) {
    if (requested_sum > balance) {
        throw std::invalid_argument ("Not enough funds.");
    } else {
        int current_balance = getBalance();
        current_balance -= requested_sum;
        setBalance(current_balance);
    }
}

std::ostream& operator<<(std::ostream& os, const BankAccount& bank_account) {
    os << bank_account.getAccountNumber() << " " << bank_account.getBalance();
    return os;
}


