#include <stdio.h>

typedef struct MyStruct1
{
    char a[2];
    int b;
    double c;
    int *Pint;
    char d;
    char* Pchar;
} MyStruct1;

typedef struct MyStruct2
{
    char a;
    char b;
    struct str2
    {
        int d;
    } c;
}MyStruct2;

typedef struct MyStruct3
{
    char a;
    int b;
    char c;
    char* d;
    double* e;
    struct str3
    {
        int f;
        char g;
        struct str33
        {
            char* p;
        }n;
    } m;
}MyStruct3;

typedef struct MyStruct4
{
    char a;
    char b;
    struct str4
    {
        char c;
        char d;
    };
}MyStruct4;

int main() {
    printf("1. %zu\n", sizeof(MyStruct1));4+4+8+8+8+8=40
    printf("2. %zu\n", sizeof(MyStruct2));1+1+2+4=8
    printf("3. %zu\n", sizeof(MyStruct3));4+4+8+8+8+4+8+8=52
    printf("4. %zu\n", sizeof(MyStruct4));1+1
    return 0;
}