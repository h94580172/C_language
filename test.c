#include <stdio.h>

int c;

int fib(int n){
    c++;
    if ((n==1)|| (n==2))
        return 1;
    return (fib(n-1)+fib(n-2));
}

int main(){
    c = 0;
    fib(5);
    printf("%d", c);
    return 0;
}