cmake_minimum_required(VERSION 3.30)
project(lab_7)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_7 main.cpp
        Vehicle.h
        Vehicle.cpp
        Garage.h
        Garage.cpp
        FileSystem.h
        FileSystem.cpp)
