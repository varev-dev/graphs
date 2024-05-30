//
// Created by varev on 23.05.2024.
//

#include "../include/Graph.h"
#include "../include/Queue.h"

#define UNCHECKED 0
#define STAGED 1
#define VISITED 2

Graph::Graph(unsigned int vert) {
    vertices = Vector<Vector<unsigned int>>(vert);
}

Graph::Graph(const Vector<Vector<unsigned int>>& vertices) : vertices(vertices) {
}

Graph::~Graph() = default;

void Graph::degreeSequence() {
    Vector<unsigned int> degrees(this->vertices.getSize());

    for (unsigned int i = 0; i < this->vertices.getSize(); i++)
        degrees.push_back(this->vertices[i].getSize());

    degrees.sort(0, degrees.getSize() - 1);
    degrees.print();
}

void Graph::connectedComponents() {
    auto* status = new char[vertices.getSize()];
    unsigned int counter = 0;

    for (unsigned int i = 0; i < vertices.getSize(); i++)
        status[i] = UNCHECKED;

    for (unsigned int i = 0; i < vertices.getSize(); i++) {
        if (status[i] != UNCHECKED)
            continue;

        Queue<unsigned int> queue(vertices.getSize());

        status[i] = STAGED;
        queue.enqueue(i);

        while (!queue.isEmpty()) {
            unsigned int current = queue.dequeue();

            for (unsigned int j = 0; j < vertices[current].getSize(); j++) {
                unsigned int check = vertices[current][j] - 1;

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

    printf("%u\n", counter);
}

void Graph::bipartiteness() {
    char* status = new char[vertices.getSize()];
    char* side = new char[vertices.getSize()];
    Queue<unsigned int> queue(vertices.getSize());

    for (unsigned int i = 0; i < vertices.getSize(); i++) {
        status[i] = 0;
        side[i] = 0;
    }

    for (unsigned int vertex = 0; vertex < vertices.getSize(); vertex++) {
        if (status[vertex] != 0)
            continue;
        status[vertex] = STAGED;
        queue.enqueue(vertex);
        side[vertex] = 1;

        while (!queue.isEmpty()) {
            unsigned int current = queue.dequeue();

            for (unsigned int i = 0; i < vertices[current].getSize(); i++) {
                unsigned int check = vertices[current][i] - 1;

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
    unsigned long long current_edges = 0llu;

    for (unsigned int i = 0; i < vertices.getSize(); i++)
        current_edges += vertices[i].getSize();
    current_edges /= 2;

    unsigned long long complement_edges = max_edges - current_edges;

    printf("%llu\n", complement_edges);
}

Vector<Vector<unsigned int>>& Graph::getVertices() {
    return vertices;
}
