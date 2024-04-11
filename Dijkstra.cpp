#include "Dijkstra.h"
using namespace std;
// Constructor

template <typename T>
Dijkstra<T>::Dijkstra() 
{
    // Initialize all adjacency matrix values to 0, indicating no edges
    for (int i = 0; i < MAX_V; ++i) 
    {
        for (int j = 0; j < MAX_V; ++j) 
        {
            adjMatrix[i][j] = 0;
        }
        
        dist[i] = INF;
        visited[i] = false;
    }
}
//---------------------------------------------------------------------------------------- 
	// dijkstra(): Implements the Dijkstra's algorithm to find the shortest paths from a given source vertex
    //             to all other vertices in a graph with non-negative weights.
		
	// Incoming Data: the starting location and number of vertices
		
	// Outgoing Data: N/A
		
	// Author: Chhavi Chhavi
		
	// Tester: 
		
	// Notes: Kara Chobot - updated template Syntax
		
	// --------------------------------------------------------------------------- 

template <typename>
void Dijkstra<T>::run(int start, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[start] = 0;

    for (int i = 0; i < n; ++i) 
    {
        int u = -1; // Vertex with the smallest known distance

        for (int j = 0; j < n; ++j) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == INF) {
            break;
        }

        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (adjMatrix[u][v] != 0 && dist[u] + adjMatrix[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }
}
