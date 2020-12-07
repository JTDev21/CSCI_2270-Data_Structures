#include <iostream>
#include "Graph.hpp"

int main()
{
    Graph graph;
    graph.addVertex("ATLS");
    graph.addVertex("EC");
    graph.addVertex("AERO");
    graph.addVertex("CHEM");
    graph.addVertex("DUAN");
    graph.addVertex("FLMG");
    graph.addVertex("MUS");
    graph.addVertex("MATH");


    graph.addEdge("ATLS", "EC");
    graph.addEdge("ATLS", "AERO");
    graph.addEdge("CHEM", "EC");
    graph.addEdge("AERO", "DUAN");
    graph.addEdge("MUS", "DUAN");
    graph.addEdge("MUS", "MATH");

    // graph.displayEdges();
    graph.breadthFirstTraverse("ATLS");
    // std::cout << graph.getConnectedBuildings() << std::endl;
    
    return 0;
}