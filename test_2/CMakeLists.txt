cmake_minimum_required(VERSION 3.30)
project(test_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(test_2 main.cpp
        Duration.h
        TaskRepository.h
        Duration.cpp
        TaskRepository.cpp)
