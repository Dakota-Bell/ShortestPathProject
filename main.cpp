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
#include "Q.cpp" // includes everything from all other headers and classes
#include "Dijkstra.h"
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////// 

//					PROTOTYPE

//////////////////////////////////////////////////////////////////////////////////////// 
void menu(string[], int);
//////////////////////////////////////////////////////////////////////////////////////// 

//					MAIN

//////////////////////////////////////////////////////////////////////////////////////// 
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
