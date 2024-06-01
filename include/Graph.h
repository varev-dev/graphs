//
// Created by varev on 23.05.2024.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include "Vector.h"

class Graph {
private:
    Vector<Vector<unsigned int>> vertices;

    unsigned int countC4();
public:
    explicit Graph(unsigned int vert);
    explicit Graph(const Vector<Vector<unsigned int>>& vertices);

    Vector<Vector<unsigned int>>& getVertices();

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
