#ifndef FILECLASS_H
#define FILECLASS_H
#include <iostream>
#include <fstream>
#include "VertexStruct.h"
using namespace std;

template <class T>
class FileClass
{
	private:
		static const int MAX_VALUES = 100; // maximum number, definitiely change it for all your needs and wants
		T name[100]; // just want to hold the name of the vertex, and keep track of it's order via the index
		
	public:
		void readFromFile();
		T writeIntoArray(T name[]); // templated so anytype of data may be returned
									// depending on the class type you need to return
		FileClass();
};

#endif
