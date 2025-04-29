#include <stdio.h>

#define DEBUG

#ifndef DEBUG
#error "You must define the DEBUG macro"
#endif

#include <stdio.h>

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b,a%b);
}

int main() {
    printf("GCD: %d\n", gcd(25,10));

    return 0;
}
