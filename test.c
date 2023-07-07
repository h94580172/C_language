#include <stdio.h>
#include <stdbool.h>

int isPrime(int num){
    int i;
    if(num==1){
        return 0;
    }else{
        for(i=2;i<num;i++){
            if(num%i==0){
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n;
    printf("輸入整数：");
    scanf("%d", &n);

    if (isPrime(n)) {
        printf("%d 質數\n", n);
    } else {
        printf("%d 不是質數\n", n);
    }

    return 0;
}