#include <stdio.h>
#include <stdlib.h>
void function(int num){
    int space,star;
    int mid = num/2;
    for(int i=0; i<=mid; i++){
        for(space=i; space<mid; space++){
            printf(" ");
        }
        for(star=0; star<=i; star++){
            printf("*");
        }
        printf("\n");
    }
    for(int i=mid-1; i>0; i--){
        for(space=i; space<mid; space++){
            printf(" ");
        }
        printf("\n");
    }
}

int main() {
    function(5);
    return 0;
}