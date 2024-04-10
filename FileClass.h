#include <iostream>
#include <fstream>
#include "VertexStruct.h"
using namespace std;

template <class T>
class FileClass
{
	private:
		static const int MAX_VALUES = 100; // maximum number, definitiely change it for all your needs and wants
		T name[100]; // just want to hold the name of the vertex
		
	public:
		void readFromFile();
		FileClass();
};