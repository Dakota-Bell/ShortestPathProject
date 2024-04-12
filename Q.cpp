#include <iostream>
#include <fstream>
#include "Q.h"
using namespace std;

//priority q implemented in heap is efficeint. this is less efficient way but still gets 100.
//---------------------------------------------------------------------------------------- 
	// isEmpty(): returns true if the frontQ points to nullptr. False if there is
	//		a vertex/vertices  in the queue.
		
	// Incoming Data: N/A
		
	// Outgoing Data: True or False
		
	// Author: Kara Chobot
		
	// Tester: 
		
	// Notes: 
		
	// --------------------------------------------------------------------------- 
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
		
// Tester: 
		
// Notes: 

// --------------------------------------------------------------------------- 
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
//---------------------------------------------------------------------------------------- 
	// isFull(): Determines if the qu
	}
	 
	matrixList.close();
	infile.close(); // close the file since we're finished reading from it
	cout << "leaving the readFromFile method!";
}
		
	// Incoming Data: N/A
		
	// Outgoing Data: False, since the Queue made of dynamic memory it will never be
	//		   full unless you run out of memory.
		
	// Author: Kara Chobot
		
	// Tester: 
		
	// Notes: 
		
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
	// deleteQ(): Deletes the qeueu one vertex at a time and dynamically deallocates
	//		the vertices memory.
		
	// Incoming Data: N/A
		
	// Outgoing Data: N/A
		
	// Author: Kara Chobot
		
	// Tester: 
		
	// Notes: 
		
	// --------------------------------------------------------------------------- 
template <typename T>
void linkedQ<T>::deleteQ()   //need to delete info as well?
{
    Vertex<T> *temp;
    if(!isEmpty())
    {
        temp = frontQ;

        frontQ = frontQ->link;
        delete temp;

        if(frontQ == nullptr)
        {
            rearQ = nullptr;
        }
        else
        {
            cout << "Cannot remove from an empty queue." << endl;
        }
    }
}
//---------------------------------------------------------------------------------------- 
	// linkedQ(): Constructor. Initializes the frontQ and rearQ pointer to 0
		
	// Incoming Data: N/A
		
	// Outgoing Data: N/A
		
	// Author: Kara Chobot
		
	// Tester: 
		
	// Notes: 
		
	// --------------------------------------------------------------------------- 
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
		
	// --------------------------------------------------------------------------- 
template <typename T>
void linkedQ<T>::addQ(const T*& element) //element needs to be name, info, weight?
{
    Vertex<T> *newVert;
    newVert = new Vertex<T>;

    newVert = new Vertex<T>;

    newVert -> name = element -> name;   //(need info or just do below code?. figure out how but this syntax dynamically creates vertices.)
//    newVert -> weight = element -> weight;
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
		
	// --------------------------------------------------------------------------- 
template <class T>
T linkedQ<T>::front()
{
    if(frontQ != nullptr)
    {
        cout<<frontQ -> weight<< " "<<frontQ -> name<<" "<<frontQ->connections<<endl; //info meaning weight, name, connections
    }
    else
    {
        cout<<"No info available."<<endl;
    }
}
//---------------------------------------------------------------------------------------- 
	// back(): Prints the data of the vertex at the rear of the queue
		
	// Incoming Data: N/A
		
	// Outgoing Data: N/A
		
	// Author: Kara Chobot
		
	// Tester: 
		
	// Notes: 
		
	// --------------------------------------------------------------------------- 
template <typename T>
T linkedQ<T>::back()
{
    if(rearQ != nullptr)
    {
        cout<<rearQ -> weight<< " "<<rearQ -> name<<" "<<rearQ->connections<<endl;
    }
    else
    {
        cout << "rearQ info not found." <<endl;
    }
}
//---------------------------------------------------------------------------------------- 
	// ~linkedQ(): calls the deleteQ(); method to deallocate queue dynamic memory.
		
	// Incoming Data: N/A
		
	// Outgoing Data: N/A
		
	// Author: Kara Chobot
		
	// Tester: 
		
	// Notes: 
		
	// --------------------------------------------------------------------------- 
template <typename T>
linkedQ<T>::~linkedQ()
{
    deleteQ();
}
//---------------------------------------------------------------------------------------- 
	// operator=(const linkedQ<T>& rhs): Overloaded = operator because you need it in 
	//					DAM
		
	// Incoming Data: a
		
	// Outgoing Data: N/A
		
	// Author: Kara Chobot
		
	// Tester: 
		
	// Notes: 
		
	// --------------------------------------------------------------------------- 
template <typename T>
const linkedQ<T>& linkedQ<T>::operator=(const linkedQ<T>& rhs)
{
    if(this != &rhs)
    {
        copyQ(rhs);
    }
    return *this;
}
//---------------------------------------------------------------------------------------- 
	// fileName(): I
		
	// Incoming Data: N/A
		
	// Outgoing Data: N/A
		
	// Author: Kara Chobot
		
	// Tester: 
		
	// Notes: 
		
	// --------------------------------------------------------------------------- 
template <typename T>
linkedQ<T>::linkedQ(const linkedQ<T>& rhs)
{
    frontQ = nullptr;
    copyQ(&rhs);
}
//---------------------------------------------------------------------------------------- 
	// fileName(): I
		
	// Incoming Data: N/A
		
	// Outgoing Data: N/A
		
	// Author: Kara Chobot
		
	// Tester: 
		
	// Notes: 
		
	// --------------------------------------------------------------------------- 
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
        frontQ->link=nullptr;

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
