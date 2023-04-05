#include <stdio.h>

int main(void)
{
    int var = 10;
    int *ptr = &var;          
    printf("ptr = %p\n ", ptr);   // 0061FF18 <<取得var的記憶體位置
    printf("ptr = %d\n ", *ptr);   // 10 <<取得*ptr的數值
}