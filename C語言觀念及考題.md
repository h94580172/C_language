# **C語言觀念及考題**

---

## ***1. point***

* 指標 (pointer)：

```c
#include <stdio.h>

int main(void)
{
    int var = 10;
    int *ptr;
    ptr = &var;          
    printf("ptr = %p\n ", ptr);   // 0061FF18 <<取得var的記憶體位置
    printf("ptr = %d\n ", *ptr);   // 10 <<取得*ptr的數值
}

```

* 函式指標 (function pointer) : 

```c
void printInt(int num){
    printf("%d\n", num);
}

void applyFunction(int num, void (*functionPtr)(int)){  //void (functionPtr)(int)也一樣意思
    functionPtr(num);
}

int main(){
    applyFunction(5, printInt);
    return 0;
}

//也可用typedef方式

typedef void (*functionPtr)(int);

void printInt(int num){
    printf("%d\n", num);
}

void applyFunction(int num, functionPtr func){
    func(num);
}

int main(){
    applyFunction(5, printInt);
    return 0;
}
```

* 基礎指標判讀

```c
int a; // 一個整數型別
int *a; // 一個指向整數的指標
int **a; // 一個指向指標的指標，而"指向的指標"是指向一個整數型別
int a[10]; // 一個有10個整數型的陣列
int *a[10]; // 一個有10個指標的陣列，該指標是指向一個整數型別
int [*a](10); // 一個指向有10個整數型陣列的指標
int (*a)(int); // 一個指向函數的指標，該函數有一個整數型參數並返回一個整數
int (*a[10])(int); // 一個有10個指標的陣列，該指標指向一個函數，該函數有一個整數型參數並返回一個整數
```

## ***2. call by value, call by reference, call by address***

* Call by value : 最常見的函式寫法，呼叫者和被呼叫者的變數各自佔有記憶體，將參數複製再傳給函式。
註：C 語言之父明確表示 C 語言只有 call by value。

```c
#include <stdio.h>

int swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main(void)
{
    int a = 5;
    int b = 10;
    swap(a, b);
    printf(" a = %d b = %d", a, b); // a = 5,b = 10
}

// 數值沒交換是因為在 C 語言中，默認的參數傳遞是call by value，函數內部改變的參數並不能影響到函數外的變數。
```

* Call by reference : 呼叫者和被呼叫者的變數使用相同的記憶體位址，因此在被呼叫函式中改變變數時，變動結果會保留。
註：傳參考是C++才有的東西，C語言是沒有的唷!

```c
void swap(int &c, int &d)
{
    int temp = c;
    c = d;
    d = temp;
}
int main()
{
    int a = 5, b = 10;
    swap(a, b);
    printf(" %d %d ", a, b);
    return 0;
}

// 在 C 語言中沒有Call by reference,故編譯時會有錯誤
```

* Call by address : 傳指標，仍然也是call by value，只不過複製的值Value剛好就是位址address

```c
#include <stdio.h>

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int a = 5;
    int b = 10;
    swap(&a, &b);
    printf(" a = %d b = %d", a, b);// a = 10, b = 5
}

// 透過指標去傳遞位址(Call by address)，可將函數內的變數作為指向該變數的指標傳遞給函數，從而讓函數內的變數直接更改函數外的變數。
```

## ***3. variable scope and lifetime***

* local 變數 : local 變數僅活在該函式內，存放位置在 stack 或 heap 記憶體中。

```c
#include <stdio.h>

void count(); 

int main(void) 
{ 
    for(int i = 0; i < 10; i++) {
        count(); 
    }

    return 0; 
} 

void count() 
{ 
    int c = 1; 
    printf("%d\n", c); // c = 1 c = 1...
    c++; 
}
```

* static 變數 : static 變數生命周期 (life time) 跟程式一樣長，而範圍 (scope) 則維持不變，即在宣告的函式之外仍無法存取 static 變數。

```c
#include <stdio.h>

void count() 
{ 
    static int c = 1; 
    printf("%d\n", c); // c = 1 c = 2...
    c++; 
}

int main(void)
{ 
    for(int i = 0; i < 10; i++) {
        count(); 
    }

    return 0; 
} 
```

* global 變數 : 所有區段皆可使用此變數。

```c
#include <stdio.h>

int c = 1; 

void count() 
{ 
    printf("%d\n", c); // c = 1 c = 2...
    c++; 
}

int main(void)
{ 
    for(int i = 0; i < 10; i++) {
        count(); 
    }

    return 0; 
} 
```

* 記憶體的配置

Stack : 存放函數的參數、區域變數等，由空間配置系統自行產生與回收，會稱作 stack 是由於其配置遵守 LIFO (Last-In-First-Out)。
Heap : 一般由程式設計師分配釋放，執行時才會知道配置大小，如 malloc/new 和 free/delete。
Global : 包含 BSS (未初始化的靜態變數)、data section (全域變數、靜態變數) 和 text/code (常數字元)。

