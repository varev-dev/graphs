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
    unsigned int size, capacity;
    T* data;

public:
    enum Order {
        ASCENDING,
        DESCENDING
    };

    [[nodiscard]] bool isSorted(Order order) const;
    unsigned int partition(unsigned int leftIter, unsigned int rightIter, Order order);

    Vector();
    explicit Vector(unsigned int init_capacity);
    Vector(const Vector<T>& other);
    Vector(unsigned int init_capacity, unsigned int filled_with);
    ~Vector();

    [[nodiscard]] unsigned int getSize() const;
    void resize(unsigned int new_capacity);

    void push_back(const T& value);
    void print() const;

    bool contains(const T& value);
    void sort(unsigned int leftIter, unsigned int rightIter, Order order);
    Vector<T>& operator=(const Vector<T>& other);
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
};

#include "../src/Vector.tpp"

#endif //GRAPHS_VECTOR_H
