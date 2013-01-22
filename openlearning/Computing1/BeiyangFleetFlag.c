// Billy Chia
// Dec 28, 2012
// Computing 1 UNSW - openlearning.com
// BeiyangFleetFlag.c
// Code to produce Beiyang Fleet flag
// Using only ascii and while loops

#include <stdio.h>
#include <stdlib.h>
#include "pixelTests.h"

#define WIDTH 168
#define HEIGHT 112

void setPixel(char *pixel, int col, int row);

int main (int argc, char * argv[]) {

    char pixel;
    int col = 0;
    int row = 0;

    while (col < WIDTH && row < HEIGHT) { 
        setPixel(&pixel, col, row);
        printf("%c", pixel);
        col++;
        if (col >= WIDTH) {
            col = 0;
            row++;
            printf("\n");
        }
    }

    return 0;
}

void setPixel(char *p, int col, int row) {
    if (is64(col, row)) {
        *p = 64;
    } else if (is35(col, row)) {
        *p = 35;
    } else if (is39(col, row)) {
        *p = 39;
    } else if (is32(col, row)) {
        *p = 32;
    } else if (is96(col, row)) {
        *p = 96;
    } else if (is43(col, row)) {
        *p = 43;
    } else if (is46(col, row)) {
        *p = 46;
    } else if (is59(col, row)) {
        *p = 59;
    } else if (is58(col, row)) {
        *p = 58;
    } else {
        *p = ',';
    }
}
