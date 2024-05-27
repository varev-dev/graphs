//
// Created by varev on 27.05.2024.
//

#ifndef GRAPHS_QUEUE_TPP
#define GRAPHS_QUEUE_TPP

#include "../include/Queue.h"

template<typename T>
Queue<T>::Queue(unsigned long long init_capacity) : size(0), capacity(init_capacity) {
    data = new T[init_capacity];
}

template<typename T>
Queue<T>::Queue(const Queue<T>& other) : size(other.size), capacity(other.capacity) {
    if (capacity > 0) {
        data = new T[capacity];
        for (unsigned long long i = 0; i < size; i++)
            data[i] = other.data[i];
    }
}

template<typename T>
Queue<T>::~Queue() {
    delete[] data;
}

template<typename T>
unsigned long long Queue<T>::getSize() const {
    return size;
}

template<typename T>
T* Queue<T>::getData() const {
    return data;
}

template<typename T>
void Queue<T>::resize() {
    T* new_data = new T[capacity * RESIZE_SCALE];

    for (unsigned long long i = 0llu; i < size; i++)
        new_data[i] = data[i];

    delete[] data;
    data = new_data;
    capacity = capacity * RESIZE_SCALE;
}

template<typename T>
bool Queue<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
void Queue<T>::enqueue(const T& value) {
    if (size >= capacity)
        resize();

    data[size++] = value;
}

template<typename T>
T& Queue<T>::dequeue() {
    if (size <= 0)
        throw std::out_of_range("queue is empty");
    T& value = data[0];
    for (unsigned long long i = 1llu; i < size; i++)
        data[i-1llu] = data[i];
    size--;
    return value;
}

template<typename T>
T& Queue<T>::head() {
    return data[0];
}

template<typename T>
T& Queue<T>::tail() {
    return data[size-1llu];
}

#endif //GRAPHS_QUEUE_TPP
