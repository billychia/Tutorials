// Billy Chia
// Dec 27, 2012
// Prints the Danish Flag
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#define WIDTH 12
#define HEIGHT 5
 
void testDanish (void);
void showDanish (void);
void showPixel (int col, int row);
 
 
int main (int argc, char *argv[]) {
 
   //testDanish();
 
   showDanish();
 
   return EXIT_SUCCESS;
}
 
void testDanish (void) {
   printf ("Output should look like \n");
   printf ("** *********\n");
   printf ("** *********\n");
   printf ("            \n");
   printf ("** *********\n");
   printf ("** *********\n");
   printf ("End of test\n\n\n");
}
 
void showDanish (void) {
   int col = 0;
   int row = 0;
 
   while (row < HEIGHT) {
      col = 0;
      while (col < WIDTH) {
         showPixel(col, row);
         col++;
      }
      printf("\n");
      row++;
   }
}
 
void showPixel (int col, int row){
 
   char pixel;
 
   if (col == 3 || row == 2) {
      pixel = ' ';
   } else {
      pixel = '*';
   }
   printf ("%c", pixel);
}
