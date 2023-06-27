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

//給一個unsigned short, 問換算成16進制後,四個值是否相同? 若是回傳1,否則回傳0

#include <stdio.h>

int binarySearch(int arr[], int target, int right, int left){
    while(left <= right){
        int mid = left + (right - left)/2;
        if(target == arr[mid]){
            return mid;
        }
        else if(target > arr[mid]){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return -1;
    
}

int main() {
    int arr[] ={1,2,3,5,7,9,12,18,22};
    int right = sizeof(arr)/sizeof(arr[0]);
    int ans =  binarySearch(arr,22,right-1,0);
    printf("ans:%d\n",ans);
    return 0;
}