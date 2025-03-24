//
// Created by Lucas on 3/23/2025.
//
#include<string>
#include <utility>
using namespace std;
class BankAccount{
  private:
    string name;
    string account_number;
    int balance;
  public:
    BankAccount();
    BankAccount(string name, string account_number, int balance);
    string getName() const { return name; };
    string getAccountNumber() const {return account_number;};
    int getBalance() const {return balance;};
    void setName(string name){this->name = std::move(name);};
    void setAccountNumber(string account_number){this->account_number = std::move(account_number);};
    void setBalance(int balance){this->balance = balance;};
    void deposit(int amount);
    void withdraw(int amount);

    friend ostream& operator<<(ostream& os, const BankAccount& ba);
};
