#include <stdio.h>

int main() {
    int rows, i, j, space;

    printf("請輸入行數：");
    scanf("%d", &rows);

    space = rows - 1; // 計算空格數

    // 打印上半部分的菱形
    for (i = 1; i <= rows; i++) {
        // 打印空格
        for (j = 1; j <= space; j++) {
            printf(" ");
        }

        // 打印星號
        if (i == rows) {
            printf("*\n"); // 最後一行只打印一顆星號後換行
        } else {
            printf("* "); // 其他行打印星號後跟一個空格
        }

        space--;
    }

    space = 1; // 重置空格數

    // 打印下半部分的菱形
    for (i = 1; i <= rows - 1; i++) {
        // 打印空格
        for (j = 1; j <= space; j++) {
            printf(" ");
        }

        // 打印星號
        if (i == rows - 1) {
            printf("*\n"); // 倒數第二行只打印一顆星號後換行
        } else {
            printf("* "); // 其他行打印星號後跟一個空格
        }

        space++;
    }

    return 0;
}