#include <stdio.h>

int main() {
    long ans = 0;
    short a = 0x1234;
    short b = 0x5600;
    ans += a << 16;
    ans += b << 0;
    ans += (b >> 2) + 0x22;
    printf("a=%x\n",ans);
}
// 1234 5600 +1580+0022
// 1234 1580
//      0022
// 1234 6BA2
// 1 5 8 0
