// Martin Reddy

#include "currency.h"
#include <iostream>

int main(int, char **)
{
	// use one of the operator functions of Currency
	apibook::Currency c1(100);
	apibook::Currency c2(150);

	c1 += c2;

	std::cout << "Currency: " << c1 << std::endl;

	return 0;
}
