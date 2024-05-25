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

Vector<Vector<int>>& readVertexes(size_t n) {
    auto* data = new Vector<Vector<int>>(n);
    while (n) {
        size_t size = readNextNumber();
        auto* vertex = new Vector<int>(size);

        while (size) {
            int value = (int) readNextNumber();
            vertex->push_back(value);
            size--;
        }
        data->push_back(*vertex);
        n--;
    }
    return *data;
}

int main() {
    size_t graphs = readNextNumber();
    while (graphs) {
        size_t n = readNextNumber();
        auto* vertices = &readVertexes(n);
        auto* graph = new Graph(*vertices);
        graph->degreeSequence();
        graphs--;
    }
    return 0;
}
