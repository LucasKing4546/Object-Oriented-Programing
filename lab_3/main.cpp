#include <iostream>
#include "bank.h"

using namespace std;

int main() {
    BankAccount my_account;
    cout << "Enter account name: ";
    string name;
    cin >> name;
    my_account.setAccountName(name);
    cout << "Enter account number: ";
    int number;
    cin >> number;
    my_account.setAccountNumber(number);
    cout << "Enter account balance: ";
    int balance;
    cin >> balance;
    my_account.setBalance(balance);
    return 0;
}
