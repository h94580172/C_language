#include <stdio.h>

void quick_sort(int *arr, int left, int right){
    if(left < right){
        int l = left;
        int r = right;
        int key= arr[left];
        while(l != r){
            while(arr[r] > key && l < r){
                r--;
            }
            while(arr[l] <= key && l < r){
                l++;
            }
            if(l < r){
                int temp = arr[l];
                arr[l] = arr[r];
                arr[r] = temp;
            }
        }
        arr[left] = arr[l];
        arr[l] = key;
        quick_sort(arr, left, l-1);
        quick_sort(arr, l+1, right);
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr, 0, n-1);
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}