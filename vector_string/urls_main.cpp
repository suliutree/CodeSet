#include <algorithm>
#include <cctype>
#include <iostream>
#include "Str.h"
#include "Vec.h"
#include "urls.h"

using namespace std;

int main()
{
	Str s;
	while (getline(cin, s))
	{
		Vec<Str> v = find_urls(s);
		for (Vec<Str>::const_iterator it = v.begin(); it != v.end(); ++it)
			cout << *it << endl;
	}

	system("pause");
	return 0;
}