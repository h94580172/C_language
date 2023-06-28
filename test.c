#include <stdio.h>

int function(int n){
    if(n <= 1){
        return n;
    }
    int prep = 0;
    int curr = 1;
    int next;
    for(int i=2; i<=n; i++){
        next = prep+curr;
        prep = curr;
        curr = next;
    }
    return curr;
}

int main() {
    int n;
    printf("input:");
    scanf("%d",&n);
    printf("%d\n",function(n));
    return 0;
}
