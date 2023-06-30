#include <stdio.h>

void quick_sort(int data[], int left, int right) 
{
    if (left >= right) {
        return 0;
    }

    int l = left;
    int r = right;
    int key = data[left];

    while (l != r) {
        while (data[r] > key && l < r) {
            r--;
        }
        while (data[l] <= key && l < r) {
            l++;
        }
        if (l < r) {
            int temp = data[l];
            data[l] = data[r];
            data[r] = temp;
        }
    }

    data[left] = data[l];
    data[l] = key;

    quick_sort(data, left, l - 1);
    quick_sort(data, l + 1, right);
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
