#include <iostream>
using namespace std;

void menu(string[], int);

int main()
{
  int MAX = 9;
	//Vertex myObj;
	string locationArr[MAX] = {"Panama Canal", "Suez Canal", "Busan, South Korea", "Shanghai, China", "Singapore, Singapore", "Rotterdam, The Netherlands", "Japan", "New York, United States", "Immingham, United Kingdom"};
	int start, end;
	menu(locationArr, MAX);
	
	cout << "Enter your starting port number: ";
	cin >> start;
	cout << "Enter your ending port number: ";
	cin >> end;
  
  return 0;
}

  //---------------------------------------------------------------------------------------- 
	// Menu(): simpliy prints out the menu of optional ports to begin at and potential 
	//	   ending ports
		
	// Incoming Data: array of all locations, maximum number of locations
		
	// Outgoing Data: N/A
		
	// Author: Dakota Bell
		
	// Tester: 
		
	// Notes: 
		
	// --------------------------------------------------------------------------- 
  void menu(string locArr[], int MAX)
  {
	  for(int i = 1; i < MAX; i++)
  	{
  		cout << i << ". " << locArr[i] << endl;
  	}
  	cout << endl;
}
