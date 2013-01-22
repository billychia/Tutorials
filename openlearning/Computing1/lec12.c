/* Billy Chia
 * Tuesday, Dec 18, 2012
 * Openlearning UNSW Computing 1
 * Lecture 12 - Functions Part 1
 * This is a play script to test things I learned
 *
 * to compile: gcc -O -Wall -Werror -o lec12 lec12.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define CONSTANT 0

//declare functions up here
void lec10 (void);
void printNum(int num);

int main(int argc, char * argv[]) {

    printf("CONSTANT is :%d\n",CONSTANT);

    lec10();
    printNum(73);
    printNum(88);
    printNum(172);

    return EXIT_SUCCESS;
}

//define functions down here

//Function to print sizes from lecture 10 notes
//need to use ld because sizeof() returns number of bytes
void lec10 (void) {
    printf("INT:\t\t\%ld\n", sizeof(int));
    printf("LONG:\t\t%ld\n", sizeof(long));
    printf("LONG LONG:\t%ld\n", sizeof(long long));
    printf("SHORT:\t\t%ld\n", sizeof(short));
    printf("FLOAT:\t\t%ld\n", sizeof(float));
    printf("DOUBLE:\t\t%ld\n", sizeof(double));
    printf("CHAR:\t\t%ld\n", sizeof(char));
    return;
}

//function to print numbers in decimal and hex
void printNum(int num){
    printf("%d in decimal is %x in hex\n", num, num);
    return;
}
