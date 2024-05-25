//
// Created by varev on 23.05.2024.
//

#include "../include/Graph.h"

Vector<int>& Graph::degreeSequence() {
    auto* degrees = new Vector<int>(this->vertices.getSize());

    for (size_t i = 0; i < this->vertices.getSize(); i++)
        degrees->push_back( (int) this->vertices[i].getSize());

    degrees->sort(0, degrees->getSize()-1);
    degrees->print();
    return *degrees;
}

Graph::Graph(const Vector<Vector<int>>& vertices) : vertices(vertices) {
}

Graph::~Graph() {
    delete &vertices;
}
