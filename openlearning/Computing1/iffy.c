// program demonstrating the use if
// statements in c
// unsw computing 1 week 2
// www.openlearning.com/courses/computing1
 
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    //int first;
    //int second;
    
    //first = 6;
    //second = 9;
    int x;
    int y;

    for (x = 0; x < 20; x++){
        for (y = 0; y < 20; y++) {
            possibles(x, y);
            printf("*** new value ***\n");
        }
    }
    
    
    return EXIT_SUCCESS;
}

int possibles (first, second) {
    
    if (first > 7) {
        printf ("Danish\n");
        if (second < 3) {
            printf ("happy");
        }
    } else {
        if (second > 8) {
            printf ("Dan");
        } else if (second > 4) {
            printf ("Sally");
        } else {
            // print nothing
        }
    }
    
    if (second < 10) {
        printf ("ish\n");
    }
    
    if (first > second) {
        printf ("\nFlag\n");
    } else {
        printf ("Flag\n");
    }
}

