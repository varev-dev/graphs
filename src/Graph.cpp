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

    degrees.sort(0, degrees.getSize() - 1, Vector<unsigned int>::DESCENDING);
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

int Graph::firstAvailableColor(const Vector<int>& colors, const Vector<int>& available) {
    for (int color = 0; color < colors.getSize(); color++) {
        if (available[color])
            return color;
    }
    return colors.getSize();
}

void Graph::colorsNaive() {
    unsigned int size = vertices.getSize();
    Vector<int> colors(size, -1);

    colors[0] = 0;
    printf("%d ", 1);

    Vector<int> available(size, 1);
    for (unsigned int u = 1; u < size; u++) {
        for (unsigned int i = 0; i < vertices[u].getSize(); i++) {
            unsigned int v = vertices[u][i]-1;
            if (v >= u) break;
            if (colors[v] != -1)
                available[colors[v]] = 0;
        }

        int color = firstAvailableColor(colors, available);
        colors[u] = color;
        printf("%d ", color+1);

        for (unsigned int i = 0; i < vertices[u].getSize(); i++) {
            unsigned int v = vertices[u][i]-1;
            if (v >= u) break;
            available[colors[v]] = 1;
        }
    }
    printf("\n");
}

void Graph::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

unsigned int Graph::partition(Vector<int>& indices, const Vector<Vector<unsigned int>>& vertices, int low, int high) {
    unsigned int pivotIndex = indices[high];
    unsigned int pivotSize = vertices[pivotIndex].getSize();
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (vertices[indices[j]].getSize() > pivotSize || (vertices[indices[j]].getSize() == pivotSize && indices[j] < pivotIndex)) {
            ++i;
            swap(indices[i], indices[j]);
        }
    }
    swap(indices[i + 1], indices[high]);
    return i + 1;
}

void Graph::sortIndicesByEdges(Vector<int>& indices, const Vector<Vector<unsigned int>>& vertices, int low, int high) {
    if (low < high) {
        int pi = partition(indices, vertices, low, high);

        sortIndicesByEdges(indices, vertices, low, pi - 1);
        sortIndicesByEdges(indices, vertices, pi + 1, high);
    }
}

Vector<int> Graph::sort(const Vector<int>& indices, const Vector<Vector<unsigned int>>& vertices) {
    Vector<int> sortedIndices(indices);

    sortIndicesByEdges(sortedIndices, vertices, 0, sortedIndices.getSize() - 1);

    return sortedIndices;
}

void Graph::colorsLF() {
    unsigned int size = vertices.getSize();
    Vector<int> colors(size, -1);
    Vector<int> indices(size);

    for (int i = 0; i < size; i++)
        indices.push_back( i);
    indices = sort(indices, vertices);

    colors[indices[0]] = 0;
    Vector<int> available(size, 1);
    for (unsigned int i = 1; i < size; i++) {
        int u = indices[i];
        unsigned int edges = vertices[u].getSize();

        for (unsigned int j = 0; j < edges; j++) {
            unsigned int v = vertices[u][j]-1;
            if (colors[v] != -1)
                available[colors[v]] = 0;
        }

        int color = firstAvailableColor(colors, available);
        colors[u] = color;

        for (unsigned int j = 0; j < edges; j++) {
            unsigned int v = vertices[u][j]-1;
            if (colors[v] != -1)
                available[colors[v]] = 1;
        }
    }

    for (unsigned int i = 0; i < size; i++)
        printf("%d ", colors[i]+1);
    printf("\n");
}

void Graph::vertexColors() {
    colorsNaive();
    colorsLF();
    printf("?\n");
}

/**
 * Based on a research paper "Simple and efficient four-cycle counting on sparse graphs"
 * @authors: Paul Burkhardt and David G. Harris
 * @source: https://arxiv.org/pdf/2303.06090
 */
unsigned long long Graph::countC4() {
    unsigned int size = vertices.getSize();
    unsigned long long counter = 0ull;

    Vector<unsigned int> L(vertices.getSize(), 0);

    for (unsigned int v = 0; v < size; ++v) {
        if (vertices[v].getSize() < 2)
            continue;

        for (unsigned int i = 0; i < vertices[v].getSize(); ++i) {
            unsigned int u = vertices[v][i]-1;
            if (u >= v) break;

            for (unsigned int j = 0; j < vertices[u].getSize(); ++j) {
                unsigned int y = vertices[u][j]-1;
                if (y >= v) break;

                counter += (unsigned long long) L[y];
                L[y]++;
            }
        }

        for (unsigned int i = 0; i < vertices[v].getSize(); ++i) {
            unsigned int u = vertices[v][i]-1;
            if (u >= v) break;

            for (unsigned int j = 0; j < vertices[u].getSize(); ++j) {
                unsigned int y = vertices[u][j]-1;
                if (y >= v) break;

                L[y] = 0;
            }
        }
    }
    return counter;
}

void Graph::subgraphsC4() {
    printf("%llu\n", countC4());
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
