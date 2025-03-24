cmake_minimum_required(VERSION 3.30)
project(test_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(test_project
        BankAccount.h
        BankAccount.cpp
        Complex.h
        Complex.cpp
        main.cpp
        DoubleQueue.h
        DoubleQueue.cpp
        BigInteger.h
        BigInteger.cpp)
