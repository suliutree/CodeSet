#include <iostream>
#include <vector>
#include <string>

#include "Pic.h"

using namespace std;

char *init[] = {"Pairs", "in the", "Spring"};

int main()
{
	vector<string> i;
	for (int j = 0; j < 3; ++j)
		i.push_back(init[j]);

	Picture p(i);
	cout << p << endl;
	Picture q = p;
	cout << q << endl;

	system("pause");
	return 0;
}