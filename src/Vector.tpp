//
// Created by varev on 24.05.2024.
//

#ifndef GRAPHS_VECTOR_TPP
#define GRAPHS_VECTOR_TPP

#include <cstdio>
#include <stdexcept>
#include "../include/Vector.h"


template<typename T>
Vector<T>::Vector() : size(0), capacity(INIT_CAPACITY) {
    data = new T[capacity];
}

template<typename T>
Vector<T>::Vector(size_t init_capacity) : size(0), capacity(init_capacity) {
    data = new T[capacity];
}

template<typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template<typename T>
size_t Vector<T>::getSize() {
    return this->size;
}

template<typename T>
void Vector<T>::resize(size_t new_capacity) {
    T* new_data = new T[new_capacity];

    for (size_t i = 0; i < size; i++)
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
    for (size_t i = 0; i < size; i++)
        printf("%d\n", data[i]);
}

template<typename T>
T& Vector<T>::operator[](uint64_t index) {
    if (index >= size)
        throw std::out_of_range("index out of range");
    return data[index];
}

template<typename T>
const T& Vector<T>::operator[](uint64_t index) const {
    if (index >= size)
        throw std::out_of_range("index out of range");
    return data[index];
}

#endif
