#include <stdio.h>

int main()
{
    int a;
    printf("input:");
    scanf("%d",&a);
    switch(a){
        case 0:
            printf("0\n");
            break;
        case 1:
            printf("1\n");
            break;
        case 2:
            printf("2\n");
            break;
        default:
            printf("x\n");
            break;
    }
    return 0;
}