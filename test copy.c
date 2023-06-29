#include <stdio.h>
#include <stdlib.h>

#define NUM 501

void func(int *nums){
    int count = 0;
    while(count < NUM){
        int temp = rand() % NUM;
        if(nums[temp] == 0){
            nums[temp] = 1;
            count++;
            printf("%d ",temp);
        }
    }
}

int main(){
    int nums[NUM];
    for(int i=0; i<NUM; i++){
        nums[i] = 0;
    }
    func(nums);
    return 0;
}