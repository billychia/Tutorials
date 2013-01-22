/*
 *  rot13.c
 *  by Billy Chia, Dec 31, 2012
 *
 *  based on encode.c
 *  lecture-code to encode a character using a +1 Caesar cipher shift
 *
 *  Original author: Richard Buckland on 16/03/11, 20/11/12.
 *  Licensed under Creative Commons SA-BY-NC 3.0.
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#define FIRST_LC_LETTER 'a'
#define LAST_LC_LETTER  'z'
#define FIRST_UC_LETTER 'A'
#define LAST_UC_LETTER  'Z'
 
void testEncode (void);
int isLowerCase (char letter);
int isUpperCase (char letter);
char encode (char plainText);
 
int main (int argc, char *argv[]) {
 
   testEncode ();
 
   char plainChar;
   char encodedChar;
 
   printf ("Enter the letter to be encoded: ");
   scanf ("%c", &plainChar);
 
   encodedChar = encode (plainChar);

   printf ("Encoded is: %c\n", encodedChar);
 
   return EXIT_SUCCESS;
}
 
int isLowerCase (char letter) {
   return (letter >= FIRST_LC_LETTER) && (letter <= LAST_LC_LETTER);
}
 
int isUpperCase (char letter) {
   return (letter >= FIRST_UC_LETTER) && (letter <= LAST_UC_LETTER);
}

void testEncode (void) {
   assert (encode ('a') == 'n');
   assert (encode ('z') == 'm');
   assert (encode ('A') == 'N');
   assert (encode ('Z') == 'M');
   assert (encode ('7') == '7');
   assert (encode (32) == 32);
   assert (encode (65) == 78);
 
   printf ("All tests passed. You are Awsome!\n");
}
 
char encode (char plainText) {
   char cipherText;

   if (isLowerCase (plainText)) {
      cipherText = (((plainText - 97) + 13) % 26) + 97;
   } else if (isUpperCase (plainText)) {
      cipherText = (((plainText - 65) + 13) % 26) + 65;
   } else {
      cipherText = plainText;
   }
 
   return cipherText;
}
