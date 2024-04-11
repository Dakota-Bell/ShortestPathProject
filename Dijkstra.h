#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <iostream>

//---------------------------------------------------------------------------------------- 
	// fileName(): I
		
	// Incoming Data: N/A
		
	// Outgoing Data: N/A
		
	// Author: Chhavi Chhavi
		
	// Tester: 
		
	// Notes: 
		
	// --------------------------------------------------------------------------- 
template <typename T>
class Dijkstra 
{
    public:
        static const int MAX_V = 100;  // Max number of vertices
    
        Dijkstra(T infinity);          // Constructor with infinity value
        void run(int start, int n);    // Function to execute the algorithm
    
    private:
        T dist[MAX_V];                 // Stores shortest distance from source
        bool visited[MAX_V];           // Keeps track of visited vertices
        T adjMatrix[MAX_V][MAX_V];     // Adjacency matrix for graph weights
        T INF;                         // Infinity value provided by the user
};

#endif
