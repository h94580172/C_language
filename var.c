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

int binarySearch(int arr[], int left, int right, int target){
    int mid = left+((right-left)/2);
    if(mid > target)
        return right = mid-1;
    else   
        return left = mid+1;

}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 12;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result == -1)
        printf("目標值 %d 不存在於陣列中。\n", target);
    else
        printf("目標值 %d 在陣列中的索引為 %d。\n", target, result);

    return 0;
}