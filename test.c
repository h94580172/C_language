#include <stdio.h>

main() {
    char a[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *tmp = a + 10;
    printf("%c\n", *(tmp - 10));
    printf("%c\n", &tmp[3] + 20);
}
// void main()
// {
//     #define SWAP(a,b) tmp = a; a = b ; b= tmp;
//     int a = 10;
//     int b = 20;
//     int tmp = 0;
//     int n = 6;
//     printf("%d %d %d\n",tmp,a,b); 
//     if(n > 6) SWAP(a,b);
//     printf("%d %d %d\n",tmp,a,b); 
// }

// 以下是一個用C語言實現上述功能的函數：

// c
// Copy code
// int check_hex(unsigned short num) {
//     // 將數字轉換為16進制字串
//     char hex_str[5];
//     sprintf(hex_str, "%04X", num);
    
//     // 檢查字串中的每個字符是否都相同
//     for (int i = 0; i < 4; i++) {
//         if (hex_str[i] != hex_str[0]) {
//             return 0;
//         }
//     }
//     return 1;
// }
// 函數接受一個 unsigned short 類型的數字，將其轉換為一個四位的16進制字串，然後檢查這個字串中的每個字符是否都相同。如果是，返回1，否則返回0。

// 您可以將此函數添加到您的C代碼中，然後使用以下代碼進行測試：

// c
// Copy code
// unsigned short num1 = 0xFFFF;
// unsigned short num2 = 0xAAAB;

// if (check_hex(num1)) {
//     printf("%04X is all the same hex digit\n", num1);
// } else {
//     printf("%04X is not all the same hex digit\n", num1);
// }

// if (check_hex(num2)) {
//     printf("%04X is all the same hex digit\n", num2);
// } else {
//     printf("%04X is not all the same hex digit\n", num2);
// }
// 當 num1 為 0xFFFF 時，check_hex 函數將返回1，因為它是所有相同16進制數位。當 num2 為 0xAAAB 時，check_hex 函數將返回0，因為它不是所有相同16進制數位。



