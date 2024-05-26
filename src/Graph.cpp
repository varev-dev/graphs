//
// Created by varev on 23.05.2024.
//

#include "../include/Graph.h"

void Graph::degreeSequence() {
    Vector<unsigned long long> degrees(this->vertices.getSize());

    for (unsigned long long i = 0; i < this->vertices.getSize(); i++)
        degrees.push_back(this->vertices[i].getSize());

    degrees.sort(0, degrees.getSize() - 1);
    degrees.print();
}

void Graph::connectedComponents() {
    printf("?\n");
}

void Graph::bipartiteness() {
    printf("?\n");
}

void Graph::verticesEccentricity() {
    printf("?\n");
}

void Graph::planarity() {
    printf("?\n");
}

void Graph::vertexColors() {
    printf("?\n");
    printf("?\n");
    printf("?\n");
}

void Graph::subgraphsC4() {
    printf("?\n");
}

void Graph::complementEdges() {
    printf("?\n");
}

Graph::Graph(const Vector<Vector<unsigned long long>>& vertices) : vertices(vertices) {
}

Graph::~Graph() = default;
