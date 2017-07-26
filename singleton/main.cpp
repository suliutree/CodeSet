// Martin Reddy

#include "singleton.h"
#include <iostream>

using std::cout;
using std::endl;

int main(int, char **)
{
	cout << "main() called" << endl;

	// singleton gets created here
	Singleton &foo = Singleton::GetInstance();
	foo.GetState();

	// returns previously allocated singleton here
	Singleton &foo2 = Singleton::GetInstance();
	foo2.GetState();

	return 0;
}
