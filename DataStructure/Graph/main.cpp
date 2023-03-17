#include "Graph.hpp"

int main()
{
    Graph<int> g;
    g.addVertex("A");
    g.addVertex("B");
    g.addEdge("A", "B", 1);
    return 0;
}