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

//---------------------------------------------------------------------------------------- 
// writePathInstructionsToFile(): Write the path instructions from the starting port to the 
//                                  ending port into a file.
		
// Incoming Data: starting port, ending port, array of strings containing the instructions
//                  and an integer representing the number of instructions in the ins[] array
		
// Outgoing Data: N/A
		
// Author: Chhavi Chhavi
		
// Tester: 
		
// Notes: 
		
// --------------------------------------------------------------------------- 

void writePathInstructionsToFile(string& startPort, string& endPort,string ins[], int noOfIns) 
{
    ofstream outputFile("Path.txt"); //Created an outputFile

    if (outputFile.is_open()) 		//Checking if file is opened
	{
	    // Write the start and end ports at the top of the file
        outputFile << "Path Instructions from " << startPort << " to " << endPort << ":\n\n";
    
        // Write each instruction to the file, line by line
        for (int i = 0; i < noOfIns; ++i) 
        {
            outputFile << ins[i] << endl;
        }
	    
	    outputFile.close(); 	//Closing the output file
	}
	else
	{
	    cout << "File not created" << endl; 	//Error message displayed
	}
}

