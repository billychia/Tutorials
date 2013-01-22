// Billy Chia
// Dec 23, 2012
// Test function to test define statments

#include <stdio.h>
 
int main (int argc, char *argv[]) {

   char array[100];
   int i;

   printf("the address of array is %p\n", array);
   for (i=0; i < 30; i++) {
      printf("%x\n", array[i]);
   }

   return 0;
}



