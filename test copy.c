#include <stdio.h>

void quick_sort(int arr[], int left, int right)
{
  if (left > right)
    return 0;
  
  int pivotIndex, temp;

    // 以第一個元素作為基準
    pivotIndex = left;

    // 以遞增方式排序
    while (left < right)
    {
      while (arr[left] <= arr[pivotIndex] && left < right)
      {
        left++;
      }
      while (arr[right] > arr[pivotIndex])
      {
        right--;
      }

      if (left < right)
      {
        // 交換元素
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
      }
    }

    // 交換基準元素與 right 元素
    temp = arr[pivotIndex];
    arr[pivotIndex] = arr[right];
    arr[right] = temp;

    // 遞迴呼叫快速排序法函數
    quick_sort(arr, left, right - 1);
    quick_sort(arr, right + 1, right);
}

int main()
{
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);
  quick_sort(arr, 0, n - 1);
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  return 0;
}
