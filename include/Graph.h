//
// Created by varev on 23.05.2024.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include "Vector.h"

class Graph {
private:
    Vector<Vector<unsigned long long>> vertices;

    void bfs(unsigned long long int vertex_id = 0, unsigned long long *status = nullptr);
public:
    explicit Graph(const Vector<Vector<unsigned long long>>& vertices);

    ~Graph();
    void degreeSequence();
    void connectedComponents();
    void bipartiteness();
    void verticesEccentricity();
    void planarity();
    void vertexColors();
    void subgraphsC4();

    void complementEdges();
};

#endif //GRAPHS_GRAPH_H
