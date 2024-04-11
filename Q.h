#ifndef Q_H
#define Q_H
//---------------------------------------------------------------------------------------- 
	// fileName(): I
		
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
    //int count;
    Vertex<T> *frontQ;
    Vertex<T> *rearQ;
    

public:
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
    void addQ(const T*& element);
};


#endif // Q_H_INCLUDED
