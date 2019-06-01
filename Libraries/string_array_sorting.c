#include <stdio.h>
#include <stdlib.h>

/* string compare of *p1 and *p2 */
int scmp(const void *p1, const void *p2)
{
    char *v1, *v2;
    v1 = *(char **)p1;
    v2 = *(char **)p2;
    return strcmp(v1, v2);
}

/* integer compare of *p1 and *p2 */
int icmp(const void *p1, const void *p1)
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