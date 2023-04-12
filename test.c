#include <stdio.h>
#include <stdlib.h>

int values[] = { 40, 10, 100, 90, 20, 25 };

int compare(const void *a, const void *b)
{
    return (*(const int*)a - *(const int*)b);
}

int main()
{
    int n, i;
    n = sizeof(values) / sizeof(values[0]);

    printf("Before sorting the list is: \n");
    for (i = 0; i < n; i++)
        printf("%d ", values[i]); // 40 10 100 90 20 25

    qsort(values, n, sizeof(int), compare);

    printf("\nAfter sorting the list is: \n");
    for (i = 0; i < n; i++)
        printf("%d ", values[i]); // 10 20 25 40 90 100

    return 0;
}