#include <iostream>
#include "Q.h"
using namespace std;

//priority q implemented in heap is efficeint. this is less efficient way but still gets 100.
//---------------------------------------------------------------------------------------- 
	// fileName(): I
		
	// Incoming Data: N/A
		
	// Outgoing Data: N/A
		
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
	// fileName(): I
		
	// Incoming Data: N/A
		
	// Outgoing Data: N/A
		
	// Author: Kara Chobot
		
	// Tester: 
		
	// Notes: 
		
	// --------------------------------------------------------------------------- 
template <typename T>
bool linkedQ<T>::isFull()
{
    return false; //since dynamic memory the Queue will never be full unless you run out of memory
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
	// fileName(): I
		
	// Incoming Data: N/A
		
	// Outgoing Data: N/A
		
	// Author: Kara Chobot
		
	// Tester: 
		
	// Notes: 
		
	// --------------------------------------------------------------------------- 
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
	// fileName(): I
		
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
	// fileName(): I
		
	// Incoming Data: N/A
		
	// Outgoing Data: N/A
		
	// Author: Kara Chobot
		
	// Tester: 
		
	// Notes: 
		
	// --------------------------------------------------------------------------- 
template <typename T>
void linkedQ<T>::addQ(const T*& element)
{
    Vertex<T> *newVert;
    newVert = new Vertex<T>;

    newVert = new Vertex<T>;

    newVert -> name = element -> name;   //(need info or just do below code?. figure out how but this syntax dynamically creates vertices.)
    newVert -> weight = element -> weight;
    newVert -> connections = element -> connections;

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
	// fileName(): I
		
	// Incoming Data: N/A
		
	// Outgoing Data: N/A
		
	// Author: Kara Chobot
		
	// Tester: 
		
	// Notes: 
		
	// --------------------------------------------------------------------------- 
template <class T>
void linkedQ<T>::front()
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
	// fileName(): I
		
	// Incoming Data: N/A
		
	// Outgoing Data: N/A
		
	// Author: Kara Chobot
		
	// Tester: 
		
	// Notes: 
		
	// --------------------------------------------------------------------------- 
template <typename T>
void linkedQ<T>::back()
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
	// fileName(): I
		
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
