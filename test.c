#include <stdio.h>

int main() {
    int x=9;
    for(int i=0; i<5; i++){
        for(int s=0; s<i; s++){
            printf(" ");
        }
        for(int n=9-2*i; n>0; n--){
            printf("%d",x);
        }
        x-=2;
        printf("\n");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{   
    int space = 0;
    for (int i = 9; i > 0 ; i -= 2){
        int k = space;
        if (i <= 7){
            while(k>0){
                printf(" ");
                k--;
            }
        }
        for (int j = i; j > 0; j--){
            printf("%d",i);
        }
        space++;
        printf("\n");
    }
    return 0;
}