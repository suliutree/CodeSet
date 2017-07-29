// Martin Reddy

#include "myobject.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

// Uncomment the next line to prevent external linkage leakage
// namespace {

// an integer constant with external linkage
int INTERNAL_CONSTANT = 42;

// a string constant with external linkage
std::string Filename = "file.txt";

// a non-static function with external linkage
void FreeFunction()
{
	cout << "Free function called" << endl;
}

// Uncomment the next line to prevent external linkage leakage
//}


namespace apibook {

void MyObject::SetValue(int value)
{
	mValue = value;
}

int MyObject::GetValue() const
{
	return mValue;
}

}
