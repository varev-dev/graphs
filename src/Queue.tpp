//
// Created by varev on 27.05.2024.
//

#ifndef GRAPHS_QUEUE_TPP
#define GRAPHS_QUEUE_TPP

#include "../include/Queue.h"

template<typename T>
Queue<T>::Queue(unsigned int init_capacity) : size(0), capacity(init_capacity) {
    data = new T[init_capacity];
}

template<typename T>
Queue<T>::~Queue() {
    delete[] data;
}

template<typename T>
void Queue<T>::resize() {
    T* new_data = new T[capacity * RESIZE_SCALE];

    for (unsigned int i = 0; i < size; i++)
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

    data[size] = value;
    size++;
}

template<typename T>
T Queue<T>::dequeue() {
    if (size <= 0)
        throw std::out_of_range("queue is empty");
    T value = data[0];
    for (unsigned int i = 1; i < size; i++)
        data[i-1] = data[i];
    size--;
    return value;
}

#endif //GRAPHS_QUEUE_TPP
