//
// Created by varev on 24.05.2024.
//

#ifndef GRAPHS_VECTOR_H
#define GRAPHS_VECTOR_H

#define uint64_t unsigned long long

template <typename T>
class Vector {
private:
    uint64_t size, capacity;
    T* data;

public:
    Vector(uint64_t size);
    ~Vector();

    unsigned long long getSize();
    void resize(uint64_t size);

    T& operator[](uint64_t size);
    const T& operator[](uint64_t) const;
    Vector& operator=(const T& value);

};

#endif //GRAPHS_VECTOR_H
