//
// Created by Lucas on 5/5/2025.
//

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "BankAccount.h"

class CheckingAccount : public BankAccount {
private:
    int overdraftLimit;
public:
    CheckingAccount(long acc, int bal, int overdraftLimit): BankAccount(acc, bal), overdraftLimit(overdraftLimit) {};
    bool saveToFile(std::ofstream &file) override;
    bool withdraw(int amount) override;
};

#endif //CHECKINGACCOUNT_H
