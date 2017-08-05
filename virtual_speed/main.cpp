/// \file   main.cpp
/// \author Martin Reddy
/// \brief  Time method class for virtual/nonvirtual call.

#include "myclass.h"
#include "autotimer.h"
#include <iostream>

using std::cout;
using std::endl;

int main(int, char **)
{
	size_t iterations = 0;

	// print the sizes of the 2 classes
	cout << "sizeof(NonVirtualClass) = " << sizeof(NonVirtualClass)
		 << " bytes" << endl;
	cout << "sizeof(DerivedClass)    = " << sizeof(DerivedClass)
		 << " bytes" << endl;

	// work out roughly how many iterations we can do in 1 sec
	{
		AutoTimer timer("Calibration");
		NonVirtualClass my_class;
		while (true) {
			my_class.DoSomething();
			if (iterations++ % 1000 == 0 && timer.GetElapsed() >= 1.0) {
				break;
			}
		}
	}

	// time a tight loop calling a non-virtual method
	{
		AutoTimer timer("NonVirtualClass");
		NonVirtualClass my_class;
		for (size_t i = 0; i < iterations; i++) {
			my_class.DoSomething();
		}
	}

	// time a tight loop calling an overridden virtual method
	{
		AutoTimer timer("DerivedClass");
		DerivedClass my_class;
		for (size_t i = 0; i < iterations; i++) {
			my_class.DoSomething();
		}
	}

	return 0;
}
