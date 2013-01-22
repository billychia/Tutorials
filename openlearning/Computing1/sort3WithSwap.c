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

void sortNums(int *first, int *second, int *third);
void swap (int *first, int *second);
int getFirst(void);
int getSecond(void);
int getThird(void);

int main (int argc, char *argv[]) {

    int first = getFirst();
    int second = getSecond();
    int third = getThird();    

    sortNums(&first, &second, &third);

    printf("%d\n%d\n%d\n", first, second, third);

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

void sortNums(int *first, int *second, int *third) {

    if (*first > *second) {
        swap(&*first, &*second);
    }
    if (*second > *third) {
        swap(&*second, &*third);
    }
    if (*third < *first) {
        swap(&*first, &*third);
    }
    if (*first > *second) {
        swap(&*first, &*second);
    }
 
    return;
}

void swap (int *first, int *second) {

    int temp = *first;
    *first = *second;
    *second = temp;

    return;
}
