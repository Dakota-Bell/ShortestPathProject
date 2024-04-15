// --------------------------------------------------------------------------- 
// Name: Kara Chobot, Dakota Bell, Chhavi Chhavi
// Course-Section: CS355-section 01
// Assignment: project # 4
// Date due: 04/15/2024
// Description: The LinkedQ class method definitions of a program intended to 
//		calculate the shortest shipping path from beginning to end destination.
// --------------------------------------------------------------------------- 
#include <iostream>
#include <fstream>
#include "Q.h"
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////// 

//				LINKEDQ METHOD DEFINITIONS

//////////////////////////////////////////////////////////////////////////////////////// 

//---------------------------------------------------------------------------------------- 
// isEmpty(): returns true if the frontQ points to nullptr. False if there is
//		a vertex/vertices  in the queue.
	
// Incoming Data: N/A
		
// Outgoing Data: True or False
		
// Author: Kara Chobot
		
// Tester: 
		
// Notes: 
		
// -----------------------------------------------------------------------------------------------
template <typename T>
bool linkedQ<T>::isEmpty()
{
    if (frontQ == nullptr);
    {
        return true;
    }
    return false;
}
//---------------------------------------------------------------------------------------- 
// readFromFile: Reads in the names of the vertexes from a file
//				1. Read in from the file
//				2. Store the name of the vertex
		
// Incoming Data: No parameters, but we have an input file names "ShippingInfo.txt"
		
// Outgoing Data: N/A
	
// Author: Dakota Bell
		
// Tester: Kara Chobot
		
// Notes: 

// -------------------------------------------------------------------------------------------
template <class T>
void linkedQ<T>::readVertexesFromFile(T obj)
{
	cout << "Entering readVertexesFromFile()" << endl;
	
	ifstream infile("ShippingInfo.txt");
	// check if the file even exists
	if (infile.fail())
	{
		cout << "File not found" << endl;
		exit(1); // Terminates the prblem
		return;
	}

	ifstream matrixList("matrix-list.txt");
	// check if the file even exists
	if (matrixList.fail())
	{
		cout << "File not found" << endl;
		exit(1); // Terminates the prblem
		return;
	}
	
	// if the file exists, get the name of the vetrtex
	int i = 0;
	linkedQ<T>* temp[MAX_VAL];
	while(infile) // while the file is open
	{
		getline(infile, obj.name); // read a line and store the name of the vertex at this point
		cout << i + 1<< ". " << obj.name << endl;; // store that name at whatever index it needs
//		temp->front[i] = obj; // place a vertex into the temp linkedQ
//		addQ(temp->front[i]);
		obj.link;
		i++; 
	}
	
	int k = 0; cout << endl;
	while(matrixList)
	{
		getline(matrixList, obj.connection[k]); // read from the 
		cout << obj.connection[k];
		obj.link;
		k++;
		cout << endl;
	}
	 
	matrixList.close();
	infile.close(); // close the file since we're finished reading from it
	cout << "leaving the readFromFile method!";
}
//---------------------------------------------------------------------------------------- 
// isFull(): Determines if the queue is full
	
// Incoming Data: N/A
		
// Outgoing Data: False
		
// Author: Kara Chobot
		
// Tester: 
		
// Notes: Since the queue made of dynamic memory it will never be
//		   full unless you run out of memory.
		
// --------------------------------------------------------------------------- 		
template <typename T>
bool linkedQ<T>::isFull()
{
    return false;
}
//---------------------------------------------------------------------------------------- 
	// initializeQ(): Calls the deleteQ() method.
		
	// Incoming Data: N/A
		
	// Outgoing Data: N/A
		
	// Author: Kara Chobot
		
	// Tester: 
		
	// Notes: 
		
	// --------------------------------------------------------------------------- 
template <typename T>
void linkedQ<T>::initializeQ()
{
    deleteQ();
}
//---------------------------------------------------------------------------------------- 
	// deleteQ(): Deletes the queue one vertex at a time and dynamically deallocates
	//		the vertices memory.
		
	// Incoming Data: N/A
		
	// Outgoing Data: N/A
		
	// Author: Kara Chobot
		
	// Tester: 
		
	// Notes: 
		
	// --------------------------------------------------------------------------- 
template <typename T>
void linkedQ<T>::deleteQ() 
{
    Vertex<T> *temp;
    if(!isEmpty())
    {
	    temp = frontQ;
	    frontQ = frontQ -> link;
	    delete temp;
    }
}
//---------------------------------------------------------------------------------------- 
// linkedQ(): Constructor. Initializes the frontQ and rearQ pointer to null.
		
// Incoming Data: N/A
		
// Outgoing Data: N/A
		
// Author: Kara Chobot
		
// Tester: 
		
// Notes: 
		
// -----------------------------------------------------------------------------------------
template <typename T>
linkedQ<T>::linkedQ()
{
    frontQ = nullptr;
    rearQ = nullptr;
}
//---------------------------------------------------------------------------------------- 
// addQ(): Dynamically adds a new vertex and associated variables to the queue
		
