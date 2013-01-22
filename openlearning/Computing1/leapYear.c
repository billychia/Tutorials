// Billy Chia
// unsw computing 1
// program to compute if a user supplied year is a leap year or not
// demostrate simple C syntax
// if then else % functions
// Test Cases:
// 4000 - yes
// 4004 - yes
// 2000 - yes
// 1999 - no
// 1791 - no
// 1802 - no
// 1492 - crash

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define START_OF_GREG_CALENDAR 1582

// function to test year for leap year conditions
int isLeapYear (int year) {
    int yesForLeapYear;
    if ((year % 400) == 0) {
        yesForLeapYear = 1;
    } else {
        if ((year % 4) == 0) {
            if (year % 100 == 0) {
                yesForLeapYear = 0;
            } else {
                yesForLeapYear = 1;
            }
        } else {
            yesForLeapYear = 0;
        }
    }
    return yesForLeapYear;
}

int main (int argc, const char * argv[]) {
    int year;

    printf ("please enter the year you are interested in\n");

    scanf ("%d", &year);

    // notice this only works if the year is >= 1582
    // beacuse of the gregorian calendar stuff

    assert (year >= START_OF_GREG_CALENDAR);

    // print if year is leap year or not
    if (isLeapYear(year) == 1) {
        printf ("%d is a leap year!\n", year);
    } else if (isLeapYear(year) == 0){
        printf ("%d is not a leap year!\n", year);
    } else {
        printf ("something went wrong!");
    }

    return EXIT_SUCCESS;
}

