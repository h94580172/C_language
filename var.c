// #include <stdio.h>

// typedef union {
//     struct {
//         unsigned int ALT : 1;
//         unsigned int USB : 1;
//         unsigned int PD : 1;
//         unsigned int DC : 1;
//         unsigned int reserved : 4;
//     } st;
//     unsigned char state;
// } state_t;

// int main() {

//     state_t gv31;
//     gv31.state = 0x07;
//     if(gv31.state && gv31.st.ALT == 1) {
//         printf("ALT: %d\n", gv31.st.ALT);
//     }
//     if(gv31.state && gv31.st.USB == 1) {
//         printf("USB: %d\n", gv31.st.USB);
//     }
//     if(gv31.state && gv31.st.PD == 1) {
//         printf("PD: %d\n", gv31.st.PD);
//     }
//     if(gv31.state && gv31.st.DC == 0) {
//         printf("DC: %d\n", gv31.st.DC);
//     }
//     return 0;
// }
#include <stdio.h>
#include <string.h>
// 給一個int a[20]已排序的陣列，請寫一個function(a, size)能印出0~500的數字，且不包含a陣列內的元素

void functionq(int *a,int size){
    for(int i = 0,j = 0; i<=size; i++){
        if(a[j] == i)
            j++;
        else
            printf("i=%d\n",i);
    }
}

// void functionq(int *a,int size)
// {
//  for(int i=0; i<=500; i++)
//  {
//     if(i == *a)
//         a++;
//     else
//         printf("%d\n",i);
//     }
// }

int main(void) 
{
    int a[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,21};
    functionq(a,500);
    return 0;
}