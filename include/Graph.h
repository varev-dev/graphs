//
// Created by varev on 23.05.2024.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include "Vector.h"

class Graph {
private:
    Vector<Vector<int>> vertices;

public:
    explicit Graph(const Vector<Vector<int>>& vertices);
    ~Graph();
    Vector<int>& degreeSequence();
};

#endif //GRAPHS_GRAPH_H
