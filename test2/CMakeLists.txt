cmake_minimum_required(VERSION 3.30)
project(test2)

set(CMAKE_CXX_STANDARD 20)

add_executable(test2 main.cpp
        BankAccount.h
        BankAccount.cpp
        SavingsAccount.h
        CheckingAccount.h
        SavingsAccount.cpp
        CheckingAccount.cpp
        BankAccountArray.h
)
