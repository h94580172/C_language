#include <stdio.h>

int func(int num){
    if(num <= 1){
        return 0;
    }
    for(int i=2; i<num; i++){
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int input;
    printf("input:");
    scanf("%d",&input);

    if(func(input)){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }
    return 0;
}