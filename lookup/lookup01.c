#include <stdio.h>
#include <string.h>

char *flab[] = {
	"actually",
	"just",
	"quite",
	"really",
	NULL
};

int lookup(char *word, char *array[])
{
	int i;
	for (i = 0; array[i] != NULL; i++)
		if (strcmp(word, array[i]) == 0)
			return i;
	return -1;
}

int main()
{
	int index1 = lookup("quite", flab);
	int index2 = lookup("just", flab);
	int index3 = lookup("fine", flab);

	printf("index1: %d, index2: %d, index3: %d", index1, index2, index3);

	return 0;
}