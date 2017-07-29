// Martin Reddy

#include "myobject.h"
#include <string>
#include <iostream>

// declare the external linkage elements of myobject.cpp
extern void FreeFunction();
extern int INTERNAL_CONSTANT;
extern std::string Filename;

int main(int, char **)
{
	// call a function hidden within the myobject.cpp module
	FreeFunction();

	// access a constant defined within myobject.cpp
	std::cout << "Internal constant = " << INTERNAL_CONSTANT << std::endl;

	// change global state within myobject.cpp
	Filename = "different.txt";

	return 0;
}
