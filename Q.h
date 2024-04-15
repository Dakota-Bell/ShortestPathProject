// --------------------------------------------------------------------------- 
// Name: Kara Chobot, Dakota Bell, Chhavi Chhavi
// Course-Section: CS355-section 01
// Assignment: project # 4
// Date due: 04/15/2024
// Description: The linkedQ prototypes and varialbes of a program intended to 
//		calculate the shortest shipping path from beginning to end destination.
// --------------------------------------------------------------------------- 

//////////////////////////////////////////////////////////////////////////////////////// 

//				LINKEDQ PROTOTYPES AND VARIABLES

//////////////////////////////////////////////////////////////////////////////////////// 
#ifndef Q_H
#define Q_H
#include "VertexStruct.h"
//---------------------------------------------------------------------------------------- 
// LinkedQ class method prototypes and variables.
		
// Incoming Data: N/A
		
// Outgoing Data: N/A
		
// Author: Kara Chobot
		
// Tester: 
		
// Notes: kept misspelling Queue so shortened to Q
		
// --------------------------------------------------------------------------- 
template <class T>
class linkedQ
{
private:
    Vertex<T> *frontQ;
    Vertex<T> *rearQ;
    static const int MAX_VAL = 25;

public:
    void readVertexesFromFile(T);
    void addQ(const T*& element);
    const linkedQ <T>& operator=(const linkedQ<T>& rhs); 
    linkedQ();
    linkedQ(const linkedQ<T>& rhs); 
    bool isEmpty();
    bool isFull(); 
    void initializeQ();
    void deleteQ();
    void printQ();
    T front(); 
    T back(); 
    ~linkedQ(); 
    void copyQ(const linkedQ<T> & rhs);
};

#endif // Q_H_INCLUDED
