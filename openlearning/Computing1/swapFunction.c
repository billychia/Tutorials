// Billy Chia
// Dec 27, 2012
// swapFunction.c
// Computing 1 UNSW - openlearning.com
// Write a function which
// 1. Takes in pointers two integers
// 2. Swaps the values


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap (int *first, int *second);

int main (int argc, char * argv[]) {
    int a = 1;
    int b = 2;

    //printf("a: %d\n", a);
    //printf("b: %d\n", b);
    
    swap(&a, &b);

    //printf("a: %d\n", a);
    //printf("b: %d\n", b);

    return 0;
}


void swap (int *first, int *second) {

    int temp = *first;
    *first = *second;
    *second = temp;

    return;
}

