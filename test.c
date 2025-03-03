#include <stdio.h>

void function(int n)
{
    printf("check : %s\n",(n / n * n == n) ? "yes" : "no");
}

int main() {
    function(3);
    return 0;
}