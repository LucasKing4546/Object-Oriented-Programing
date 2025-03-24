//
// Created by Lucas on 3/24/2025.
//
#include "TaskRepository.h"

void TaskRepository::add_Task(task Task) {
    if (length == capacity) {
        capacity = 2*capacity;
        task* new_data = new task[capacity];
        for (int i=0; i < length; i++) {
            new_data[i] = array[i];
        }
        delete[] array;
        array = new_data;
    }
    for (int i=0; i < length; i++) {
        if (array[i].id == Task.id) {
            throw std::invalid_argument("Id already exists!");
        }
    }
    array[length++] = Task;
}

void TaskRepository::print(char delimiter) {
    for (int i=0; i<length; i++) {
        std::cout << array[i].id << delimiter << array[i].duration;
    }
}

Duration TaskRepository::time_needed() {
    Duration total_time = Duration();
    for (int i=0; i<length; i++) {
        total_time = total_time + array[i].duration;
    }
    return total_time;
}

void TaskRepository::delete_all() {
    if (array) {
        delete[] array;
        array = nullptr;
        length = 0;
    }
}

int TaskRepository::count_tasks_between(Duration min_duration, Duration max_duration) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (min_duration.getSeconds() <= array[i].duration.getSeconds() &&
            max_duration.getSeconds() >= array[i].duration.getSeconds()) {
            count++;
            }
    }
    return count;
}

