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

	Picture q = frame(p);
	cout << q << endl;

	cout << frame(q) << endl;

	Picture r = hcat(p, q);
	cout << r << endl;

	Picture s = vcat(q, r);
	cout << s << endl << frame(s) << endl;

	system("pause");
	return 0;
}