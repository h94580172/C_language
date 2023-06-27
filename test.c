// #include <stdio.h>
// #define MIN(a,b) (a < b ? a : b)
// #ifndef DEBUG
// #error "12354564564"
// #endif

// int bubbleSort(int arr[],int n){
//     for(int i=0; i<n-1 ;i++){
//         for(int j=i+1; j<n; j++){
//             if(arr[i] > arr[j]){
//                 int temp = arr[j];
//                 arr[j] = arr[i];
//                 arr[i] = temp;
//             }
//             printf("%d ",arr[j]);
//         }
//         printf("\n");
//     }
// }
 
// // int main()
// // {
// //     int arr[] = {64, 34, 25, 12, 22, 11, 90};
// //     int n = sizeof(arr)/sizeof(arr[0]);
// //     bubbleSort(arr, n);
// //     printf("Sorted array: \n");
// //     for (int i=0; i < n; i++)
// //         printf("%d ", arr[i]);
// //     return 0;
// // }


// int main()
// {
//     printf("min:%d\n",MIN(88,6));
//     return 0;
// }
#include<stdio.h>
#include<stdlib.h>

void diamond()
{
    int i,input,star,space,mid;
    printf("input:");
    scanf("%d",&input);
    mid = (input/2) + 1;
    for(i=1; i<=mid; i++){
        for(space=i; space<mid; space++)    printf(" ");
        for(star=1; star<=(2*i)-1; star++)  printf("*");
        printf("\n");
    }
    for(i=mid-1; i>0; i--){
        for(space=i; space<mid; space++)    printf(" ");
        for(star=1; star<=(2*i)-1; star++)  printf("*");
        printf("\n");
    }
}

void empty_diamond()
{
    int i, input, star, space, mid;
    printf("input");
    scanf("%d", &input);
    mid = (input / 2) + 1;
    for (i = 1; i <= mid; i++) {
        for (space = i; space < mid; space++)
            printf(" ");
        for (star = 1; star <= (2 * i) - 1; star++) {
            if (star == 1 || star == (2 * i) - 1) {
                printf("*"); // 打印星號在第一個和最後一個位置
            } else {
                printf(" "); // 打印空格在其他位置
            }
        }
        printf("\n");
    }
    for (i = mid - 1; i > 0; i--) {
        for (space = i; space < mid; space++)
            printf(" ");
        for (star = 1; star <= (2 * i) - 1; star++) {
            if (star == 1 || star == (2 * i) - 1) {
                printf("*"); // 打印星號在第一個和最後一個位置
            } else {
                printf(" "); // 打印空格在其他位置
            }
        }
        printf("\n");
    }
}

int main()
{
    empty_diamond();
    diamond();
    return 0;
}
