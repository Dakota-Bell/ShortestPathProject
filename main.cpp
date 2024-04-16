// ---------------------------------------------------------------------------
// Name: Kara Chobot, Dakota Bell, Chhavi Chhavi
// Course-Section: CS355-section 01
// Assignment: project # 4
// Date due: 04/15/2024
// Description: The main portion of a program intended to calculate the shortest
//		shipping path from beginning to end destination.
// ---------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "Q.cpp" // includes everything from all other headers and classes
#include "Eyeball.h"
using namespace std;

void menu(string[], int);

////////////////////////////////////////////////////////////////////////////////////////
//          MAIN FUNCTION
////////////////////////////////////////////////////////////////////////////////////////

const int MAX = 5;
float INF = INFINITY;

int main()
{
    // Array that connects each vertex number to its corresponding name for better readability.
    string locationArr[MAX] = {"Suez Canal", "Busan, South Korea", "Shanghai, China", "Singapore, Singapore", "Rotterdam, The Netherlands"};
    int adjMatrix[MAX][MAX], start, end; // adjacency matrix for graph representation and start/end points 
    string fileName = "No file chosen"; // to hold the filename from user input
    Eyeball vertex[MAX]; // Array of Eyeball objects representing each vertex

    int visited[MAX] = {0}; 
    int holdStart; // temp value for use in a for loop later
    ArrayQ<int> Q; 

    // Prompt user for the adjacency matrix file name and attempt to open it
    cout << "Enter file name: ";
    cin >> fileName;
    
    cout << endl;
    
    ifstream infile(fileName); // File stream for reading the adjacency matrix
    if(infile.fail()) // Check if the file opening failed
    {
        cout << "File not found" << endl;
        exit(1); // Exit if no file found
    }

    // Read the adjacency matrix from the file
    while(infile)
    {
        for(int i = 0; i < MAX; i++)
        {
            for(int j = 0; j < MAX; j++)
            {
                infile >> adjMatrix[i][j];
            }
        }
        infile.close(); // Close the file after reading
    }

    // Assign location names to vertices
	for(int i = 0; i < MAX; i++)
	{
		vertex[i].name = locationArr[i];
	}

    // Output the adjacency matrix
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            cout << setw(3) << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl;

    // Display menu and get user input for starting and ending ports
    menu(locationArr, MAX);

    cout << "Enter your starting port number: ";
    cin >> start;
    cout << "Enter your ending port number: ";
    cin >> end;

    vertex[0].eye = start - 1;      // first Eyeball
    end = end - 1;                  // Goal
    vertex[0].currentDist = 0;      // Start with a distance of 0
    Q.enQ(vertex[0].eye);           // Enqueue the starting vertex
    
    holdStart = start - 1;          // Hold the start position for looping
    
    // Main loop to traverse the graph
    for(int j = vertex[0].eye; j < MAX; j++)  
    {
        if(vertex[j].eye == end)    // Check if the end vertex is reached
        {
            while(Q.isEmpty() == false) // Output the route information while there are vertices in the queue
            {
                vertex[j].currentDist = vertex[j].currentDist + 1;
                
                cout << vertex[j].currentDist << endl;
                cout << vertex[j].name << endl;
                
                Q.deQ(); // Dequeue after processing
            }
            
            break; // Exit the loop once the destination is reached
        } 
        else if (adjMatrix[vertex[j].eye][j] == 1 && visited[vertex[j].eye] == 0)
        {
            vertex[j].eye = j; // Update the current vertex based on adjacency matrix
            vertex[j].whoChanged = vertex[j].eye; // Track the vertex that caused the change
            Q.enQ(vertex[j].eye); // Enqueue the new vertex
            visited[vertex[j].eye] = 1; // Mark as visited
            vertex[j].currentDist = vertex[j].currentDist + 1; // Increment the distance
        }
        else
        {
            cout << "Vertex cannot be reached." << endl; // Output if no path is found
        }
		
		if(j == MAX && holdStart != 0) // Check if loop needs to be reset to start
        {
            j = 0; // Reset loop index to start
        }		
    }

    return 0; 
}

////////////////////////////////////////////////////////////////////////////////////////
//          FUNCTION DEFINITIONS
////////////////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------------------
// menu(): simply prints out the menu of optional ports to begin at and potential
//         ending ports

// Incoming Data: array of all locations, maximum number of locations

// Outgoing Data: N/A

// Author: Dakota Bell

// Tester: 

// Notes: 

//----------------------------------------------------------------------------------------
void menu(string locArr[], int MAX)
{
    for(int i = 0; i < MAX; i++)
    {
        cout << i + 1 << ". " << locArr[i] << endl;
    }
    cout << endl;
}
