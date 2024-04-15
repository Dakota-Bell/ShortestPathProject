#include "Dijkstra.h"

//---------------------------------------------------------------------------------------- 
	// filename(): This constructor initializes a Dijkstra object, setting all distances 
	//		to a specified infinity value, marking all vertices as unvisited, and 
	//		initializing the adjacency matrix with zeros to indicate no direct 
	//		connections between vertices
		
	// Incoming Data: infinity- The value used to initialize distances for which no direct 
	//				paths are known
		
	// Outgoing Data: N/A
		
	// Author: Chhavi Chhavi
		
	// Tester: 
		
	// Notes: 
		
	//---------------------------------------------------------------------------------
template <typename T>
Dijkstra<T>::Dijkstra(T infinity) : INF(infinity) 
{
    // Initialize all adjacency matrix values to 0, indicating no edges
    for (int i = 0; i < MAX_V; ++i) 
    {
        for (int j = 0; j < MAX_V; ++j) 
        {
            adjMatrix[i][j] = 0;
        }

	// Distance from source to vertex i is infinity
        dist[i] = INF; 

	// Vertex i has not been visited
        visited[i] = false;
    }
}


//---------------------------------------------------------------------------------------- 
// dijkstra(): Implements the Dijkstra's algorithm to find the shortest paths from 
//		a given source vertex	to all other vertices in a graph with 
//		non-negative weights.
		
// Incoming Data: the starting location and number of vertices
		
// Outgoing Data: N/A
		
// Author: Chhavi Chhavi
		
// Tester: Dakota Bell
		
// Notes: 
		
//---------------------------------------------------------------------------------

template <typename T>
void Dijkstra<T>::run(int start, int n) 
{
    // Reinitialize distances and visited status for all vertices 
    for (int i = 0; i < n; i++) 
    {
        dist[i] = INF;
        visited[i] = false;
    }

    // Distance to the source is always zero
    dist[start] = 0;

    // Loop to visit each vertex
    for (int i = 0; i < n; ++i) 
    {
        // Vertex with the smallest distance not yet visited
	int u = -1;  

        // Find the unvisited vertex with the smallest distance
        for (int j = 0; j < n; ++j) 
        {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) 
            {
                u = j;
            }
        }

        // If the smallest distance is infinity, the remaining vertices are unreachable
        if (dist[u] == INF) 
        {
            break;
        }

        // Mark the vertex as visited
        visited[u] = true;

        // Update the distance to the neighboring vertices
        for (int v = 0; v < n; ++v) 
        {
            if (adjMatrix[u][v] != 0 && dist[u] + adjMatrix[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }
}
