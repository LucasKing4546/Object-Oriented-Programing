//
// Created by Lucas on 5/5/2025.
//

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <fstream>

class BankAccount {
protected:
    long AccountNumber;
    int balance;
public:
    BankAccount(long acc, int bal);
    bool deposit(int amount);
    virtual bool withdraw(int amount);
    virtual bool saveToFile(std::ofstream &file) = 0;
    virtual ~BankAccount() = default;
};

#endif //BANKACCOUNT_H
