#include <iostream>
using namespace std;

const int MAX_V = 100; 	//max no of vertices
const int INF = 1e9; 	//representing infinity

void menu(string[], int);

int adjMatrix[MAX_V][MAX_V]; 	// Adjacency matrix for graph weights
int distance[MAX_V]; 		// Stores shortest distance from source
bool visited[MAX_V]; 		// Keeps track of visited vertices

void dijkstra(int, int);

int main()
{
  int MAX = 9;
	//Vertex myObj;
	string locationArr[MAX] = {"Panama Canal", "Suez Canal", "Busan, South Korea", "Shanghai, China", "Singapore, Singapore", "Rotterdam, The Netherlands", "Japan", "New York, United States", "Immingham, United Kingdom"};
	int start, end, vertices;
	menu(locationArr, MAX);
	
	cout << "Enter your starting port number: ";
	cin >> start;
	cout << "Enter your ending port number: ";
	cin >> end;

	dijkstra(start, vertices);
	
  return 0;
}

  //---------------------------------------------------------------------------------------- 
	// Menu(): simpliy prints out the menu of optional ports to begin at and potential 
	//	   ending ports
		
	// Incoming Data: array of all locations, maximum number of locations
		
	// Outgoing Data: N/A
		
	// Author: Dakota Bell
		
	// Tester: 
		
	// Notes: 
		
	// --------------------------------------------------------------------------- 
  void menu(string locArr[], int MAX)
  {
	  for(int i = 1; i < MAX; i++)
  	{
  		cout << i << ". " << locArr[i] << endl;
  	}
  	cout << endl;
}

//---------------------------------------------------------------------------------------- 
	// dijkstra(): Algorithm for eyeball
		
	// Incoming Data: the starting location and
		
	// Outgoing Data: N/A
		
	// Author: Chhavi Chhavi
		
	// Tester: 
		
	// Notes: 
		
	// --------------------------------------------------------------------------- 
void dijkstra(int start, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        dist[i] = INF;
        visited[i] = false;
    }
	
    dist[start] = 0;

    for (int i = 0; i < n; ++i) 
    {
        int u = -1;
        // Finding the vertex with the smallest distance
        for (int j = 0; j < n; ++j) 
	{
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) 
	    {
                u = j;
            }
        }

        if (dist[u] == INF)
	{
		break; // Remaining vertices are unreachable
	}

        visited[u] = true;
        for (int v = 0; v < n; ++v) 
	{
            if (adjMatrix[u][v] && dist[u] + adjMatrix[u][v] < dist[v])
	    { 
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }
}
