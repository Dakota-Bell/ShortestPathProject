#include <iostream>
#include "Dijkstra.h"

//Global variables
int adjMatrix[MAX_V][MAX_V]; 	// Adjacency matrix for graph weights
int dist[MAX_V]; 		        // Stores shortest distance from source
bool visited[MAX_V]; 	    	// Keeps track of visited vertices

//---------------------------------------------------------------------------------------- 
	// dijkstra(): Implements the Dijkstra's algorithm to find the shortest paths from a given source vertex
    //             to all other vertices in a graph with non-negative weights.
		
	// Incoming Data: the starting location and number of vertices
		
	// Outgoing Data: N/A
		
	// Author: Chhavi Chhavi
		
	// Tester: 
		
	// Notes: 
		
	// --------------------------------------------------------------------------- 

void dijkstra(int start, int n) 
{
    // Initialize distances as infinite and visited status as false for all vertices
    for (int i = 0; i < n; i++) 
    {
        dist[i] = INF;
        visited[i] = false;
    }

    // Distance from the start vertex to itself is always 0
    dist[start] = 0;

    // Main loop: runs 'n' times, each time selecting a new vertex to 'visit'
    for (int i = 0; i < n; ++i) 
    {
        int u = -1; // Variable to store the vertex with the smallest known distance so far

        // Find the unvisited vertex with the smallest distance
        for (int j = 0; j < n; ++j) 
        {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) 
            {
                u = j;
            }
        }

        // If the smallest distance is infinite, remaining vertices are unreachable
        if (dist[u] == INF) 
        {
            break;
        }

        // Mark the selected vertex as visited
        visited[u] = true;

        // Update the distance to each neighboring vertex of 'u'
        for (int v = 0; v < n; ++v) 
        {
            // If there's an edge from 'u' to 'v' and the total distance is smaller, update 'v's distance
            if (adjMatrix[u][v] != 0 && dist[u] + adjMatrix[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }
}
