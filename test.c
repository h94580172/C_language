// ## ***39. 0~500個數字每次隨機 取一個數字出來，但下次在抽出時不可以出現已經抽過的數字，問你如何時實現。***

#include <stdio.h>
#include <stdlib.h>


void random(int *arr) {
    int count = 0; // 已經抽出的數字個數
    while (count < 501) {
    int num = rand() % (501); // 隨機產生一個數字
        if (arr[num] == 0) { // 如果這個數字還沒被抽過
            arr[num] = 1; // 標記為已經抽過
            count++; // 已經抽出的數字個數加 1
            printf("%d ", num);
        }
    }
}

int main() {
    int nums[501];
    for (int i = 0; i < 501; i++) {
        nums[i] = 0;
    }
    random(nums);
    return 0;
}
// int cnt=0;
// void swap(int *a, int *b){
// 	int tmp = *a;
// 	*a = *b;
// 	*b = tmp;
// }

// int main()
// {
// 	int arr[501]; 
// 	for(int i = 0; i < 501; i++){
// 		arr[i] = i;
// 	}
// 	int final_idx = 500;
// 	int choose_idx;
// 	while(1){
		
// 		choose_idx = rand() % (final_idx + 1);
// 		printf("%d\n",arr[choose_idx]);
//         cnt++;
// 		if(final_idx == 0)
// 			break;
		
// 		swap(&arr[choose_idx],&arr[final_idx]);
// 		final_idx--;
// 	}
//     printf("cnt=%d\n",cnt);
// }