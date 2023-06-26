#include <stdio.h>
#define MIN(a,b) (a < b ? a : b)
#ifndef DEBUG
#error "12354564564"
#endif

int bubbleSort(int arr[],int n){
    for(int i=0; i<n-1 ;i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
            printf("%d ",arr[j]);
        }
        printf("\n");
    }
}
 
// int main()
// {
//     int arr[] = {64, 34, 25, 12, 22, 11, 90};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     bubbleSort(arr, n);
//     printf("Sorted array: \n");
//     for (int i=0; i < n; i++)
//         printf("%d ", arr[i]);
//     return 0;
// }


int main()
{
    printf("min:%d\n",MIN(88,6));
    return 0;
}

