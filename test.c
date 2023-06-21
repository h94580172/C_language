#include <stdio.h>

int main()
{
    int arr[3][4];
    printf("1:%d\n", sizeof(arr));  // 結果為 48（3 * 4 * 4(int)）

    char str[2][10];
    printf("2:%d\n", sizeof(str));  // 結果為 20（2 * 10 * 1(char)）

    int* ptr[5][3];
    printf("3:%d\n", sizeof(ptr));  // 結果為 120（5 * 3 * 8(int*)）

    struct Point 
    {
        int x;
        int y;
    };

    struct Point points[4][3];
    printf("4:%d\n", sizeof(points));  // 結果為 96（4 * 3 * 8(struct Point)）
    return 0;
}
