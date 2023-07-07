#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    printf("请输入一个整数：");
    scanf("%d", &n);

    if (isPrime(n)) {
        printf("%d 質樹\n", n);
    } else {
        printf("%d 不是質數\n", n);
    }

    return 0;
}