![img](https://3.bp.blogspot.com/-cwf7UwVo2_Y/WYiVjLqxBDI/AAAAAAABU6Y/INc4LASyJEsicGNfCWzdgM_xhZOBXMTUACLcBGAs/s1600/program_in_memory2.png)

## ***4. extern***

C 語言中，extern 關鍵字用於聲明外部變數，表示該變數在當前文件中未定義，但在其他文件中已經定義了。使用 extern 關鍵字聲明變數時，不會為該變數分配存儲空間，只是告訴編譯器在連結時在其他文件中查找該變數的定義。

如果在聲明變數時沒有使用 extern 關鍵字，則表示該變數是一個全局變數，需要在當前文件中定義並分配存儲空間。在其他文件中使用該變數時，需要使用 extern 關鍵字聲明該變數。

簡單來說，如果變數需要在多個文件中共享，就需要使用 extern 關鍵字聲明該變數；如果變數只在當前文件中使用，可以不使用 extern 關鍵字聲明。

```c
// var.c
int a = 10;
```

```c
// main.c
#include "var.c" 

extern int a;

int main() {
    printf("a = %d\n", a); //a = 10
    return 0;
}
```

## ***5. const***

const 通常表示只可讀取不可寫入的變數，常用來宣告常數。使用const有以下好處：

1. 使編譯器保護那些不希望被改變的參數
2. 編譯器處理方式 : define 在預處理階段展開；const 在編譯階段使用。
3. 類型和安全檢查 : const 會在編譯階段會執行類型檢查，define 則不會。
4. 存儲方式 : define 直接展開不會分配記憶體，const 則會在記憶體中分配。

```c
#include <stdio.h>

int main(void)
{
    int n1 = 10, n2 = 100, n3 = 50;

    const int *ptr1 = &n1; // const int* ptr(int const* ptr), ptr是一個指向const int的指標
    *ptr1 = 20; // X
    ptr1 = &n2; // O (ptr1 = 100)

    int* const ptr2 = &n1; // int* const ptr, ptr是一個指向一個整數的const指標
    *ptr2 = 20; // O (ptr2 = 20)
    ptr2 = &n2; // X

    int const * ptr3 const; //一個指向const int的const指標 (指標指向的整數不可修改，同時指標也不可修改)
    *ptr3 = 20; // X 
    ptr3 = &n3; // X

    //const int* const ptr, ptr是一個指向一個const int的const指標
}
```

## ***6. volatile***

volatile 修飾的變數代表它可能會被不預期的更新，因此告知編譯器不對它涉及的地方做最佳化，並在每次操作它的時候都讀取該變數實體位址上最新的值，而不是讀取暫存器的值。

volatile 常見的應用：

1. 修飾中斷處理程式中(ISR)中可能被修改的全域變數。
2. 修飾多執行緒(multi-threaded)的全域變數。
3. 設備的硬體暫存器(如狀態暫存器)

```c
extern const volatile unsigned int rt_clock;
```

這是在 RTOS kernel 常見的一種宣告：rt_clock通常是指系統時鐘，它經常被時鐘中斷進行更新。所以它是volatile。

因此在用的時候，要讓編譯器每次從記憶體裡面取值。而rt_clock通常只有一個寫者（時鐘中斷），其他地方對其的使用通常都是唯讀的。所以將其聲明為 const，表示這裏不應該修改這個變數。

## ***7. inline***

* inline function寫法 :

```c
inline int square(int x) 
{
  return x * x;
}
```

* Macro寫法 :

```c
# define SQUARE(x) ((x) * (x))

printf("\n %d", SQUARE(5)); // 若在主程式中，下述能得到 25，看起來沒有問題

printf("\n %d", SQUARE(3+2)); // 但如果是以下，卻會得到 11 (3+2 * 3+2)
```

* 差異 :
基本上macro和inline function都可以省下速度，但Macro在預處理時(Preprocessor)，直接單純的文字替換，但inline function是在compile階段時，直接取代function。

![img](https://miro.medium.com/v2/resize:fit:720/format:webp/0*wCR1txNEbCz5xKyU.png)

## ***8. #define***

 #define 是巨集，在前置處理器(preprocessor)執行時處理，將要替換的程式碼展開做文字替換。define 語法範例如下：

```c
#define PI 3.1415926 //常數巨集
#define A(x) x //函數巨集
#define MIN(A，B)  ( (A)  <= (B) ? (A) : (B))
```

* 引入防護和條件編譯 :

引入防護 (Include guard) 是一種條件編譯，用於防範 #include 指令重複引入的問題。

```c
#ifndef MYHEADER // 避免重複引入
#define MYHEADER
...
#endif
```

## ***9. 指標與陣列的差別***

就記憶體方向來看，指標所用的記憶體位置不為連續，而"矩陣"所配置的空間為連續。

## ***10. strlen***

* 實作strlen :

```c
int strlen( const char *str )
{
    int len;
    while( (*str++) != '\0' )
    {
        len++;
    }
    return len;
}
```

* strlen範例 :

```c
#include <stdio.h>
#include <string.h>

int main ()
{
   char str[50];
   int len;

   strcpy(str, "GOOD");
   len = strlen(str);
   printf("|%s| 的長度是 |%d|\n", str, len); // GOOD 的長度是 4
   
   return(0);
}
```

## ***11. strcpy***

* 實作strcpy :

```c
void strcpy(char *s, char *t)
{  
    while((*s = *t) != '\0') 
    {
       s++;
       t++;
    }
}
```

* strcpy範例 :

```c
#include <stdio.h>
#include <string.h>
 
int main()
{
   char src[40];
   char dest[100];
  
   memset(dest, '\0', sizeof(dest));
   strcpy(src, "This is runoob.com");
   strcpy(dest, src);
 
   printf("dest = %s\n", dest); // dest = This is runoob.com
   
   return(0);
}
```

## ***12. memcpy***

* 實作memcpy :

```c
void *memcpy(void *dest, const void *src, unsigned long count)
{
    char *tmp = dest;
    const char *s = src;
    while (count--)
        *tmp++ = *s++;
    return dest;
}
```

* memcpy範例 :

```c
#include <stdio.h>
#include <string.h>

struct 
{
  char name[40];
  int age;
} person, person_copy;

int main ()
{
  char myname[] = "Pierre de Fermat";

  /* using memcpy to copy string: */
  memcpy ( person.name, myname, strlen(myname)+1 );
  person.age = 46;

  /* using memcpy to copy structure: */
  memcpy ( &person_copy, &person, sizeof(person) );

  printf ("person_copy: %s, %d \n", person_copy.name, person_copy.age );

  return 0;
}
```

## ***13. memset***

* 實作memset :

```c
void *memset(void *s, char c, unsigned long n)
{
    unsigned long i;
    char *ss = (char *)s;
    for (i=0; i<n; i++)
        ss[i] = (char)c;
    return s;
}
```

* memset範例 :

```c
#include <stdio.h>
#include <string.h>

int main ()
{
    char str[] = "almost";
    printf("str1=%s\n", str); // str1=almost
    memset (str,'-',6);
    printf("str2=%s\n", str); // str2=------
    return 0;
}
```

## ***13. memcmp***

* 實作memcmp :

```c
int memcmp(const void *cs, const void *ct, unsigned long count)
{
    const unsigned char *su1, *su2;
    int res = 0;
    for (su1=cs, su2=ct; 0<count; ++su1, ++su2, count--)
    {
        if ((res = *su1 - *su2) != 0)
            break;
    }
    return res;
}
```

* memcmp範例 :

```c
#include <stdio.h>
#include <string.h>

int main() 
{
    char buffer1[] = "abcde";
    char buffer2[] = "abcDE";
    
    int ret = memcmp(buffer1, buffer2, 3);
    if (ret > 0) {
        printf("buffer1 is greater than buffer2\n");
    } else if (ret < 0) {
        printf("buffer1 is less than buffer2\n");
    } else { // ret == 0
        printf("buffer1 is equal to buffer2\n"); // 前三個相同
    }

    return 0;
}
```

## ***14. malloc***

* 實作malloc :

```c
void* malloc (size_t size);
```

* malloc範例 :

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    char * ptr;
    ptr = (char *) malloc(sizeof(char) * 20);
    strcpy(ptr, "Hello World");
    printf("%s\n", ptr); // Hello World
    free(ptr);
    printf("%s\n", ptr); // NULL
    return 0;
}
```

## ***15. qsort***

* 實作qsort :

```c
#include <stdio.h>
#include <stdlib.h>

int values[] = { 40, 10, 100, 90, 20, 25 };

int compare(const void *a, const void *b)
{
    return (*(const int*)a - *(const int*)b);
}

int main()
{
    int n, i;
    n = sizeof(values) / sizeof(values[0]);

    printf("Before sorting the list is: \n");
    for (i = 0; i < n; i++)
        printf("%d ", values[i]); // 40 10 100 90 20 25

    qsort(values, n, sizeof(int), compare);

    printf("\nAfter sorting the list is: \n");
    for (i = 0; i < n; i++)
        printf("%d ", values[i]); // 10 20 25 40 90 100

    return 0;
}
```

## ***16. bubbleSort***

* bubbleSort範例 :

```c
#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        // Last i elements are already sorted
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
```

## ***17. struct***

struct 是使用者自定的型態，包含數個不同資料型態的變數，將不同的資料型態關聯在一起，使他們的關聯更直覺。

* struct範例 :

```c
#include <stdio.h>

int main()
{
    struct student
    {
        char name[50];
        int id;
        float grade;
    };

    struct student s1 = {"John Doe", 12345, 90.5};

    printf("學生姓名：%s\n", s1.name); // 學生姓名：John Doe
    printf("學生學號：%d\n", s1.id); // 學生學號：12345
    printf("學生成績：%.2f\n", s1.grade); // 學生成績：90.50
}
```

```c
#include <stdio.h>
#include <string.h>

int main()
{
    typedef struct student
    {
        char name[50];
        int id;
        float grade;
    } student;

    student s1;
    strcpy(s1.name, "John Doe"); 
    // 字符串是常量，不能直接分配給字符數組，需要使用 strcpy 函數將字符串複制到字符數組中。
    s1.id = 12345;
    s1.grade = 90.50;


    printf("學生姓名：%s\n", s1.name);    // 學生姓名：John Doe
    printf("學生學號：%d\n", s1.id);      // 學生學號：12345
    printf("學生成績：%.2f\n", s1.grade); // 學生成績：90.50
}
```

## ***18. union***

在語法結構上，union與 struct 類似，都是使用者自定義的資料結構。但union 與 struct 差別最大的地方，就在於 union 結構中的各變數是共用記憶體位置。
並且在任何時候，只有一個變數的值是有效的，這取決於最後一次賦值的變數。

struct 稱為結構體，可以包含數個不同資料型態的變數，所有變數佔用不同的內存。
union 稱為聯合體，也可以包涵不同資料型態的變數，但是所有辨識站又相同內存。

* union範例 :

```c
#include <stdio.h>

struct St {
  int i;
  float f;
};

union Un {
  int i;
  float f;
};

int main () {
  struct St st;
  st.i = 10;
  st.f = 10.25;
  
  printf("%d %f\n", st.i, st.f);
  // 輸出: 10 10.250000
  
  // union 和 struct 的使用方式真的很像
  union Un un;
  un.i = 10;
  un.f = 10.25;
  
  printf("%d %f\n", un.i, un.f);
  // 輸出: 1092878336 10.250000 <= 錯誤!!
  
  return 0;
}
```

## ***19. enum***

enum 是一種常數定義方式，可以提升可讀性，enum 裡的識別字會以 int 的型態，從指定的值開始遞增排列 (預設為 0)

* enum範例 :

```c
enum color1 {red, green, blue, yellow}; 
// red = 0, green = 1...

enum color2 {red=10, green, blue=20, yellow}; 
//red = 10, green = 11, blue = 20, yellow = 21
```

## ***20. Interrupt 和 Polling 差異***

Interrupt 和 Polling 差異點就在中斷是具有即時性的,而輪詢則是定時檢查

中斷是一種事件驅動的機制，在I/O設備發生事件時，設備會向處理器發出中斷請求（Interrupt Request，IRQ），處理器暫停當前正在執行的任務，轉而去執行與中斷相關的處理程序，處理完畢後再返回原來的任務。

輪詢則是一種定期檢查的方式，處理器會定期向設備發出查詢，以檢查設備是否有事件。如果有事件發生，處理器將立即處理它，否則繼續執行其它任務。

```c

```

---

## ***1. 設定一個絕對位址為0x67a9的整數型變數的值為0xaa55***

```c
#include <stdio.h>

int main(void)
{
    int *ptr = (int *)0x67a9;
    printf("p1=%x\n", ptr); // p1=67a9
    ptr = (int *)0xaa55;
    printf("p2=%x\n", ptr); // p2=aa55
}
```

## ***2. Ｎ是否為判斷2的次方***

```c
bool isPowerof2(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

## ***3. 下列程式碼輸出什麼***

```c
#include <stdio.h>

int main(void)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = &(a + 1)[3];
    printf("%d\n", *p); // 5
    // 因為a+1指向a的第二個元素，[3]表示再向後移動3個元素
    // a+1是跳一個int的大小(a想成指標)
    // &a+1是跳一整個array的大小
}
```

## ***4. 連續呼叫 func 10 次，印出的值為何？***

```c
#include <stdio.h>

void func(void)
{
    static int i = 0 ;
    i++ ;
    printf("%d" , i ) ;
}

int main(void)
{
    func(); // 12345678910
}
```

## ***5. i++ & ++i***

```c
#include <stdio.h>

int main()
{
    int i = 5;
    int j = i++ // i++ : 表示先返回 i 的值，然後再將其加 1。
    printf("i1 = %d\n",i);  // 6
    printf("j1 = %d\n",j);  // 5

    i = 5;
    j = ++i; // ++i : 表示先將 i 的值加 1，然後再返回它。
    printf("i2 = %d\n",i);  // 6
    printf("j2 = %d\n",j);  // 6
    return 0;
}
```

## ***6. Setting a bit***

```c
int set_bit(int x, int n){
    return x | (1 << n);
}
```

## ***7. Clearing a bit***

```c
int clear_bit(int x, int n) {
    return x & ~(1 << n);
}
```

## ***8. Inverse a bit***

```c
int inverse_bit(int x, int n) {
    return x ^ (1 << n);
}
```

## ***9. Checking a bit***

```c
int clear_bit(int x, int n) {
    return (x >> n) & 1;
}
```

## ***10. 寫個function判斷基數偶數***

```c
if (num % 2 == 0) {
    printf("even\n");
} else {
    printf("odd\n");
}
```

## ***11. 寫個function計算有幾個位元是 1***

```c
int func(int x){
    int sum=0;
    while(x){
        x &= x-1;
        sum++;
    }
    return sum;
}
```

## ***12. What is the content of array a***

```c
int main() {
    int a[] = {6, 7, 8, 9, 10};
    int *p = a;
    *(p++) += 123;
    *(++p) += 123;
    for (int i = 0; i < 5; i++) {
        printf("a[%d] = %d\n", i, a[i]); // a = {129, 7, 131, 9, 10}
    }
}
```

## ***13. define vs typedef***

```c
#define dPS struct s *
typedef struct s * tPS;
以上兩種情況的意圖都是要定義dPS 和 tPS 作為一個指向結構s指標。哪種方法更好呢 ? (如果有的話)為什麼 ?

---

答案是︰typedef 更好。思考下面的例子︰
dPS p1, p2;
tPS p3, p4;
第一個擴展為
struct s * p1, p2;
上面的程式碼定義p1為一個指向結構的指標，p2為一個實際的結構，這也許不是你想要的，所以沒事不要亂用 macro。
```

## ***14. What is the output of the following program***

```c
int main() {
    unsigned int a = 6;
    int b = -20;
    (a + b > 6) ? puts(">6") : puts("<= 6");
}

// 當表達式中存在有符號類型和無符號類型（unsigned）
// 時所有的操作數都自動轉換為無符號類型。
// 因此-20變成了一個非常大的正整數，所以該表達式計算出的結果大于6。
```

## ***15. The faster way to an integer multiply by 7***

```c
int main() {
    int i = 1;
    i = (i << 2) + (i << 1) + (i << 0);
    printf("i = %d\n",i);
}
```

## ***16. declaration（宣告）和 definition（定義）的差異***

宣告是指告訴編譯器一個變數、函數、類型等識別符號的名稱和類型，
但不分配存儲空間，也不執行初始化。例如，以下是一個變數的宣告：

```c
int a;
```

定義是指為變數、函數、類型等識別符號分配存儲空間，
並且可能進行初始化。例如，以下是一個變數的定義：

```c
int a;
```

在C語言中，每個變數和函數只能有一個定義，但可以有多個宣告。

## ***17. Reverse a string***

```c
#include <stdio.h>
#include <string.h>

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    char str[] = "Hello, world!";
    printf("Original string: %s\n", str);
    reverse_string(str);
    printf("Reversed string: %s\n", str);
    return 0;
}
```

## ***18. point考題***

```c
1. 一個整型數（An integer）
2. 一個指向整型數的指標（A pointer to an integer）
3. 一個指向指標的的指標，它指向的指標是指向一個整型數（A pointer to a pointer to an integer）
4. 一個有10個整型數的陣列（An array of 10 integers）
5. 一個有10個指標的陣列，該指標是指向一個整型數的（An array of 10 pointers to integers）
6. 一個指向有10個整型數陣列的指標（A pointer to an array of 10 integers）
7. 一個指向函數的指標，該函數有一個整型參數並返回一個整型數（A pointer to a function that takes an integer as an argument and returns an integer）
8. 一個有10個指標的陣列，該指標指向一個函數，該函數有一個整型參數並返回一個整型數（ An array of ten pointers to functions that take an integer argument and return an integer）

1. int p
2. int *p
3. int **p
4. int p[10]
5. int *p[10]
6. int (*p)[10]
7. int (*p)(int)
8. int (*p[10])(int)
```

## ***19. 算出以下數值***

輸出 *(str+1)，也就是陣列 str 中第二個字串，即 "WelcomeToHere"。

輸出 str[3]+8，也就是陣列 str 中第四個字串的第九個字元開始的子字串，即 "Genius"。

輸出 *m，也就是指標 m 指向的字元，即 "HopeEverythingGood" 的第五個字元，即 "E"。

輸出 *(n+3)，也就是指標 n 指向的字串的第四個字元，即 "WelcomeToHere" 的第四個字元，即 "c"。

輸出 *p + 1，也就是指標 p 指向的子字串的第一個字元加一，即 "l" + 1，結果是 "m"。注意這裡加一的是字元的 ASCII 碼，而不是數值。

```c
#include <stdio.h>

int main(void) {
 char *str[] = {
     {"MediaTekOnlineTesting"},
     {"WelcomeToHere"},
     {"Hello"},
     {"EverydayGenius"},
     {"HopeEverythingGood"}
 };
 char* m = str[4] + 4;
 char* n = str[1];
 char* p = *(str+2) + 4;
 printf("1. %s\n", *(str+1));
 printf("2. %s\n", (str[3]+8));
 printf("3. %c\n", *m);
 printf("4. %c\n", *(n+3));
 printf("5. %c\n", *p + 1);
 // 1. WelcomeToHere
 // 2. Genius
 // 3. E
 // 4. c
 // 5. p
 return 0;
}
```

## ***20. 判斷Big-Endian or Little-Endian***

在現今主流的 CPU 中，最常見的位元組順序有兩種，分別是 Big-Endian 與 Little-Endian，Big-Endian 是指資料放進記憶體中的時候，最高位的位元組會放在最低的記憶體位址上，而 Little-Endian 則是剛好相反，它會把最高位的位元組放在最高的記憶體位址上。

![img](https://miro.medium.com/v2/resize:fit:720/format:webp/0*Tp4eqqbFuIsWnyXv.png)

![img](https://miro.medium.com/v2/resize:fit:720/format:webp/0*sSII9z24WkAGpm3k.png)

## ***21. 給一個int a[20]已排序的陣列，請寫一個function(a, size)能印出0~500的數字，且不包含a陣列內的元素***

```c
#include <stdio.h>

void function(int *a,int size)
{
 for(int i=0; i<=500; i++)
 {
    if(i == *a)
        a++;
    else
        printf("%d\n",i);
    }
}
```

## ***22. 分類0~500***

```c
void function(int *a, int size, int b)
{
    int *ptr = a;
    int i;

    while (*ptr < b * 100) {
        ptr++;
    }

    for (i = b*100; i<(b+1)*100; i++) {
        if (*ptr == i)
             ptr++;
        else
            printf("%d\n", i);
    }
}
```

## ***23. 印出下列圖形***

```c
    *
   **
  ***
 ****
*****

#include <stdio.h>

int main() {
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<5-i;j++){
            printf(" ");
        }
        for(j=0;j<i+1;j++){
            printf("*"); 
        }
        printf("\n"); 
    }
    return 0;
}
```

## ***24. a是多少***

```c
unsigned int a,b;

for(b = 2; b >= 0 ; b--)
{
   a++;
}
cout << a;

Ans : 這題因為b是unsigned int 所以永遠不會小於0，你就回答爆掉或a = inf就好
```

## ***25. 費式數列***

11,12,23,35,58,....n,寫一個函數,輸入值是位置的值"n",要找出相對應的值

```c
#include <stdio.h>

int main() 
{
    int n, temp, a = 11, b = 12;
    printf("n = ");
    scanf("%d", &n);

    if(n==0)
        return a;
    if(n==1)
        return b;
    
    for(int i = 2 ; i <= n ; ++i)
    {
        temp = b;
        b = a + b;
        a = temp;
    }
    printf("b : %d",b);
}
```

## ***26. quick sort***

```c
void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void QuickSort(int *array, int left, int right)
{
    if (left < right) {
        int i= left-1, j=right+1;
        int mid = info[(left+right)/2].signal_level;

        while (true) {
            while(info[++i].signal_level > mid);
            while(info[--j].signal_level < mid);

            if (i>=j)
                break;

            swap(info, i, j);
        }

        QuickSort(info, left, i-1);
        QuickSort(info, j+1, right);
    }
}
```

## ***27. binary serach***

```c
int binsearch(int* arr, int k, int n) {
  int left = 0, right = n;
  while (left <= right) {
    int mid = (left+right)/2;
    if (arr[mid] > k) {       // 往左半部找
      right = mid - 1;
    }
    else if (arr[mid] < k) {  // 往右半部找
      left = mid + 1;
    }
    else
      return mid;
  }
  return -1; // not found
}
```

## ***28. 給一個unsigned short, 問換算成16進制後四個值是否相同? 若是回傳1,否則回傳0***

```c
int isHexEqaul(unsigned short input) {     // input = 0xAAAA;
    unsigned short input;
    unsigned short hex[4]; // 0xFFFF ==> 0000 0000 0000 0000
    int is_eqaul;

    hex[0] = (input & 0xF000) >> 12;
    hex[1] = (input & 0x0F00) >> 8;
    hex[2] = (input & 0x00F0) >> 4;
    hex[3] = input & 0x000F;

    is_eqaul = ((hex[0] == hex[1]) && (hex[1] == hex[2]) && (hex[2] == hex[3]));
    return is_eqaul;
}
```

## ***29. 求一個數的最高位1在第幾位***

```c
int main()
{
    unsigned int a = 0x65; // 0110 0101
    unsigned int test_bit = 128; // 1000 0000
    int count = 7;  // sizeof(unsigned int)*8   == 該data type的bit數
    while (((a & test_bit) >> count) != 1) {
        count--;
        test_bit >>= 1;
    }
    printf("hightest bit is %d th bit\n", count);
    
    return 0;
}
```

## ***30. 最大公因數 遞迴寫法***

```c
int gcd(int x, int y) { // x > y
    if (y == 0)  /* 餘 0，除數 x 即為最大公因數 */
        return x;
    else
        return gcd(y, x % y);  /* 前一步驟的除數為被除數，餘數為除數 */
}
```

## ***31. (多選題)問哪邊會出現錯誤(以及錯在哪)，及要如何初始化?***

```c
union Var
{ 
    char ch;
    int num1;
    double num2;
}; 
int main()
{

    union Var var = {123}; 
    printf("var.ch = %c\n",var.ch); 
    printf("var.num1 = %d\n",var.num1); 
    printf("var.num2 = %.3f\n",var.num2); 
    
    return 0;
}

///answer

初始化時給予的數值類型不符合 union 成員的類型。

在此程式碼中，union 的成員包含 char、int 和 double 三種類型，因此在初始化時需要確保給予的值類型符合 union 成員的類型。在此程式碼中，給予的值是整數 123，這個值的類型為 int，因此可以正確初始化 union 中的 int 成員，但 char 和 double 成員則可能會出現未定義的行為。

讀取 union 成員時沒有確定該成員的值是否有效。

在此程式碼中，雖然已經對 union 進行了初始化，但是只給了其中一個成員變量 var.num1 一個值。因此，在讀取其他成員變量之前，必須先確定該成員變量的值是否有效，否則可能會出現未定義的行為。

要正確初始化此程式碼中的 union，可以按照以下方式進行：

初始化時給予的值需要與 union 成員的類型相符。

在此程式碼中，如果要同時初始化 char、int 和 double 成員變量，可以使用以下程式碼進行初始化：

```

## ***32. struct佔幾byte?***

```c
typedef struct MyStruct
{
    char a[2];
    int  b;
    double c;
};
//ans = 1+3(對齊int)+4+8=16byte

typedef struct MyStruct
{
    char a[2];
    int  b;
    double c;
    int *Pint;
    char d;
    char*Pchar;
};
//ans = 1+3(對齊int)+4+8+4+1+3+4(由於(4+1+3+4)不是8的倍數故需要補4)+4=32byte

typedef struct MyStruct
{
    char a;
    char b;
    struct str2
    {
        int d;
    } c;
};
//ans = 1+1+4+2(對齊int)=8byte

typedef struct MyStruct
{
    char a;
    int b;
    char c;
    char* d;
    double* e;
    struct str2
    {
        int f;
        char g;
        struct str3
        {
            char* p;
        }n;
    } m;
};
//ans = 1+3+4+1+3+4+4+4+1+3+4=32byte

typedef struct MyStruct
{
    char a;
    char b;
    struct str2
    {
        char c;
        char d;
    };
};
//ans = 1+1=2byte  *並沒有申明這個結構體的變數所以str2不用計算
```

## ***33. 0~500個數字每次隨機 取一個數字出來，但下次在抽出時不可以出現已經抽過的數字，問你如何時實現。***

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 500

int main() {
    int nums[MAX_NUM + 1]; // 儲存 0~500 的數字，初始化為 0
    for (int i = 0; i <= MAX_NUM; i++) {
        nums[i] = 0;
    }

    srand(time(NULL)); // 使用當前時間作為種子，產生亂數

    int count = 0; // 已經抽出的數字個數
    while (count < MAX_NUM) {
        int num = rand() % (MAX_NUM + 1); // 隨機產生一個數字
        if (nums[num] == 0) { // 如果這個數字還沒被抽過
            nums[num] = 1; // 標記為已經抽過
            count++; // 已經抽出的數字個數加 1
            printf("%d ", num); // 輸出這個數字
        }
    }

    return 0;
}

```

## ***34. #define MIN(A,B) A < B ? A:B; 這樣會有甚麼問題?***

```c
int result = 2 * MIN(6,10); // 2*6<10?6:10;
//result 會變成10，但我們要的是12
```

## ***35. Linked list 實作queue的 push, pop***

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定義鏈結串列節點結構
struct Node {
    int data;
    struct Node* next;
};

// 定義 Queue 結構
struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
};

// 創建一個新節點
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// 創建一個新的 Queue
struct Queue* newQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// 在 Queue 尾部插入一個節點
void push(struct Queue* queue, int data) {
    struct Node* node = newNode(data);
    if (queue->rear == NULL) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->size++;
}

// 從 Queue 頭部刪除一個節點
int pop(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    queue->size--;
    return data
}
```

## ***36. 解釋C語言中的 "#error"***

```c
在C語言中，預處理指令（preprocessor directives）以 '#' 字符開。

#error指令會讓預處理器產生一個錯誤消息，並停止編譯。它通常被用來在預處理時檢測錯誤或者不符合要求的條件，比如檢測程序是否被正確地編譯、是否使用了正確的編譯選項、是否定義了需要的marco等等。

//這是一個防止編譯器編譯這個文件時，如果沒有定義DEBUG這個macro，預處理器會產生一個錯誤消息
#ifndef DEBUG
#error "You must define the DEBUG macro"
#endif
```

## ***37. Explain lvalue and rvalue***

```c
lvalue：指的是可以出現在等號左邊 (assignment expression 的左邊) 的運算式，lvalue 可以被當成是一個物件 (object)，它具有某個記憶體位址，可以對它進行讀取或寫入的操作。例如，變數、陣列元素、指向變數或陣列元素的指標、結構體成員等都是 lvalue。

rvalue：指的是不能出現在等號左邊的運算式，也就是沒有記憶體位置 (address) 的運算式，只有值 (value) 的運算式。rvalue 可以是常數、運算式的結果、函數的回傳值等。在運算式中，rvalue 可以被當成一個數值、一個指標或一個結構體等值的表達式，但是無法對它進行寫入操作。

以下是一例子： int a = 5;  // a 是 lvalue，5 是 rvalue
```

## ***38. 寫一個“標準”巨集MIN ，這個巨集輸入兩個參數並返回較小的一個。***

```c
#include <stdio.h>

#define MIN(a,b) (a < b ? a : b)

int main()
{   
    printf("min=%d\n",MIN(10,5));
}
```

## ***39. Write a code to swap integer a, b, without temporary variable.***

```c
#include <stdio.h>

void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main() {
    int a = 5;
    int b = 10;
    printf("Before swapping: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swapping: a = %d, b = %d\n", a, b);
    return 0;
}
```

## ***40. bitwise 運算***

```c
#include <stdio.h>

int main() {
    long ans = 0;
    short a = 0x1234;
    short b = 0x5600;
    ans += a << 16;
    ans += b << 0;
    ans += (b >> 2) + 0x22;
    printf("a=%d\n",ans);   // 12346BA2
}
```

## ***41. 大小寫轉換***

```c
// 輸出大寫
#include <stdio.h>

int main() {
    char lowercase = 'a';
    char uppercase = lowercase - 32; 
    printf("%c\n", uppercase); 
    return 0;
}
// 輸出小寫
#include <stdio.h>

int main() {
    char uppercase = 'A';
    char lowercase = uppercase + 32; 
    printf("%c\n", lowercase); 
    return 0;
}
```

## ***42. Sizeof***

```c
64bit
sizeof(string)       = 8
sizeof(char)         = 1
sizeof(p)            = 8
sizeof(short)        = 2
sizeof(int)          = 4
sizeof(long)         = 8
sizeof(long long)    = 8
sizeof(size_t)       = 8
sizeof(double)       = 8
sizeof(long double)  = 16

32bit
sizeof(string)       = 4
sizeof(char)         = 1
sizeof(p)            = 4  //指標
sizeof(short)        = 2
sizeof(int)          = 4  //怕因環境影響程式,絕大多數64,32的編譯器是一樣大
sizeof(long)         = 4      
sizeof(long long)    = 8
sizeof(size_t)       = 4
sizeof(double)       = 8
sizeof(long double)  = 12    //看作long+double = 4 + 8 =12
```

## ***42. 多執行緒***

```c
為了提高 CPU 的使用率，將某些需要耗時較多的任務或是大量 I/O 操作 (I/O處理速度很慢)，採用多執行緒可以適當地提高程式的執行效率。

在介紹多執行緒之前，先來說明多執行緒的相關概念。

程式 (Program) : 指尚未被 Load 到記憶體的 Code
程序 (Process) : 指正在執行的程式，Operating System (OS) 會分配其所需要的資源，至少存在一個或多個執行緒，主要包含: Code, Data, Heap, Stack
Code (Text Section) 儲存程序執行的代碼
Data 可分為 global variable 跟 static variable
Heap 動態配置記憶體空間給變數或函式
Stack 儲存暫時性的資料 (local variable, function)
執行緒 (Thread) : 指 OS 分配 CPU 進行運算的基本單位，存在於 Process中。一旦CPU開始執行程式，就會至少有一個Thread運作
多執行緒 (Multithreading) : 指將一個程序中的任務分配給不同的執行緒，各個執行緒平行運作，不互相影響，並且在同一個程序的執行緒共享記憶體 (shared memory)
❗ 不同的程序間沒辦法共享記憶體，若有需要互相通訊，唯有依賴特別的設計才能擁有共享記憶體

使用多執行緒有什麼優點跟缺點呢~~

🔹 優點:

1. 提高 CPU 的使用效率

2. 當一個執行緒必須停下來等待與服務器連接或是需要佔據長時間處理的程序，可以放在後台處理，其他執行緒還是可以繼續運作，可以提高處理效能

🔹 缺點:

1. 若有大量的執行緒，就會影響其效能，因為 OS 需要在它們之間做切換 (Context Switch)

2. 更多的執行緒需要更多的記憶體空間

3. 因為資料是多個執行緒共享的，因此有可能會發生 Race Condition 的狀況

上下文切換 (Context Switch) : 指當 CPU 要從一個執行緒切換至另一個執行緒時，需要先儲存當前執行緒的狀態，再讀回將要執行的執行緒狀態。在切換的過程中，需要花費一些時間
Context Switch 的發生時機 : 因為一顆 CPU 同時只能處理一項程序，OS 就會利用時間輪轉的方式，讓使用者感覺這些程序都是同時運作。當CPU 認為某執行緒執行夠久的時候，就會發出一個中斷 (Interrupt) 訊號，切換至另一個執行緒去運作
競爭危害 (Race Condition) : 指當一個 Thread 修改動作執行到一半時被切換，而另一個 Thread 也正好執行修改同一個地方時，可能會導致記憶體洩漏 (memory leak)
Race Condition 的發生時機 : 因為程序有時間排程的問題 (發生 Context Switch)，在多個執行緒的情況下，當兩個 Thread 同時修改一個資料時，可能造成變數的值錯誤，形成不可預期的結果，便造成了 Race Condition， 解決 Race Condition 的方法就是使用 Critical Section
臨界區段 (Critical Section) : 指存取共享資源的程式碼區域，而這些共享資源不能被多個執行緒存取，也就是指這些要受保護的程式區段稱為 Critical Section。
❗ 當執行緒進入臨界區段時，必須使用一些同步機制在臨界區段的進入點與離開點實現，以確保這些執行緒的安全。
```
