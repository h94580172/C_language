#include <stdio.h>

int main() {
    printf("ans=%d\n",fun(456)+fun(123)+fun(789));
}

int fun(int x){
   int count = 0 ;
   while(x){
      count++ ;
      x = x & (x-1) ;
   }
   return count ;
}