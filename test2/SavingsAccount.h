//
// Created by Lucas on 5/5/2025.
//

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "BankAccount.h"

class SavingsAccount : public BankAccount {
private:
    double interestRate;
public:
    SavingsAccount(long acc, int bal, double interestRate): BankAccount(acc, bal), interestRate(interestRate) {};
    bool saveToFile(std::ofstream &file) override;
};

#endif //SAVINGSACCOUNT_H
