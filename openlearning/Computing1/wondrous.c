// wondrous.c
// by Billy Chia Dec 31, 2012
// create function wondrous()
// take in an int > 0 
// output wondrous sequence
// if the current term is even: 
//    the next term is half the current term.
// if the current term is odd:
//    the next term is three times the current term, plus 1
// space separate terms and print \n after last number
// return a count of the numbers printed 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int wondrous (int start);

int main (int argc, char *argv[]) {

   int start;

   //assert(wondrous (3) == 8);
   printf("Enter num: ");
   scanf("%d", &start);
   printf("%d\n", wondrous (start));

   return EXIT_SUCCESS; 
}

int wondrous (int start) {

   int count = 1;

   while (start != 1) {
      printf("%d ", start);
      if (start % 2 == 0) {
         start /= 2;
      } else {
         start *= 3;
         start += 1; 
      } 
      count++;
   }
   printf("%d\n", start);
   
   return count;
}
