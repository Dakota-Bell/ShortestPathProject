#include "FileClass.h"
template <class T>
//---------------------------------------------------------------------------------------- 
// readFromFile: This function is basically like a "vertex.getName()" method.
//				1. Read in from the file
//				2. Store the name of the vertex
//				3. Store the connections and weights into their arrays
		
// Incoming Data: N/A
		
// Outgoing Data: N/A
	
// Author: Dakota Bell
		
// Tester: 
		
// Notes: 
		
// --------------------------------------------------------------------------- 
//template <class T>
void FileClass<T>::readFromFile()//string n, int c[MAX_VALUES], int w[MAX_VALUES])
{
	ifstream infile("ShippingInfo.txt");
	// check if the file even exists
	if (infile.fail())
	{
		cout << "File not found" << endl;
		exit(1); // Terminates the prblem
		return;
	}
			
	// if the file exists, get the name of the vetrtex
	int i = 0;
	while(infile)
	{
		getline(infile, name[i], '.');
		cout << name[i];
		i++;
		cout << endl;
	}
			
			
/*
	// get the connecting vertexes and store into the c array
			
	int linesCounted; // for keeping track of how many total numbers there are in the rest of 
					  // a line, you keep track of the number of commas + 1 and divide by two 
					  // so you know how many connections and weights there are for that vertex
			
	// count the number of commas
			
	while(getline(infile, connections[i], ','))
	{
		i++;
		cout << connections[i] << endl;
	}
			*/
	// get the weights of each edge (they must be in order) and store into the w array
			
	// display for debugging
	infile.close();
	cout << "leaving the readFromFile method!" << endl;
}
	
//---------------------------------------------------------------------------------------- 
// writeIntoArray, Will write into the array of the vertex's and such
//				do NOT need to include the size of the array in the constructor
//				when doing it this way.
		
// Incoming Data: readFromFile info, a vertex
		
// Outgoing Data: N/A
		
// Author: Dakota Bell
		
// Tester: 
		
// Notes: 
		
// --------------------------------------------------------------------------- 
		
		
//---------------------------------------------------------------------------------------- 
// Constructor, initialize the name, and two parallel arrys. You
//				do NOT need to include the size of the array in the constructor
//				when doing it this way.
		
// Incoming Data: N/A
		
// Outgoing Data: N/A
		
// Author: Dakota Bell
		
// Tester: 
		
// Notes: 
		
// --------------------------------------------------------------------------- 
template <class T>
FileClass<T>::FileClass():name(){}