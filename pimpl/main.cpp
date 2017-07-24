#include "autotimer.h"
#include <iostream>

using std::cout;
using std::endl;

int main(int, char **)
{
	apibook::AutoTimer timer("MyTimer");

	for (int i = 0; i < 1000; ++i)
	{
		cout << ".";
	}
	cout << endl;

	return 0;
}
