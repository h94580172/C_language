#include <stdio.h>

int main()
{
    int i = 5;
    int j = i++;
    printf("i1 = %d\n",i);  
    printf("j1 = %d\n",j);  

    i = 5;
    j = ++i; 
    printf("i2 = %d\n",i);
    printf("j2 = %d\n",j);  

    int A=2 , AA=0;
    int B=2 , BB=0;

    AA = (A++) + (A++);
    BB = (++B) + (B++);
    printf("A=%d   B=%d\n",AA,BB);

    return 0;
}
