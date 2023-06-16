#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int var = 0x67a9;
    int *ptr = &var;
    printf("p1=%x\n", ptr); // p1=67a9
    // ptr = 0xaa55;
    // printf("p2=%x\n", ptr); // p2=aa55
}