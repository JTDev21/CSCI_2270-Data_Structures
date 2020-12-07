#include <iostream>
#include <queue>
#include "Graph.hpp"

void Graph::addEdge(string v1, string v2)
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == v1)
        {
            for(int j = 0; j < vertices.size(); j++)
            {
                if(vertices[j]->name == v2 && i != j)
                {
                    adjVertex av1;
                    av1.v = vertices[j];
                    vertices[i]->adj.push_back(av1);

                    adjVertex av2;
                    av2.v = vertices[i];
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}

void Graph::addVertex(string name)
{
    vertex *newVtx = new vertex;
    newVtx->name = name;
    vertices.push_back(newVtx);
    // std::cout << "Pushed: " << name << std::endl;
}

void Graph::displayEdges()
{
    for(int i = 0; i < vertices.size(); i++)
    {
        std::cout << vertices[i]->name << " --> ";
        for(int j = 0; j < vertices[i]->adj.size(); j++)
        {
            std::cout << vertices[i]->adj[j].v->name << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::breadthFirstTraverse(string sourceVertex)
{
    std::queue <vertex*> vtxQueue;
    // Find source vertex
    for(int i = 0; i < vertices.size(); i++)
    {
        // std::cout << vertices[i]->name << " == " << sourceVertex << std::endl;
        if(vertices[i]->name == sourceVertex)
        {
            vertices[i]->visited = true;
            vtxQueue.push(vertices[i]);
            i = vertices.size(); // Stops for loop
        }
    }

    //BFS
    std::cout << "Starting vertex (root): " << vtxQueue.front()->name << "-> ";
    while(!vtxQueue.empty())
    {
        vertex *dequeuedVtx = vtxQueue.front();
        vtxQueue.pop();
        
        for(int i = 0; i < dequeuedVtx->adj.size(); i++)
        {
            if(!dequeuedVtx->adj[i].v->visited) // Checks if the adj vertex has been visited
            {
                dequeuedVtx->adj[i].v->visited = true;
                dequeuedVtx->adj[i].v->distance = dequeuedVtx->distance + 1;
                vtxQueue.push(dequeuedVtx->adj[i].v);
                std::cout << dequeuedVtx->adj[i].v->name << "(" << dequeuedVtx->adj[i].v->distance << ") ";
            }
        }
    }
    std::cout << std::endl;
}

vertex *dfs(vertex *sourceVtx)
{
    sourceVtx->visited = true;
    for(int i = 0; i < sourceVtx->adj.size(); i++)
    {
        // std::cout << sourceVtx->name << " | " << sourceVtx->visited << std::endl;
        if(!sourceVtx->adj[i].v->visited)
        {
            dfs(sourceVtx->adj[i].v);
        }
    }
}

int Graph::getConnectedBuildings()
{
    for(int i = 0; i < vertices.size(); i++)
        vertices[i]->visited = false;
        
    int connectedComponents = 0;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->visited == false)
        {
            dfs(vertices[i]);
            connectedComponents++;
        }
    }
    return connectedComponents;
}