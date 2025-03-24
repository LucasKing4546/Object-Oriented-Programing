//
// Created by Lucas on 3/23/2025.
//

#ifndef DOUBLEQUEUE_H
#define DOUBLEQUEUE_H

#endif //DOUBLEQUEUE_H

#include <iostream>

class Deque {
    public:
    Deque();
    Deque(int cap) {
        capacity = cap;
        data = new int[capacity];
        length = 0;
    };

    ~Deque() {
        if (data) {
            delete[] data;
            data = nullptr;
        }
    }
    Deque(const Deque& other) {
        capacity = other.capacity;
        length = other.length;
        data = new int[capacity];
        for (int i = 0; i < length; i++) {
            data[i] = other.data[i];
        }
    }

    Deque& operator=(const Deque& other) {
        if (this != &other) {
            if (data) {
                delete[] data;
            }
            capacity = other.capacity;
            length = other.length;
            data = new int[capacity];
            for (int i = 0; i < length; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    void push_back(int value);
    void push_front(int value);
    void pop_back();
    void pop_front();
    int top();
    int back();

    friend std::ostream& operator<<(std::ostream& os, const Deque& dq);
    friend std::istream& operator>>(std::istream& is, Deque& dq);
    private:
        int length;
        int capacity;
        int* data;
};
