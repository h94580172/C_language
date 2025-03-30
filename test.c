#include <stdio.h>

int main() {
    char *str[ ][2] =
        { "professor", "Justin" ,
        "teacher", "Momor" ,
        "student", "Caterpillar"};

    char *str2[ ][3] =
        { "professor", "Justin" ,
        "teacher", "Momor" ,
        "student", "Caterpillar"};

    char str3[3][10] = {"professor", "Justin", "etc"};
    printf("%s\n",str[1][1]); 
    printf("%s\n",str2[1][1]);
    printf("%c\n",str3[1][1]); 
}