//
// Created by Lucas on 5/5/2025.
//

#include "CheckingAccount.h"

bool CheckingAccount::saveToFile(std::ofstream &file) {
    file << "CheckingAccount " << AccountNumber << ' ' << balance << ' ' << overdraftLimit << std::endl;
    return true;
}

bool CheckingAccount::withdraw(int amount) {
    if (amount > balance + overdraftLimit || amount <= 0) {
        return false;
    }
    balance -= amount;
    return true;
}