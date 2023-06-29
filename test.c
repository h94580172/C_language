#include <stdio.h>
#include <string.h>

void string_reverse(char *s){
    int left = 0;
    int right = strlen(s)-1;
    while(left < right){
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

int main() {
    char s[] = "abcde";
    string_reverse(s);
    printf("%s\n",s);
    return 0;
}

