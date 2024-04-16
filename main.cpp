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
#include "VertexStruct.cpp"
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
    Eyeball vertex;// nextVertex;

    int visited[MAX] = {0};
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

//testing output WORKS
    /* for(int i = 0; i < MAX; i++)
     {
         for(int j = 0; j < MAX; j++)
         {
             cout<< adjMatrix[i][j] << " ";
         }
         cout<<endl;
     }*/

    menu(locationArr, MAX);

    cout << "Enter your starting port number: ";
    cin >> start;
    cout << "Enter your ending port number: ";
    cin >> end;

    vertex.eye = start - 1; //first Eyeball
    end = end - 1; //Goal
    Q.enQ(vertex.eye); //adds to Q
    vertex.currentDist = 0;
    //visited[vertex.eye] = 1;

    //Greedy
  //int j = 0;
        //cout<<"in while loop"<<endl;
        //vertex.currentDist = INF; //initializes all distances to logical infinity //do this in the struct? or earlier in main??
       for(int j = 0; j < MAX; j++)
        {
            //cout<<"in for loop"<<endl;
            if(vertex.eye == end)
            {
                while(Q.isEmpty() == false)
                {
                    cout<<vertex.eye<<endl;
                    Q.deQ();
                }
            }
            else if (adjMatrix[vertex.eye][j] == 1 && visited[vertex.eye] == 0)
            {
                //cout<<"in if statement"<<endl;
                vertex.whoChanged = vertex.eye;
                vertex.eye = j;
                Q.enQ(vertex.eye);
                visited[vertex.eye] = 1;
                //visited[vertex.eye];
                vertex.currentDist = vertex.currentDist + 1;
            }//end else-if statement
            else
            {
                cout<<"Vertex cannot be reached."<<endl;
            }

        }//end for loop
        //cout<<"exit for loop"<<endl;
    //end while loop
    //cout<<"exit while loop"<<endl;

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
    for(int i = 1; i < MAX; i++)
    {
        cout << i << ". " << locArr[i] << endl;
    }
    cout << endl;
 }
