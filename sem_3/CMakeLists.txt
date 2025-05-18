cmake_minimum_required(VERSION 3.30)
project(sem_3)

set(CMAKE_CXX_STANDARD 20)

add_executable(sem_3 main.cpp
        AcousticWawe.h
        AcousticWawe.cpp
        DerivedWawes.h
        DerivedWaves.cpp)
