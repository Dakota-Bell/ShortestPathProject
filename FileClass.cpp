#include "FileClass.h"
template <class T>
//---------------------------------------------------------------------------------------- 
// readFromFile: Reads in the names of the vertexes from a file
//				1. Read in from the file
//				2. Store the name of the vertex
		
// Incoming Data: No parameters, but we have an input file names "ShippingInfo.txt"
		
// Outgoing Data: N/A
	
// Author: Dakota Bell
		
// Tester: 
		
// Notes: 
		
// --------------------------------------------------------------------------- 
//template <class T>
void FileClass<T>::readVertexesFromFile()
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
			
	infile.close();
	cout << "leaving the readFromFile method!";
}
	
//---------------------------------------------------------------------------------------- 
// writeIntoArray, Will write into the array of the vertex's and such
//				do NOT need to include the size of the array in the constructor
//				when doing it this way.
		
// Incoming Data: readFromFile info, a vertex that will hold the infomation from one 
//				  
		
// Outgoing Data: N/A
		
// Author: Dakota Bell
		
// Tester: 
		
// Notes: 
		
// --------------------------------------------------------------------------- 
template <class T>
T FileClass<T>::writeIntoArray(T name[])
{
	// get info from the file into each individual index for each vertex
	
	return this;
}
		
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
