//
// Created by varev on 27.05.2024.
//

#ifndef GRAPHS_QUEUE_H
#define GRAPHS_QUEUE_H

#define RESIZE_SCALE 2

template<typename T>
class Queue {
private:
    unsigned int size, capacity;
    T* data;

    void resize();
public:
    explicit Queue(unsigned int init_capacity);
    ~Queue();

    [[nodiscard]] bool isEmpty() const;

    void enqueue(const T& value);
    T dequeue();
};

#include "../src/Queue.tpp"

#endif //GRAPHS_QUEUE_H
