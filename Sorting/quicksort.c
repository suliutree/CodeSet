#include <stdio.h>
#include <stdlib.h>

void swap(int v[], int i, int j);

void quicksort(int v[], int n)
{
    int i, last;
    if (n <= 1)
        return;
    swap(v, 0, rand() % n); /* move pivot elem to v[0] */
    last = 0;
    for (i = 1; i < n; ++i) /* partition */
        if (v[i] < v[0])
            swap(v, ++last, i);
    swap(v, 0, last);
    quicksort(v, last);
    quicksort(v+last+1, n-last-1);
}

void swap(int v[], int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main()
{
    int array[] = {4, 3, 2, 7, 5, 9, 1, 3, 6};
    int length = sizeof(array) / sizeof(array[1]);

    printf("original array: ");
    for (int i = 0; i < length; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    quicksort(array, length);

    printf("sorted array: ");
    for (int i = 0; i < length; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}