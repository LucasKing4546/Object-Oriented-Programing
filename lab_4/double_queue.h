//
// Created by Lucas on 3/17/2025.
//

#ifndef DOUBLE_QUEUE_H
#define DOUBLE_QUEUE_H

#endif //DOUBLE_QUEUE_H

#pragma once
#include <iostream>


class DoubleQueue {
public:
    DoubleQueue(unsigned int capacity = 10):m_data{new int[capacity]}, m_capacity{capacity}, m_length{0}{};

    unsigned int length() const {return m_length;};
    unsigned int capacity() const {return m_capacity;};

    void resize() {
        unsigned int newCapacity = m_capacity * 2;
        int* newData = new int[newCapacity];
        for (int i = 0; i < m_length; i++) {
            newData[i] = m_data[i];
        }
        delete[] m_data;
        m_data = newData;
        m_capacity = newCapacity;
    }

    void push_back(int item) {
        if (m_length >= m_capacity) {
            resize();
        }
        m_data[m_length++] = item;
    }
    void push_front(int item) {
        if (m_length >= m_capacity) {
            resize();
        }
        m_length++;
        for (unsigned int i = m_length - 1; i > 0; i--) {
            m_data[i] = m_data[i - 1];
        }
        m_data[0] = item;
    }
    void pop_front() {
        for (int i = 1; i < m_length; i++) {
            m_data[i-1] = m_data[i];
        }
        m_length--;
    }
    void pop_back() {
        m_length--;
    }
    int top() {
        return m_data[0];
    }
    int back() {
        return m_data[m_length - 1];
    }

    friend std::ostream& operator<<(std::ostream& os, const DoubleQueue& queue) {
        for (unsigned int i = 0; i < queue.m_length; i++) {
            os << queue.m_data[i] << " ";
        }
        os << std::endl;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, DoubleQueue& queue) {
        while (true) {
            int item;
            is >> item;
            if (item == 0) {
                break;
            }
            queue.push_back(item);
        }
        return is;
    }

    ~DoubleQueue() {
        if (m_data) {
            delete[] m_data;
            m_data = nullptr;
        }
    }

    DoubleQueue(DoubleQueue& other) {
        m_capacity = other.m_capacity;
        m_length = other.m_length;
        m_data = new int[other.m_capacity];
        for (unsigned int i = 0; i < other.m_length; i++)
            m_data[i] = other.m_data[i];
    }

    DoubleQueue& operator=(const DoubleQueue& other) {
        if (this != &other) {
            delete[] m_data;
            m_capacity = other.m_capacity;
            m_length = other.m_length;
            m_data = new int[other.m_capacity];
            for (unsigned int i = 0; i < other.m_length; i++)
                m_data[i] = other.m_data[i];
        }
        return *this;
    }
private:
    int* m_data;
    unsigned int m_length;
    unsigned int m_capacity;
};

