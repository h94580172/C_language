#include <stdio.h>

int main(){
    int arr1[] = {10,20};
    int arr2[] = {10,20};
    int arr3[] = {10,20};
    int *p = arr1;
    int *q = arr2;
    int *r = arr3;
    ++*p;
    *q++;
    *++r;
    printf("%d %d %d\n", arr1[0], arr1[1], *p);11 20 11
    printf("%d %d %d\n", arr2[0], arr2[1], *q);10 20 20
    printf("%d %d %d\n", arr3[0], arr3[1], *r);11 20 11
}