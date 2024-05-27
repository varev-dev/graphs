#include "include/Vector.h"
#include "include/Graph.h"

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
    unsigned long long graphs;
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
