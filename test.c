#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    
    int prev = 0;
    int current = 1;
    int next;

    for (int i = 2; i <= n; i++) {
        next = prev + current;
        prev = current;
        current = next;
    }

    return current;
}

int main() {
    int n;
    printf("input:");
    scanf("%d",&n);
    printf("%d\n",fibonacci(n));
    return 0;
}