#include <stdio.h>

int n2(int n){
    return ((n > 0) && (n&(n-1)) == 0);
}

int main(void)
{
    printf("\n%d",n2(8));

    return 0;
}