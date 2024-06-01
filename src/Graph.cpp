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

bool Graph::isNeighbor(unsigned int first, unsigned int second) {
    if (vertices[first].getSize() > vertices[second].getSize()) {
        unsigned int temp = first;
        first = second;
        second = temp;
    }

    for (unsigned int i = 0; i < vertices[first].getSize(); i++) {
        if (vertices[first][i]-1 == second)
            return true;
    }

    return false;
}

unsigned int Graph::numberOfCommonNeighbor(unsigned int first, unsigned int second) {
    bool* check = new bool[vertices.getSize()];
    unsigned int counter = 0;

    for (unsigned int i = 0; i < vertices.getSize(); i++)
        check[i] = false;

    for (unsigned int i = 0; i < vertices[first].getSize(); i++)
        check[vertices[first][i]-1] = true;

    for (unsigned int i = 0; i < vertices[second].getSize(); i++) {
        if (check[vertices[second][i]-1])
            counter++;
    }

    delete[] check;
    return counter;
}

unsigned int Graph::countC4() {
    unsigned int size = vertices.getSize();
    unsigned int counter = 0;

    for (unsigned int u = 0; u < size; u++) {
        for (unsigned int v = 0; v < size; v++) {
            if (u == v)
                continue;
            unsigned int common = numberOfCommonNeighbor(u, v);
            counter += common * (common - 1);
        }
    }
    return counter/8;
}

void Graph::subgraphsC4() {
    printf("%u\n", countC4());
}

void Graph::complementEdges() {
    unsigned long long max_edges = (unsigned long long) vertices.getSize() * (vertices.getSize() - 1llu) / 2;
    unsigned long long current_edges = 0llu;

    for (unsigned int i = 0; i < vertices.getSize(); i++)
        current_edges += (unsigned long long) vertices[i].getSize();
    current_edges /= 2;

    unsigned long long complement_edges = max_edges - current_edges;

    printf("%llu\n", complement_edges);
}

Vector<Vector<unsigned int>>& Graph::getVertices() {
    return vertices;
}
