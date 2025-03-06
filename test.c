#include <stdio.h>

#define swap(a,b) {int temp = a; a = b; b = temp;}

int main(){
    int c = 5;
    int d = 10;
    printf("before c=%d,d=%d\n",c,d);
    swap(c,d);
    printf("after c=%d,d=%d\n",c,d);

    return 0;
}