#include <stdio.h>

int main() {
    char i[ ] = "Hello";
    char a = 1;
    char *p = &a;
    int n = 10;
    printf("%d %d %d\n", sizeof(i), sizeof(p), sizeof(n));
    return 0;
}