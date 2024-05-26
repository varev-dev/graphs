#include "include/Vector.h"
#include "include/Graph.h"

size_t readNextNumber() {
    size_t value = 0;
    char in = 0;

    while (in != ' ' && in != '\n') {
        in = (char) getchar();

        if (in < '0' || in > '9')
            continue;

        value *= 10;
        value += in-'0';
    }

    return value;
}

Vector<Vector<unsigned long long>>* readVertices(unsigned long long n) {
    auto* data = new Vector<Vector<unsigned long long>>(n);
    unsigned long long size;
    while (n) {
        scanf("%llu", &size);
        auto* vertex = new Vector<unsigned long long>(size);
        unsigned long long value = 0;

        while (size && std::cin >> value) {
            vertex->push_back(value);
            size--;
        }
        data->push_back(*vertex);
        delete vertex;
        n--;
    }
    return data;
}

int main() {
    unsigned long long  graphs;
    scanf("%llu", &graphs);
    while (graphs) {
        unsigned long long n;
        scanf("%llu", &n);
        auto* vertices = readVertices(n);
        auto* graph = new Graph(*vertices);
        graph->degreeSequence();
        graph->connectedComponents();
        graph->bipartiteness();
        graph->verticesEccentricity();
        graph->planarity();
        graph->vertexColors();
        graph->subgraphsC4();
        graph->complementEdges();
        delete graph;
        delete vertices;
        graphs--;
    }
    return 0;
}
