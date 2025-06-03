#include <stdio.h>

int checkbit(int x, int n){
    return (x >> n) & 1; 
}

int main() {
    int n = 1;
    printf("n=%d",checkbit(n,1));
}