//
// Created by Lucas on 3/23/2025.
//
#include "DoubleQueue.h"

Deque::Deque() {
    capacity = 0;
    data = nullptr;
    length = 0;
}
void::Deque::push_back(int value) {
    if (length == capacity) {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < length; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[length++] = value;
}

void::Deque::push_front(int value) {
    if (length == capacity) {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < length; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    for (int i = length; i > 0; i--) {
        data[i] = data[i - 1];
    }
    data[0] = value;
    length++;
}

void::Deque::pop_front() {
    if (length == 0) {
        throw std::out_of_range("Deque is empty");
    }
    length--;
    for (int i = 0; i < length; i++) {
        data[i] = data[i + 1];
    }
}

void::Deque::pop_back() {
    if (length == 0) {
        throw std::out_of_range("Deque is empty");
    }
    length--;
}

int::Deque::top() {
    if (length == 0) {
        throw std::out_of_range("Deque is empty");
    }
    return data[length];
}

int Deque::back() {
    if (length == 0) {
        throw std::out_of_range("Deque is empty");
    }
    return data[length - 1];
}

std::ostream& operator<<(std::ostream& os, const Deque& obj) {
    for (int i = 0; i < obj.length; i++) {
        os << obj.data[i] << " ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Deque& obj) {
    int capacity,  item;
    std::cout << "Enter the capacity of the deque you want to read: ";
    is >> capacity;
    obj.capacity = capacity;
    std::cout << "Enter the elements of the deque you want to read: ";
    while (is >> item) {
        obj.push_back(item);
    }
}

