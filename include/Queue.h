//
// Created by varev on 27.05.2024.
//

#ifndef GRAPHS_QUEUE_H
#define GRAPHS_QUEUE_H

#define RESIZE_SCALE 2

template<typename T>
class Queue {
private:
    unsigned long long size, capacity;
    T* data;

    void resize();
public:
    explicit Queue(unsigned long long init_capacity);
    Queue(const Queue<T>& other);
    ~Queue();

    [[nodiscard]] unsigned long long getSize() const;
    T* getData() const;

    [[nodiscard]] bool isEmpty() const;
    void print();

    void enqueue(const T& value);
    T dequeue();

    T& head();
    T& tail();
};

#include "../src/Queue.tpp"

#endif //GRAPHS_QUEUE_H
