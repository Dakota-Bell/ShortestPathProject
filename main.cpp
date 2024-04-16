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
#include "Q.cpp" // includes everything from all other headers and classes
#include "eyeball.h"
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////

//					PROTOTYPE

////////////////////////////////////////////////////////////////////////////////////////
void menu(string[], int);
//void run(adjMatrix[i][j], locationArr[MAX]);
////////////////////////////////////////////////////////////////////////////////////////

//					MAIN

////////////////////////////////////////////////////////////////////////////////////////
const int MAX = 5;
float INF = INFINITY;

int main() 
{
    //mao connects vertex num to vertex name for context
    string locationArr[MAX] = {"Suez Canal", "Busan, South Korea", "Shanghai, China", "Singapore, Singapore", "Rotterdam, The Netherlands"};
    int adjMatrix[MAX][MAX], start, end;
    string fileName = "No file chosen";
    Eyeball vertex[MAX];// nextVertex;

    int visited[MAX] = {0};
    int holdStart; // temp value for use in a for loop later 
    ArrayQ<int> Q;
    //ArrayQ<int> waiting;
    //Write routine so that diagonal is 0, all others -1, then add in 1 for adjacencies from the adjacency file.

    //Reads in an adjacency matrix from file.
    cout << "Enter file name: " << endl;
    cin >> fileName;
    //cout << "Made it into loadAdj" <<endl;
     ifstream infile(fileName);
     if(infile.fail())
     {
         cout << "File not found" << endl;
         exit(1);
     }

     while(infile)
     {
         for(int i = 0; i < MAX; i++)
         {
             for(int j = 0; j < MAX; j++)
             {
                infile>>adjMatrix[i][j];
             }
         }
         infile.close();
     }

	for(int i = 0; i < MAX; i++)
	{
		vertex[i].name = locationArr[i];
	}

//testing output WORKS
    for(int i = 0; i < MAX; i++)
     {
         for(int j = 0; j < MAX; j++)
         {
             cout<< adjMatrix[i][j] << " ";
         }
         cout<<endl;
     }

    menu(locationArr, MAX);

    cout << "Enter your starting port number: ";
    cin >> start;
    cout << "Enter your ending port number: ";
    cin >> end;

    vertex[0].eye = start - 1; //first Eyeball
    end = end - 1; //Goal
    vertex[0].currentDist = 0;
    Q.enQ(vertex[0].eye); //adds to Q
    //visited[vertex.eye] = 1;

    //Greedy
  //int j = 0;
        //cout<<"in while loop"<<endl;
        //vertex.currentDist = INF; //initializes all distances to logical infinity //do this in the struct? or earlier in main??
        holdStart = start - 1;
       for(int j = vertex[0].eye; j < MAX; j++)  
        {
            //cout<<"in for loop"<<endl;
            if(vertex[j].eye == end) // if you have reached the end
            {
                while(Q.isEmpty() == false) // while you have info to display, display it
                {
                	
                    vertex[j].currentDist = vertex[j].currentDist + 1;
                	cout<<vertex[j].currentDist<<endl;
                    cout<<vertex[j].name << endl;
                    Q.deQ(); // remove the vertex array from the queue
                }
                break; // break out of the loop, you no longer need to be here ya silly guy!
            } 
            else if (adjMatrix[vertex[j].eye][j] == 1 && visited[vertex[j].eye] == 0)
            {
                vertex[j].eye = j; // change the eyeball to j because the adj matrix says you can
                vertex[j].whoChanged = vertex[j].eye; // who changed me is set to j essentially
                Q.enQ(vertex[j].eye);
                visited[vertex[j].eye] = 1;
                vertex[j].currentDist = vertex[j].currentDist + 1;
            }//end else-if statement
            else
            {
                cout<<"Vertex cannot be reached."<<endl;			
            }
			if(j == MAX && holdStart != 0) /* before leaving the loop, you want to check and see if you started at zero,
											  and if not: reset the value of j to. You also need to be at the max value
											  otherwise, leave it be*/
        		j = 0;
        }//end for loop

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////

//				FUNCTION DEFINITIONS

////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------
// Menu(): simpliy prints out the menu of optional ports to begin at and potential
//	   ending ports

// Incoming Data: array of all locations, maximum number of locations

// Outgoing Data: N/A

// Author: Dakota Bell

// Tester:

// Notes:

// ----------------------------------------------------------------------------------------
void menu(string locArr[], int MAX)
{
    for(int i = 0; i < MAX; i++)
    {
        cout << i + 1 << ". " << locArr[i] << endl;
    }
    cout << endl;
 }
