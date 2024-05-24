//
// Created by varev on 24.05.2024.
//

#ifndef GRAPHS_VECTOR_H
#define GRAPHS_VECTOR_H

#include <cstddef>

#define uint64_t unsigned long long
#define RESIZE_SCALE 2
#define INIT_CAPACITY 3

template <typename T>
class Vector {
private:
    size_t size, capacity;
    T* data;

public:
    Vector();
    explicit Vector(size_t init_capacity);
    ~Vector();

    size_t getSize();
    void resize(size_t new_capacity);

    void push_back(const T& value);
    void print() const;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;
};

#include "../src/Vector.tpp"

#endif //GRAPHS_VECTOR_H
