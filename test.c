#include <stdio.h>

int function(int n) {
  if (n <= 1)
        return n;
  
  return function(n - 1) + function(n - 2); 
}

int main() {
    int n;
    printf("input:");
    scanf("%d",&n);
    printf("%d\n",function(n));
    return 0;
}