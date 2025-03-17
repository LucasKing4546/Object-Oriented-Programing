cmake_minimum_required(VERSION 3.29)
project(sem_2 C)

set(CMAKE_C_STANDARD 11)

add_executable(sem_2 main.c)

add_executable(test tests.c)

add_executable(dynamic_array dynamicarray.c)
