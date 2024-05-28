//
// Created by varev on 23.05.2024.
//

#include "../include/Graph.h"
#include "../include/Queue.h"

#define UNCHECKED 0
#define STAGED 1
#define VISITED 2

Graph::Graph(unsigned long long vert) {
    vertices = Vector<Vector<unsigned long long>>(vert);
}

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

void Graph::connectedComponents() {
    auto* status = new char[vertices.getSize()];
    unsigned long long counter = 0;

    for (unsigned long long i = 0; i < vertices.getSize(); i++)
        status[i] = UNCHECKED;

    for (unsigned long long i = 0llu; i < vertices.getSize(); i++) {
        if (status[i] != UNCHECKED)
            continue;

        Queue<unsigned long long> queue(vertices.getSize());

        status[i] = STAGED;
        queue.enqueue(i);

        while (!queue.isEmpty()) {
            unsigned long long current = queue.dequeue();

            for (unsigned long long j = 0llu; j < vertices[current].getSize(); j++) {
                unsigned long long check = vertices[current][j] - 1llu;

                if (status[check] != UNCHECKED) {
                    continue;
                }

                status[check] = STAGED;
                queue.enqueue(check);
                status[current] = VISITED;
            }
        }
        counter++;
    }
    delete[] status;

    printf("%llu\n", counter);
}

void Graph::bipartiteness() {
    char* status = new char[vertices.getSize()];
    char* side = new char[vertices.getSize()];
    Queue<unsigned long long> queue(vertices.getSize());

    for (unsigned long long i = 0llu; i < vertices.getSize(); i++) {
        status[i] = 0;
        side[i] = 0;
    }

    for (unsigned long long vertex = 0; vertex < vertices.getSize(); vertex++) {
        if (status[vertex] != 0)
            continue;
        status[vertex] = STAGED;
        queue.enqueue(vertex);
        side[vertex] = 1;

        while (!queue.isEmpty()) {
            unsigned long long current = queue.dequeue();

            for (unsigned long long i = 0llu; i < vertices[current].getSize(); i++) {
                unsigned long long check = vertices[current][i] - 1llu;

                if (side[check] == 0)
                    side[check] = side[current] == 1 ? 2 : 1;

                if (status[check] != UNCHECKED) {
                    if (side[check] == side[current]) {
                        printf("%c\n", 'F');
                        delete[] side;
                        delete[] status;
                        return;
                    }
                    continue;
                }
                status[check] = STAGED;
                queue.enqueue(check);
                status[current] = VISITED;
            }
        }
    }

    printf("%c\n", 'T');
    delete[] side;
    delete[] status;
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

    printf("%llu\n", complement_edges);
}

Vector<Vector<unsigned long long>>& Graph::getVertices() {
    return vertices;
}
