#include <stdio.h>

int func(unsigned short X){
   unsigned short n[4];
   n[0] = ((X & 0xF000) >> 12);
   n[1] = ((X & 0x0F00) >> 8);
   n[2] = ((X & 0x00F0) >> 4);
   n[3] = (X & 0x000F);
   if((n[0] ^ n[1] ^ n[2] ^ n[3]) == 0)
      return 1;
   else
      return 0;
}

int main() {
   unsigned short num = 0xBBBB;
   printf("ans:%d\n",func(num));
   return 0;
}