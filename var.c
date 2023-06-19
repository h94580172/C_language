#include <stdio.h>

int main()
{
    int i = 5;
    int j = i++ 
    printf("i1 = %d\n",i);  
    printf("j1 = %d\n",j); 

    i = 5;
    j = ++i; 
    printf("i2 = %d\n",i);  
    printf("j2 = %d\n",j);  
    return 0;
}