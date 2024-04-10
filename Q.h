#ifndef Q_H
#define Q_H

//kept misspelling Queue so shortened to Q
template <class T>
class linkedQ
{
private:
    //int count;
    Vertex<T> *frontQ;
    Vertex<T> *rearQ;
    void addQ(const T*& element);

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
};


#endif // Q_H_INCLUDED
