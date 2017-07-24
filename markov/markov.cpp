#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <map>
#include <vector>

using namespace std;

const int NPREF = 2;
const char NONWORD[] = "\n";
const int MAXGEN = 10000;

typedef deque<string> Prefix;
map<Prefix, vector<string> > statetab;

void build(Prefix&, istream&);
void generate(int nwords);
void add(Prefix& , const string&);

int main()
{
	int nwords = MAXGEN;
	Prefix prefix;

	ifstream infile;
	infile.open("test.txt");
	istream &s = infile;

	srand(time(NULL));
	for (int i = 0; i < NPREF; ++i)
		add(prefix, NONWORD);
	build(prefix, s);
	add(prefix, NONWORD);
	generate(nwords);
	return 0;
}

void build(Prefix &prefix, istream &in)
{
	string buf;
	while (in >> buf)
		add(prefix, buf);
}

void add(Prefix &prefix, const string &s)
{
	if (prefix.size() == NPREF)
	{
		statetab[prefix].push_back(s);
		prefix.pop_front();
	}
	prefix.push_back(s);
}

void generate(int nwords)
{
	Prefix prefix;
	int i;

	for (i = 0; i < NPREF; ++i)
		add(prefix, NONWORD);

	for (i = 0; i < nwords; ++i)
	{
		vector<string>& suf = statetab[prefix];
		const string &w = suf[rand() % suf.size()];
		if (w == NONWORD)
			break;
		cout << w << " ";
		prefix.pop_front();
		prefix.push_back(w);
	}
}
