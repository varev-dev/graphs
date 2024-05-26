//
// Created by varev on 24.05.2024.
//

#ifndef GRAPHS_VECTOR_H
#define GRAPHS_VECTOR_H

#include <cstddef>

#define RESIZE_SCALE 2
#define INIT_CAPACITY 3

template <typename T>
class Vector {
private:
    unsigned long long size, capacity;
    T* data;

    [[nodiscard]] bool isSorted() const;
    unsigned long long partition(unsigned long long leftIter, unsigned long long rightIter);

public:
    Vector();
    explicit Vector(unsigned long long init_capacity);
    Vector(const Vector<T>& other);
    ~Vector();

    [[nodiscard]] unsigned long long getSize() const;
    void resize(unsigned long long new_capacity);

    void push_back(const T& value);
    void print() const;

    void sort(unsigned long long leftIter, unsigned long long rightIter);

    Vector<T>& operator=(const Vector& other);
    T& operator[](unsigned long long index);
    const T& operator[](unsigned long long index) const;
};

#include "../src/Vector.tpp"

#endif //GRAPHS_VECTOR_H
