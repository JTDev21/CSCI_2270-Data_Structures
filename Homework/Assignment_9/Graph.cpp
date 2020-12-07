#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>
#include <limits.h>

using namespace std;

void Graph::createEdge(string v1, string v2, int num){
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == v1)
        {
            for(int j = 0; j < vertices.size(); j++)
            {
                if(vertices[j]->name == v2)
                {
                    adjVertex adj1;
                    adj1.v = vertices[j];
                    adj1.weight = num;
                    vertices[i]->adj.push_back(adj1);

                    adjVertex adj2;
                    adj2.v = vertices[i];
                    adj2.weight = num;
                    vertices[j]->adj.push_back(adj2);
                }
            }
        }
    }
}

void Graph::insertVertex(string n){
    vertex *new_VTX = new vertex;
    new_VTX->name = n;
    vertices.push_back(new_VTX);
}

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    // cout<<"here"<<vertices.size()<<endl;
    for(unsigned int i = 0; i < vertices.size(); i++){
        cout<<vertices[i]->name<<":"<<endl;
        for(unsigned int j = 0; j < vertices[i]->adj.size(); j++){
            cout<<" --> "<< vertices[i]->adj[j].v->name << " "<<vertices[i]->adj[j].weight<<endl;
        }
        cout<<endl;
    }
}

void Graph::traverseWithDijkstra(string start){
    vertex *sourceVertex;
    for(int i = 0; i < vertices.size(); i++)
    {
        vertices[i]->distance = 100000000; // Use an arbitrarily large int
        if(vertices[i]->name == start)
        {
            sourceVertex = vertices[i];
            sourceVertex->distance = 0;
            sourceVertex->pred = NULL;
        }
    }

    std::queue <vertex*> q;
    q.push(sourceVertex);

    while(!q.empty())
    {
        vertex *u = q.front();
        q.pop();

        for(int i = 0; i < u->adj.size(); i++)
        {
            if(u->distance + u->adj[i].weight < u->adj[i].v->distance)
            {
                u->adj[i].v->distance = u->distance + u->adj[i].weight;
                u->adj[i].v->pred = u;
                // std::cout << u->adj[i].v->name << " | Distance: " << u->adj[i].v->distance << std::endl;
                q.push(u->adj[i].v);
            }
        }
    }
    // for(int i = 0; i < vertices.size(); i++)
    // {
    //     std::cout << vertices[i]->name << " | Distance: " << vertices[i]->distance << std::endl;
    // }
}

//--------------------------Second Version of Dijkstra----------------------
void Graph::traverseWithDijkstra2(string start){
    vertex *sourceVertex;
    for(int i = 0; i < vertices.size(); i++)
    {
        vertices[i]->distance = INT_MAX; // Use an arbitrarily large int
        vertices[i]->visited = false;
        if(vertices[i]->name == start)
        {
            sourceVertex = vertices[i];
            vertices[i]->visited = true;
            sourceVertex->distance = 0;
            sourceVertex->pred = NULL;
        }
    }

    std::vector <vertex*> solvedList;
    solvedList.push_back(sourceVertex);
    bool allSolved = false;

    while(!allSolved)
    {
        int minDist = INT_MAX;
        vertex *solvedV = NULL;
        allSolved = true;
        for(int i = 0; i < solvedList.size(); i++)
        {
            vertex *s = solvedList[i];
            for(int j = 0 ; j < s->adj.size(); j++)
            {
                if(!s->adj[j].v->visited)
                {
                    int dist = s->distance + s->adj[j].weight;
                    if(dist < minDist)
                    {
                        solvedV = s->adj[j].v;
                        minDist = dist;
                    }
                    allSolved = false;
                }
            }
        }
        if(!allSolved)
        {
            solvedV->distance = minDist;
            solvedV->visited = true;
            solvedList.push_back(solvedV);
        }
    }
    // for(int i = 0; i < vertices.size(); i++)
    // {
    //     std::cout << vertices[i]->name << " | Distance: " << vertices[i]->distance << std::endl;
    // }
}
//-------------------------------------------------------------------------

//---------------------------------DFS Algorithm --------------------------
void dfs(vertex *vtx)
{
    std::cout << vtx->name << " -> ";
    vtx->visited = true;
    for(int i = 0; i < vtx->adj.size(); i++)
    {
        if(vtx->adj[i].v->visited == false)
        {
            dfs(vtx->adj[i].v);
        }
    }
}

void Graph::depthFirstTraversal(string sourceVertex)
{
    // Search for source vertice
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == sourceVertex)
            dfs(vertices[i]);
    }
    std::cout << "DONE" << std::endl;
}
//-----------------------------------------------------------

vertex *printPath(vertex *source)
{
    if(source == NULL) return NULL;
    printPath(source->pred);
    std::cout << source->name << " -> ";
}

void Graph::minDistPath(string source, string destination) {
    traverseWithDijkstra(source);
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == source)
            vertices[i]->pred = NULL;

        if(vertices[i]->name == destination)
        {
            printPath(vertices[i]);
            cout << "DONE [" << vertices[i]->distance << "]" << std::endl;
        }
    }



    // Prints second version of Dijkstra
    traverseWithDijkstra2(source);
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == source)
            vertices[i]->pred = NULL;

        if(vertices[i]->name == destination)
        {
            printPath(vertices[i]);
            cout << "DONE [" << vertices[i]->distance << "]" << std::endl;
        }
    }
}