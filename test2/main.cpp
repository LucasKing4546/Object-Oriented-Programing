#include <algorithm>

#include "BankAccount.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "BankAccountArray.h"

#include <cassert>
#include <fstream>
#include <sstream>


BankAccountArray loadFromFile(std::ifstream &file) {
    BankAccountArray accounts;
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);

        long AccountNumber;
        int Balance;
        std::string AccountType;

        ss>>AccountType>>AccountNumber>>Balance;

        if (AccountType == "SavingsAccount") {
            double interestRate;
            ss>>interestRate;
            accounts.add(new SavingsAccount(
                AccountNumber,
                Balance,
                interestRate)
                );
        }
        else {
            int overdraft;
            ss>>overdraft;
            accounts.add(new CheckingAccount(
                    AccountNumber,
                    Balance,
                    overdraft)
                    );
        }
    }
    return accounts;
}


int main() {
    std::cout << "Testing..." << std::endl;
    std::ofstream outfile{"test.txt", std::ios::trunc};
    assert(outfile.is_open());

    SavingsAccount s = SavingsAccount(123456789, 1000, 2.0);
    CheckingAccount c = CheckingAccount(819481802, 2000, 500);

    assert(s.deposit(500));
    assert(c.deposit(1000));

    assert(s.withdraw(1000));
    assert(c.withdraw(500));
    assert(c.withdraw(3000)); // all the money left + 500 overdraft

    assert(!s.deposit(-100));
    assert(!c.deposit(0));

    assert(!c.withdraw(-100));
    assert(!s.withdraw(-500));

    assert(s.saveToFile(outfile));
    assert(c.saveToFile(outfile));

    outfile.close();

    std::ifstream infile;
    infile.open("test.txt");
    assert(infile.is_open());
    BankAccountArray accounts;
    accounts = loadFromFile(infile);
    assert(!accounts.isEmpty());
    std::cout << "Files: " << accounts.getSize() << std::endl;
    infile.close();
    std::cout << "Testing complete!" << std::endl;
}
