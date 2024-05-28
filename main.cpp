#include "include/Vector.h"
#include "include/Graph.h"

void readVertices(unsigned long long n, Vector<Vector<unsigned long long>>& vertices) {
    unsigned long long size;
    while (n) {
        scanf("%llu", &size);
        auto* vertex = new Vector<unsigned long long>(size);
        unsigned long long value = 0;
        while (size && std::cin >> value) {
            vertex->push_back(value);
            size--;
        }
        vertices.push_back(*vertex);
        delete vertex;
        n--;
    }
}

int main() {
    unsigned long long graphs;
    scanf("%llu", &graphs);
    while (graphs) {
        unsigned long long n;
        scanf("%llu", &n);
        auto* graph = new Graph(n);
        readVertices(n, graph->getVertices());
        graph->degreeSequence();
        graph->connectedComponents();
        graph->bipartiteness();
        graph->verticesEccentricity();
        graph->planarity();
        graph->vertexColors();
        graph->subgraphsC4();
        graph->complementEdges();
        delete graph;
        graphs--;
    }
    return 0;
}
