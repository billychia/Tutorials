// Billy Chia
// Dec 18, 2012
// Computing 1 UNSW OpenLearning
// Sort 3 Numbers
// Write a program to read in 3 whole numbers
// and print them out in acending order, one per line
// eg given input of "8 5 9"
// print out: 5\n8\n9\n

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void sortNums(int first, int second, int third);
int getFirst(void);
int getSecond(void);
int getThird(void);

int main (int argc, char *argv[]) {

    int first = getFirst();
    int second = getSecond();
    int third = getThird();    

    sortNums(first, second, third);

    return EXIT_SUCCESS;
}

int getFirst(void) {
    int first; 
    scanf("%d",&first);
    return first;
}

int getSecond(void) {
    int second;
    scanf("%d",&second);
    return second;
}

int getThird(void) {
    int third;
    scanf("%d",&third);
    return third;
}

void sortNums(int first, int second, int third) {

    int smallest = 0;
    int median = 0;
    int largest = 0;

    if (first < second && second < third) {
        smallest = first;
        median = second;
        largest = third;
    } else if (first < third && third < second) {
        smallest = first;
        median = third; 
        largest = second;
    } else if (second < first && first < third) {
        smallest = second;
        median = first; 
        largest = third;
    } else if (second < third && third < first) {
        smallest = second;
        median = third; 
        largest = first;
    } else if (first < second) {
        smallest = third;
        median = first; 
        largest = second;
    } else {
        smallest = third;
        median = second; 
        largest = first;
    }

    printf("%d\n%d\n%d\n", smallest, median, largest);

    return;
}

