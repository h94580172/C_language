#include <stdio.h>

int main() {
    int i = 3;
    i = (i << 2) + (i << 1) + (i << 0);
    printf("i = %d\n",i);
}