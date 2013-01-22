//
//  exploreMemory.c
//  memory
//
//  Created by Richard Buckland on 20/11/12.
//
 
#include <stdio.h>
#include <stdlib.h>
 
long add (int x, int y);
 
int main(int argc, const char * argv[]) {
 
   int x;
   int y;
   long total;
 
   x = 40;
   y = 2;
 
   total = add (x, y);
 
   //printf("the sum of %d and %d is %ld\n", x, y, total);
 
   char c = -129;
   printf("Overflow of char is \t\t\t%d\n", c);
 
   unsigned long ul       = 9223372036854775807;
   printf("Overflow of unsigned long is \t\t\t%ld\n", ul);
   unsigned int ui        = 1;
   //printf("Overflow of unsigned int is \t\t%ld\n", ui);
   unsigned long long ull = 2;
   //printf("Overflow of unsigned long long is \t%ld\n", ull);
   unsigned short us      = 3;
   //printf("Overflow of unsigned short is \t%ld\n", us);
 
   signed long sl       = 4;
   //printf("Overflow of signed long is \t\t%ld\n", sl);
   signed int si        = 5;
   //printf("Overflow of signed int is \t\t%ld\n", si);
   signed long long sll = 6;
   //printf("Overflow of signed long long is \t%ld\n", sll);
   signed short ss      = 7;
   //printf("Overflow of signed short is \t\t%ld\n", ss);
 
   long l       = 8;
   //printf("Overflow of long is \t\t\t%ld\n", l);
   int i        = 9;
   //printf("Overflow of int is \t\t\t%ld\n", i);
   long long ll = 10;
   //printf("Overflow of long long is \t\t\t%ld\n", ll);
   short s      = 11;
   //printf("Overflow of short is \t\t\t%ld\n", s);
 
   float f = 999999999999999999;
   //printf("Overflow of float is \t\t\t%f\n", f);
   double d = 999999999999999999;
   //printf("Overflow of double is \t\t\t%f\n", d);
 
   // add them all together just to make use of them so the compiler
   // doesn't grumble that they are unused in the program
 
   double grandTotal;
   grandTotal =  c +
                 ul + ui + ull + us +
                 sl + si + sll + ss +
                  l +  i +  ll +  s +
                  f + d;
 
   //printf ("all these things added together make %f\n", grandTotal);
 
   return EXIT_SUCCESS;
}
 
long add (int x, int y) {
   long answer;
   answer = x + y;
 
   return answer;
}
