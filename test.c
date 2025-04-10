#include <stdio.h>

int func(int num){
    int sum = 0;
    while(num){
        num &= (num-1);
        sum++;
    }
    return sum;

}
int main()
{
    printf("sum=%d\n",func(9));

    return 0;
}
