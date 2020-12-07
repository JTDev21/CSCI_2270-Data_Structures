#include <iostream>
#include "Graph.hpp"
using namespace std;

int main()
{
    // Graph graph;
    // graph.insertVertex("Aurora");
    // graph.insertVertex("Bloomington");
    // graph.insertVertex("Cheyenne");
    // graph.insertVertex("Denver");
    // graph.insertVertex("Fruita");

    // graph.createEdge("Aurora", "Bloomington", 5);
    // graph.createEdge("Aurora", "Cheyenne", 10);
    // graph.createEdge("Aurora", "Fruita", 30);
    // graph.createEdge("Bloomington", "Denver", 40);
    // graph.createEdge("Bloomington", "Fruita", 15);
    // graph.createEdge("Cheyenne", "Denver", 10);

    // // graph.traverseWithDijkstra("Bloomington");
    // graph.minDistPath("Aurora", "Denver");

    Graph graph;
    // graph.insertVertex("A");
    // graph.insertVertex("B");
    // graph.insertVertex("C");
    // graph.insertVertex("D");
    // graph.insertVertex("E");
    // graph.insertVertex("F");
    // graph.insertVertex("G");

    // graph.createEdge("A", "C", 3);
    // graph.createEdge("A", "B", 1);
    // graph.createEdge("C", "B", 1);
    // graph.createEdge("B", "G", 3);
    // graph.createEdge("B", "D", 2);
    // graph.createEdge("D", "F", 4);
    // graph.createEdge("B", "E", 4);
    // graph.createEdge("E", "F", 5);

    // // graph.traverseWithDijkstra("A");
    graph.minDistPath("A", "F");
    return 0;
}