#include <stdio.h>

void bubble_sort(int arr, int n){
   
}

int main()
{
   int arr[] = {64, 34, 25, 12, 22, 11, 90};
   int n = sizeof(arr)/sizeof(arr[0]);
   bubble_sort(arr,n);
   for (int i = 0; i < n; i++)
      printf("%d ",arr[i]);
   printf("\n",0);
   return 0;
}