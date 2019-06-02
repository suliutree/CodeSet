#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* string compare of *p1 and *p2 */
int scmp(const void *p1, const void *p2)
{
    char *v1, *v2;
    v1 = *(char **)p1;
    v2 = *(char **)p2;
    return strcmp(v1, v2);
}

/* integer compare of *p1 and *p2 */
int icmp(const void *p1, const void *p2)
{
    int v1, v2;
    v1 = *(int *)p1;
    v2 = *(int *)p2;
    if (v1 < v2)
        return -1;
    else if (v1 == v2)
        return 0;
    else
        return 1;
}


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

int nvcmp(const void *va, const void *vb);

/* use bsearch to find name in tab, return index */
int lookup(char *name, Nameval tab[], int ntab)
{
    Nameval key, *np;

    key.name = name;
    key.value = 0;
    np = (Nameval *)bsearch(&key, tab, ntab, sizeof(tab[0]), nvcmp);
    if (np == NULL)
        return -1;
    else
        return np - tab;
}

/* compare two Nameval names */
int nvcmp(const void *va, const void *vb)
{
    const Nameval *a, *b;

    a = (Nameval *)va;
    b = (Nameval *)vb;
    return strcmp(a->name, b->name);
}

int main()
{
    // string array sorting
    char *str[] = {
        "book",
        "array",
        "something",
        "anything",
        "without",
        "change",
        "zip",
        "package"
    };

    int array_length = sizeof(*str) / sizeof(str[0][0]);

    printf("original array: \n");
    for (int i = 0; i < array_length; ++i)
    {
        printf("%s\n", str[i]);
    }

    qsort(str, array_length, sizeof(str[0]), scmp);

    printf("sorted array: \n");
    for (int i = 0; i < array_length; ++i)
    {
        printf("%s\n", str[i]);
    }

    // integer array sorting
    int arr[] = {12, 34, 32, 90, 45, 65, 43, 888, 79, 234};
    int int_length = sizeof(arr) / sizeof(arr[0]);

    printf("original int array: ");
    for (int i = 0; i < int_length; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    qsort(arr, int_length, sizeof(arr[0]), icmp);

    printf("sorted int array: ");
    for (int i = 0; i < int_length; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Nameval lookup
    int ntab = sizeof(htmlchars) / sizeof(htmlchars[0]);
    int index1 = lookup("Acirc", htmlchars, ntab);
    int index2 = lookup("Nothing", htmlchars, ntab);
    int index3 = lookup("Free", htmlchars, ntab);

    printf("index1: %d, index2: %d, index3: %d", index1, index2, index3);

    return 0;
}