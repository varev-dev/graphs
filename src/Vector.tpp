//
// Created by varev on 24.05.2024.
//

#ifndef GRAPHS_VECTOR_TPP
#define GRAPHS_VECTOR_TPP

#include <cstdio>
#include <stdexcept>
#include <iostream>
#include "../include/Vector.h"

template<typename T>
Vector<T>::Vector() : size(0llu), capacity(INIT_CAPACITY) {
    data = new T[capacity];
}

template<typename T>
Vector<T>::Vector(unsigned long long init_capacity) : size(0), capacity(init_capacity) {
    data = new T[capacity];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other) : size(other.size), capacity(other.capacity), data(nullptr) {
    if (capacity > 0) {
        data = new T[capacity];
        for (unsigned long long i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
}

template<typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template<typename T>
unsigned long long Vector<T>::getSize() const {
    return this->size;
}

template<typename T>
void Vector<T>::resize(unsigned long long new_capacity) {
    T* new_data = new T[new_capacity];

    for (unsigned long long i = 0llu; i < size; i++)
        new_data[i] = data[i];
    delete[] data;

    data = new_data;
    capacity = new_capacity;
}

template<typename T>
void Vector<T>::push_back(const T &value) {
    if (capacity <= size)
        resize(capacity * RESIZE_SCALE);
    data[size++] = value;
}

template<typename T>
void Vector<T>::print() const {
    for (unsigned long long i = 0llu; i < size; i++)
        printf("%llu ", data[i]);
    printf("\n");
}

template<typename T>
bool Vector<T>::isSorted() const {
    for (unsigned long long i = 0llu; i < size-1; i++) {
        if (data[i] < data[i+1])
            return false;
    }
    return true;
}

template<typename T>
void Vector<T>::sort(unsigned long long leftIter, unsigned long long rightIter) {
    if (leftIter >= rightIter || rightIter >= size || isSorted())
        return;

    unsigned long long pivot = partition(leftIter, rightIter);
    sort(leftIter, pivot);
    sort(pivot+1, rightIter);
}

template <typename T>
unsigned long long Vector<T>::partition(unsigned long long leftIter, unsigned long long rightIter) {
    T pivot = data[leftIter];

    while (true) {
        while (data[leftIter] > pivot)
            leftIter++;
        while (data[rightIter] < pivot)
            rightIter--;

        if (leftIter < rightIter) {
            T temp = data[leftIter];
            data[leftIter] = data[rightIter];
            data[rightIter] = temp;
        } else {
            return rightIter;
        }

        leftIter++;
        rightIter--;
    }
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T> &other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = nullptr;
        if (capacity > 0) {
            data = new T[capacity];
            for (unsigned long long i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
    }
    return *this;
}

template<typename T>
T& Vector<T>::operator[](unsigned long long index) {
    if (index >= size)
        throw std::out_of_range("index out of range");
    return data[index];
}

template<typename T>
const T& Vector<T>::operator[](unsigned long long index) const {
    if (index >= size)
        throw std::out_of_range("index out of range");
    return data[index];
}

#endif
