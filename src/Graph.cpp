//
// Created by varev on 23.05.2024.
//

#include "../include/Graph.h"
#include "../include/Queue.h"

#define UNCHECKED 0
#define STAGED 1
#define VISITED 2

Graph::Graph(const Vector<Vector<unsigned long long>>& vertices) : vertices(vertices) {
}

Graph::~Graph() = default;

void Graph::degreeSequence() {
    Vector<unsigned long long> degrees(this->vertices.getSize());

    for (unsigned long long i = 0; i < this->vertices.getSize(); i++)
        degrees.push_back(this->vertices[i].getSize());

    degrees.sort(0, degrees.getSize() - 1);
    degrees.print();
}

void Graph::bfs(unsigned long long vertex_id, unsigned long long *status) {
    if (!status) {
        status = new unsigned long long[vertices.getSize()];
        for (unsigned long long i = 0; i < vertices.getSize(); ++i)
            status[i] = UNCHECKED;
    }
    auto* parent = new unsigned long long[vertices.getSize()];
    auto* queue = new Queue<unsigned long long>(vertices.getSize());

    status[vertex_id] = STAGED;
    parent[vertex_id] = vertex_id;
    queue->enqueue(vertex_id);

    while (!queue->isEmpty()) {
        unsigned long long current = queue->dequeue();

        for (unsigned long long i = 0llu; i < vertices[current].getSize(); i++) {
            if (status[vertices[current][i]] != UNCHECKED)
                continue;

            status[vertices[current][i]] = STAGED;
            parent[vertices[current][i]] = current;
            queue->enqueue(vertices[current][i]);
            status[current] = VISITED;
        }
    }
}

void Graph::connectedComponents() {
    auto* status = new unsigned long long[vertices.getSize()];
    unsigned long long counter = 0;

    for (unsigned long long i = 0; i < vertices.getSize(); i++)
        status[i] = UNCHECKED;

    for (unsigned long long i = 0llu; i < vertices.getSize(); i++) {
        if (status[i] != UNCHECKED)
            continue;

        bfs(i, status);
        counter++;
    }

    printf("%llu\n", counter);
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
    unsigned long long max_edges = vertices.getSize() * (vertices.getSize() - 1) / 2;
    unsigned long long current_edges = 0;

    for (unsigned long long i = 0; i < vertices.getSize(); i++)
        current_edges += vertices[i].getSize();
    current_edges /= 2;

    unsigned long long complement_edges = max_edges - current_edges;

    printf("%llu", complement_edges);
}
