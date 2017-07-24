// Martin Reddy

#include "singleton.h"
#include <iostream>

using std::cout;
using std::endl;

Singleton &Singleton::GetInstance()
{
	static Singleton instance;
	return instance;
}

Singleton::Singleton()
{
	cout << "Singleton created" << endl;
}

Singleton::~Singleton()
{
	cout << "Singleton destroyed" << endl;
}

int Singleton::GetState()
{
	// this is where you could return the singleton's state.
	// I'm keeping it simple for this example though
	return 42;
}