// Incoming Data: N/A
		
// Outgoing Data: N/A
		
// Author: Kara Chobot
		
// Tester: 
		
// Notes: 
		
// --------------------------------------------------------------------------------------------
template <typename T>
void linkedQ<T>::addQ(const T*& element)
{
    Vertex<T> *newVert;
    newVert = new Vertex<T>;

    newVert = new Vertex<T>;

    newVert -> name = element -> name;  
    newVert -> weight = element -> weight;
    newVert -> connection = element -> connection;

    newVert -> link = nullptr;

    if (frontQ == nullptr)
    {
        frontQ = newVert;
        rearQ = newVert;
    }
    else
    {
        rearQ -> link = newVert;
        rearQ = rearQ -> link;
    }
}
//---------------------------------------------------------------------------------------- 
// front(): Prints the data of the vertex at the front of the queue.
		
// Incoming Data: N/A
		
// Outgoing Data: N/A
		
// Author: Kara Chobot
		
// Tester: 
		
// Notes: 
		
// -----------------------------------------------------------------------------------------
template <class T>
T linkedQ<T>::front()
{
    if(frontQ != nullptr)
    {
        cout << frontQ -> weight << " " << frontQ -> name << " " << frontQ -> connections << endl; //info meaning weight, name, connections
    }
    else
    {
        cout << "No info available." << endl;
    }
}
//---------------------------------------------------------------------------------------- 
// back(): Prints the data of the vertex at the rear of the queue
		
// Incoming Data: N/A
		
// Outgoing Data: N/A
		
// Author: Kara Chobot
		
// Tester: 
		
// Notes: 
		
// --------------------------------------------------------------------------------------
template <typename T>
T linkedQ<T>::back()
{
    if(rearQ != nullptr)
    {
        cout << rearQ -> weight << " " << rearQ -> name << " " << rearQ -> connections << endl;
    }
    else
    {
        cout << "rearQ info not found." << endl;
    }
}
//---------------------------------------------------------------------------------------- 
// ~linkedQ(): calls the deleteQ(); method to deallocate queue dynamic memory.
		
// Incoming Data: N/A
		
// Outgoing Data: N/A
		
// Author: Kara Chobot
		
// Tester: 
		
// Notes: 
		
// ---------------------------------------------------------------------------------------
template <typename T>
linkedQ<T>::~linkedQ()
{
    deleteQ();
}
//---------------------------------------------------------------------------------------- 
// operator=(const linkedQ<T>& rhs): Overloaded = operator because you need it to 
//					dynamically allocate memory.
		
// Incoming Data: The right hand side of the = operator
		
// Outgoing Data: N/A
		
// Author: Kara Chobot
		
// Tester: 
		
// Notes: 
		
// -------------------------------------------------------------------------------------
template <typename T>
const linkedQ<T>& linkedQ<T>::operator = (const linkedQ<T>& rhs)
{
    if(this != &rhs)
    {
        copyQ(rhs);
    }
    return *this;
}
//---------------------------------------------------------------------------------------- 
// linkedQ(const linkedQ<T>& rhs): A copy constructor that creates a new vertex by calling
//					copyQ.
		
// Incoming Data: Rhight hand side vertex.
		
// Outgoing Data: N/A
		
// Author: Kara Chobot
		
// Tester: 
		
// Notes: 
		
// ---------------------------------------------------------------------------------------
template <typename T>
linkedQ<T>::linkedQ(const linkedQ<T>& rhs)
{
    frontQ = nullptr;
    copyQ(&rhs);
}
//---------------------------------------------------------------------------------------- 
// CopyQ(const linkedQ<T>& rhs): Does a deep copy of an existing pointer vertex
		
// Incoming Data: Right hand side vertex
		
// Outgoing Data: N/A
		
// Author: Kara Chobot
		
// Tester: 
		
// Notes: 
		
// -------------------------------------------------------------------------------------- 
template <typename T>
void linkedQ<T>::copyQ(const linkedQ<T>& rhs)
{
    int count;
    Vertex<T> *newVert;
    Vertex<T> *current;

    if(frontQ != nullptr)
    {
        deleteQ();
    }

    if(rhs.frontQ == nullptr)
    {
        frontQ = nullptr;
        rearQ = nullptr;
        count = 0;
    }
    else
    {
        current = rhs.frontQ;
        count = rhs.count;

        frontQ = new Vertex <T>;
        frontQ -> name = current -> name;
        frontQ -> weight = current -> weight;
        frontQ -> connections = current -> connections;
        frontQ -> link = nullptr;

        rearQ = frontQ;

        current = current -> link;

        while (current != nullptr)
        {
            newVert = new Vertex<T>;
            newVert -> name = current -> name;
            newVert -> weight = current -> weight;
            newVert -> connections = current -> connections;
            newVert -> link = nullptr;

            rearQ -> linke = newVert;
            rearQ = newVert;

            current = current ->link;
        }
    }
}
