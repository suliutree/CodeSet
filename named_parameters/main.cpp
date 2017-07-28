// Martin Reddy


#include "timer.h"

using namespace apibook;

int main(int, char **)
{
	// NPI: Named Parameter Idiom 命名参数惯用法
	// Named parameters let the programmer pass the parameters to a function
	// in any order and they are distinguished by a name. So the programmer 
	// can explicitly pass all the needed parameters and default values without
	// worrying about the order used in the function declaration.
	// The NPI lets you create method chains to simulate optional params
	Timer timer = Timer().SetDelay(10.0).SetSingleShot(true).Start();

	return 0;
}
