//
// Created by Lucas on 3/10/2025.
//

#ifndef BANK_H
#define BANK_H
#include <fstream>
#include <utility>
using std::ifstream;
using std::ofstream;

class BankAccount {
    private:
    int accountNumber;
    std::string accountName;
    int balance;
    public:
    BankAccount();
    BankAccount(std::string accountName, int accountNumber, int balance);
    //get
    inline int getAccountNumber() const {return accountNumber;}
    inline std::string getAccountName() const {return accountName;}
    inline int getBalance() const {return balance;}

    //set
    inline void setAccountNumber(int a_name) {accountNumber = a_name;}
    inline void setAccountName(std::string a_num) {accountName = std::move(a_num);}
    inline void setBalance(int b) {balance = b;}


    void deposit(int inserted_sum);
    void withdraw(int requested_sum);

    friend std::ostream& operator<<(std::ostream& os, const BankAccount& bank_account);
};



#endif //BANK_H
