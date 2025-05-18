//
// Created by Lucas on 5/5/2025.
//

#include "SavingsAccount.h"

bool SavingsAccount::saveToFile(std::ofstream &file) {
    file << "SavingsAccount " << AccountNumber << ' ' << balance << ' ' << interestRate << std::endl;
    return true;
}
