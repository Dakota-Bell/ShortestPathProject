#include <iostream>
#include "VertexStruct.cpp"
#include "Q.h"
using namespace std;
//---------------------------------------------------------------------------------------- 
// isEmpty(): This function returns true or false depending on whether or not the queue
//		is contains a vertex or not.
		
// Incoming Data: N/A
		
// Outgoing Data: True or False depending on whether or not the Queue is empty.
		
// Author: Kara Chobot
		
// Tester: 
		
// Notes: 
		
// -----------------------------------------------------------------------------------------
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
// isFull: This function returns. The queue should always return false due to using dynamic 
//		memory allocation unless you have run out of memory on your computer.
		
// Incoming Data: N/A
		
// Outgoing Data: false
		
// Author: Kara Chobot
		
// Tester: 
		
// Notes: 
		
// -----------------------------------------------------------------------------------------
template <typename T>
bool linkedQ<T>::isFull()
{
    return false; //since dynamic memory the Queue will never be full unless you run out of memory
}
//---------------------------------------------------------------------------------------- 
// initializeQ: This function 
//				1. R
//				2. S
//				3. S
		
// Incoming Data: N/A
		
// Outgoing Data: N/A
		
// Author: Kara Chobot
		
// Tester: 
		
// Notes: 
		
// -----------------------------------------------------------------------------------------
template <typename T>
void linkedQ<T>::initializeQ()
{
    Vertex<T> *temp;
    while(frontQ != nullptr)
    {
        temp = frontQ;
        frontQ = frontQ -> link;
        delete temp;
    }
    rearQ = nullptr;
}
//---------------------------------------------------------------------------------------- 
// functionName: This function 
//				1. R
//				2. S
//				3. S
		
// Incoming Data: N/A
		
// Outgoing Data: N/A
		
// Author: Kara Chobot
		
// Tester: 
		
// Notes: 
		
// -----------------------------------------------------------------------------------------
template <typename T>
void linkedQ<T>::deleteQ()   //need to delete info as well.
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
// functionName: This function 
//				1. R
//				2. S
//				3. S
		
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
// functionName: This function 
//				1. R
//				2. S
//				3. S
		
// Incoming Data: N/A
		
// Outgoing Data: N/A
		
// Author: Kara Chobot
		
// Tester: 
		
// Notes: 
		
// -----------------------------------------------------------------------------------------
template <typename T>
void linkedQ<T>::addQ(const T*& element)
{
    Vertex<T> *newVert;
    newVert = new Vertex<T>;

    newVert = new Vertex<T>;

    newVert -> info = element;   //(need info or just do below code?. figure out how but this syntax dynamically creates vertices.)
    /*
        newVert -> name = name;
        newVert -> weight = weight;
        newVert -> connections = connections;
    */
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
// functionName: This function 
//				1. R
//				2. S
//				3. S
		
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
        return frontQ -> info; //info meaning weight, name, connections
    }
    else
    {
        cout<<"No info available."<<endl;
    }
}
//---------------------------------------------------------------------------------------- 
// functionName: This function 
//				1. R
//				2. S
//				3. S
		
// Incoming Data: N/A
		
// Outgoing Data: N/A
		
// Author: Kara Chobot
		
// Tester: 
		
// Notes: 
		
// -----------------------------------------------------------------------------------------
template <typename T>
T linkedQ<T>::back()
{
    if(rearQ != nullptr)
    {
        return rearQ -> info; //weight, name, connections
    }
    else
    {
        cout << "rearQ info not found." <<endl;
    }
}
//---------------------------------------------------------------------------------------- 
// functionName: This function 
//				1. R
//				2. S
//				3. S
		
// Incoming Data: N/A
		
// Outgoing Data: N/A
		
// Author: Kara Chobot
		
// Tester: 
		
// Notes: 
		
// -----------------------------------------------------------------------------------------
template <typename T>
linkedQ<T>::~linkedQ()
{
    deleteQ();
}
//---------------------------------------------------------------------------------------- 
// functionName: This function 
//				1. R
//				2. S
//				3. S
		
// Incoming Data: N/A
		
// Outgoing Data: N/A
		
// Author: Kara Chobot
		
// Tester: 
		
// Notes: 
		
// -----------------------------------------------------------------------------------------
template <typename T>
const linkedQ<T>& linkedQ<T>::operator=(const linkedQ<T>& rhs)
{
    if(this != &rhs)
    {
        copyQ(rhs)
    }
    return *this;
}
//---------------------------------------------------------------------------------------- 
// functionName: This function 
//				1. R
//				2. S
//				3. S
		
// Incoming Data: N/A
		
// Outgoing Data: N/A
		
// Author: Kara Chobot
		
// Tester: 
		
// Notes: 
		
// -----------------------------------------------------------------------------------------
template <typename T>
linkedQ<T>::linkedQ(const linkedQ<T>& rhs)
{
    frontQ = nullptr;
    copyQ(rhs);
}
//---------------------------------------------------------------------------------------- 
// functionName: This function 
//				1. R
//				2. S
//				3. S
		
// Incoming Data: N/A
		
// Outgoing Data: N/A
		
// Author: Kara Chobot
		
// Tester: 
		
// Notes: 
		
// -----------------------------------------------------------------------------------------
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
        count = 0
    }
    else
    {
        current = rhs.frontQ;
        count = rhs.count;

        frontQ = newVert<T>;
        frontQ -> info = current -> info;
        /*
            frontQ ->name = current ->name;
            frontQ->weight...ETC
        */
        frontQ->link=nullptr;

        rearQ = frontQ;

        current = current -> link;

        while (current != nullptr)
        {
            newVert = new Vertex<T>;
            newVert -> info = current -> info; //name, weight, connections
            newVert -> link = nullptr;

            rearQ -> linke = newVert;
            rearQ = newVert;

            current = current ->link;
        }
    }
}
