#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <iostream>

class Dijkstra
{
    public:
        static const int MAX_V = 100;  // Max number of vertices, made public and static
        static const int INF = 1e9;    // Representing infinity, made public and static

        Dijkstra();                     // Constructor declaration
        void run(int start, int n);     // Corrected function declaration

    private:
        int dist[MAX_V];            // Stores shortest distance from source
        bool visited[MAX_V];        // Keeps track of visited vertices
        int adjMatrix[MAX_V][MAX_V]; // Adjacency matrix for graph weights
};

#endif
