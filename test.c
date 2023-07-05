#include <stdio.h>

void func1(){
    printf("a");
}

void func2(){
    printf("b");
}

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int *p = (int*)(&a+1);
    // printf("%d\n",p);
    // printf("%d\n",*(a+1));
    printf("%d\n",(*p-1));
}