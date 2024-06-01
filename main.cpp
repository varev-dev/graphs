#include "include/Vector.h"
#include "include/Graph.h"

void readVertices(unsigned int n, Vector<Vector<unsigned int>>& vertices) {
    unsigned int size;
    while (n) {
        scanf("%u", &size);
        auto* vertex = new Vector<unsigned int>(size);
        unsigned int value = 0;
        while (size && std::cin >> value) {
            vertex->push_back(value);
            size--;
        }
        vertex->sort(0, vertex->getSize()-1, Vector<unsigned int>::ASCENDING);
        vertices.push_back(*vertex);
        delete vertex;
        n--;
    }
}

int main() {
    unsigned int graphs;
    scanf("%u", &graphs);
    while (graphs) {
        unsigned int n;
        scanf("%u", &n);
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
