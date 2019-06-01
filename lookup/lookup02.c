#include <stdio.h>
#include <string.h>

typedef struct Nameval Nameval;
struct Nameval {
	char *name;
	int value;
};

Nameval htmlchars[] = {
	"AElig", 	0x00c6,
	"Aacute", 	0x00c1,
	"Acirc", 	0x00c2,
	"Burice", 	0x00b5,
	"Curle", 	0x0078,
	"Diff",		0x0101,
	"Egio",		0x0034,
	"Free",		0x56b3,
	"zeta",		0x7777,
};

int lookup(char *name, Nameval tab[], int ntabs)
{
	int low, high, mid, cmp;
	low = 0;
	high = ntabs - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		cmp = strcmp(name, tab[mid].name);
		if (cmp < 0)
			high = mid - 1;
		else if (cmp > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int main()
{
	int ntabs = sizeof(htmlchars) / sizeof(htmlchars[0]);
	int index1 = lookup("Egio", htmlchars, ntabs);
	int index2 = lookup("Acirc", htmlchars, ntabs);
	int index3 = lookup("Nothing", htmlchars, ntabs);

	printf("index1: %d, index2: %d, index3: %d", index1, index2, index3);

	return 0;
}