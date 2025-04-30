#include <stdio.h>

int mul_32(unsigned int x){
    x = x + 31;
    x = x & ~31; 
    return x;
}

int main()
{
    printf("%d\n",mul_32(95));
    return 0;
}