/*
 *  doomsday.c
 *  A program to test a function dayOfWeek which determines which
 *  day of the week a particular date falls on.
 *  (only for dates after the start of the Gregorian calendar).
 *
 *  Program stub created by Richard Buckland on 27/03/12
 *  This program by Billy Chia on Dec 22, 2012
 *  Freely licensed under Creative Commons CC-BY-3.0
 *
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#define THURSDAY 0
#define FRIDAY   1
#define SATURDAY 2
#define SUNDAY   3
#define MONDAY   4
#define TUESDAY  5
#define WEDNESDAY 6
 
#define TRUE 1
#define FALSE 0
#define DAYS_PER_WEEK 7
 
int dayOfWeek (int doomsday, int leapYear, int month, int day);
int getDaysFromDD (int doomsday, int leapYear, int month, int day);
void runTests(void);
 
int main (int argc, char *argv[]) {

    runTests();

    return EXIT_SUCCESS;
}
 
 
// given the doomsday for a year, and whether or not it is a
// leap year, this function return the day of the week for any
// given month and day in the year.
 
int dayOfWeek (int doomsday, int leapYear, int month, int day) {
    int daysFromDD;
    int dayOfWeek;

    daysFromDD = getDaysFromDD(doomsday, leapYear, month, day);

    dayOfWeek = (doomsday + daysFromDD) % DAYS_PER_WEEK;

    //fix for non-pythonic modulus
    if (dayOfWeek < 0) {
        dayOfWeek += DAYS_PER_WEEK;
    } 
 
    return (dayOfWeek);
}

int getDaysFromDD (int doomsday, int leapYear, int month, int day) {
    int doomsDayOfMonth;
    int daysFromDD;

    if (month == 1 && leapYear == TRUE) {
        doomsDayOfMonth = 4; 
    } else if (month == 1 && leapYear == FALSE) {
        doomsDayOfMonth = 3;
    } else if (month == 2 && leapYear == TRUE) {
        doomsDayOfMonth = 1;
    } else if (month == 2 && leapYear == FALSE) {
        doomsDayOfMonth = 7;
    } else if (month == 3) {
        doomsDayOfMonth = 0;
    } else if (month == 5) {
        doomsDayOfMonth = 9;
    } else if (month == 7) {
        doomsDayOfMonth = 11;
    } else if (month == 9) {
        doomsDayOfMonth = 5;
    } else if (month == 11) {
        doomsDayOfMonth = 7;
    } else {
        doomsDayOfMonth = month;
    }

    daysFromDD = day - doomsDayOfMonth;

    return (daysFromDD);
}

void runTests(void) {
    //tests given with stub code
    assert (dayOfWeek (THURSDAY,  FALSE,  4,  4) == THURSDAY);
    assert (dayOfWeek (FRIDAY,    FALSE,  6,  6) == FRIDAY);
    assert (dayOfWeek (MONDAY,    FALSE,  8,  8) == MONDAY);
    assert (dayOfWeek (WEDNESDAY, FALSE, 10, 10) == WEDNESDAY);
    assert (dayOfWeek (FRIDAY,    FALSE, 12, 12) == FRIDAY);
    assert (dayOfWeek (THURSDAY,  FALSE,  9,  5) == THURSDAY);
    assert (dayOfWeek (FRIDAY,    FALSE,  5,  9) == FRIDAY);
    assert (dayOfWeek (SUNDAY,    FALSE,  7, 11) == SUNDAY);
    assert (dayOfWeek (TUESDAY,   FALSE, 11,  7) == TUESDAY);
    assert (dayOfWeek (WEDNESDAY, FALSE,  3,  7) == WEDNESDAY);

    assert (dayOfWeek (THURSDAY,  FALSE,  4,  5) == FRIDAY);
    assert (dayOfWeek (SATURDAY,  FALSE,  6,  5) == FRIDAY);
    assert (dayOfWeek (MONDAY,    FALSE,  8,  9) == TUESDAY);
    assert (dayOfWeek (WEDNESDAY, FALSE, 10,  9) == TUESDAY);
    assert (dayOfWeek (FRIDAY,    FALSE, 12, 20) == SATURDAY);
    assert (dayOfWeek (THURSDAY,  FALSE,  9,  9) == MONDAY);
    assert (dayOfWeek (FRIDAY,    FALSE,  5,  5) == MONDAY);
    assert (dayOfWeek (SUNDAY,    FALSE,  7,  7) == WEDNESDAY);
    assert (dayOfWeek (TUESDAY,   FALSE, 11, 11) == SATURDAY);
    assert (dayOfWeek (THURSDAY,  FALSE,  3, 30) == SATURDAY);

    assert (dayOfWeek (TUESDAY,   FALSE,  2,  28) == TUESDAY);
    assert (dayOfWeek (TUESDAY,   FALSE,  2,  27) == MONDAY);
    assert (dayOfWeek (THURSDAY,  FALSE,  1,  3)  == THURSDAY);

    //Tests with leapYear == TRUE
    assert (dayOfWeek (TUESDAY,   TRUE,  2,  29) == TUESDAY);
    assert (dayOfWeek (TUESDAY,   TRUE,  2,  28) == MONDAY);
    assert (dayOfWeek (THURSDAY,  TRUE,  4,  4) == THURSDAY);
    assert (dayOfWeek (FRIDAY,    TRUE,  6,  6) == FRIDAY);
    assert (dayOfWeek (MONDAY,    TRUE,  8,  8) == MONDAY);
    assert (dayOfWeek (WEDNESDAY, TRUE, 10, 10) == WEDNESDAY);
    assert (dayOfWeek (FRIDAY,    TRUE, 12, 12) == FRIDAY);
    assert (dayOfWeek (THURSDAY,  TRUE,  9,  5) == THURSDAY);
    assert (dayOfWeek (FRIDAY,    TRUE,  5,  9) == FRIDAY);
    assert (dayOfWeek (SUNDAY,    TRUE,  7, 11) == SUNDAY);
    assert (dayOfWeek (TUESDAY,   TRUE, 11,  7) == TUESDAY);
    assert (dayOfWeek (WEDNESDAY, TRUE,  3,  7) == WEDNESDAY);

    //Test for Jan leap and non-leap doomsdays
    assert (dayOfWeek (SUNDAY,  FALSE,  1,  3)  == SUNDAY);
    assert (dayOfWeek (SUNDAY,  FALSE,  1,  10)  == SUNDAY);
    assert (dayOfWeek (SUNDAY,  FALSE,  1,  17)  == SUNDAY);
    assert (dayOfWeek (SUNDAY,  FALSE,  1,  24)  == SUNDAY);
    assert (dayOfWeek (SUNDAY,  FALSE,  1,  31)  == SUNDAY);
    assert (dayOfWeek (SUNDAY,  TRUE,  1,  4)  == SUNDAY);
    assert (dayOfWeek (SUNDAY,  TRUE,  1,  11)  == SUNDAY);
    assert (dayOfWeek (SUNDAY,  TRUE,  1,  18)  == SUNDAY);
    assert (dayOfWeek (SUNDAY,  TRUE,  1,  25)  == SUNDAY);

    //my birthday
    assert (dayOfWeek (WEDNESDAY, TRUE, 1, 8) == SUNDAY);

    //Test WENDESDAY(6) doomsday with large number non-dooms days
    assert (dayOfWeek (WEDNESDAY, TRUE, 1, 30) == MONDAY);
    assert (dayOfWeek (WEDNESDAY, TRUE, 2, 25) == SATURDAY);
    assert (dayOfWeek (WEDNESDAY, TRUE, 3, 30) == FRIDAY);
    assert (dayOfWeek (WEDNESDAY, TRUE, 4, 29) == SUNDAY);
    assert (dayOfWeek (WEDNESDAY, TRUE, 5, 31) == THURSDAY);
    assert (dayOfWeek (WEDNESDAY, TRUE, 6, 30) == SATURDAY);
    assert (dayOfWeek (WEDNESDAY, TRUE, 7, 31) == TUESDAY);
    assert (dayOfWeek (WEDNESDAY, TRUE, 8, 31) == FRIDAY);
    assert (dayOfWeek (WEDNESDAY, TRUE, 9, 30) == SUNDAY);
    assert (dayOfWeek (WEDNESDAY, TRUE, 10, 30) == TUESDAY);
    assert (dayOfWeek (WEDNESDAY, TRUE, 11, 30) == FRIDAY);
    assert (dayOfWeek (WEDNESDAY, TRUE, 12, 31) == MONDAY);

    //Test for negative days (days in month before 1st doomsday)
    assert (dayOfWeek (WEDNESDAY, TRUE, 1, 2) == MONDAY);
    assert (dayOfWeek (THURSDAY, FALSE, 2, 1) == FRIDAY);
    assert (dayOfWeek (FRIDAY, FALSE, 3, 4) == TUESDAY);
    assert (dayOfWeek (SATURDAY, FALSE, 4, 1) == WEDNESDAY);
    assert (dayOfWeek (MONDAY, TRUE, 5, 1) == SUNDAY);
    assert (dayOfWeek (TUESDAY, FALSE, 6, 1) == THURSDAY);
    assert (dayOfWeek (WEDNESDAY, FALSE, 7, 1) == SUNDAY);
    assert (dayOfWeek (THURSDAY, FALSE, 8, 1) == THURSDAY);
    assert (dayOfWeek (SATURDAY, TRUE, 9, 1) == TUESDAY);
    assert (dayOfWeek (SUNDAY, FALSE, 10, 1) == FRIDAY);
    assert (dayOfWeek (MONDAY, FALSE, 11, 1) == TUESDAY);
    assert (dayOfWeek (TUESDAY, FALSE, 12, 1) == FRIDAY);

//from site:
    assert (dayOfWeek (WEDNESDAY, TRUE,  2,  26) == SUNDAY);
    assert (dayOfWeek (WEDNESDAY, TRUE,  3,  14) == WEDNESDAY);
    assert (dayOfWeek (MONDAY, TRUE,  1,  1) == FRIDAY);
 
//By Ahmad Harb (I will try to add some more later)
    //My birthday, very innovative I know !!!
    assert (dayOfWeek (TUESDAY, FALSE,  4,  3) == MONDAY); 
 
//By Robert Backhaus: This should be controversial!
     // And.. Discuss!!!
    assert (dayOfWeek (SUNDAY, FALSE, 2, 29) == MONDAY);
 
// By Steve Epstein
    assert (dayOfWeek (THURSDAY, TRUE, 12, 1) == SUNDAY);

    //extra tests
    //#include "./DDUnitTests.h"
    #include "./doomsdayUnitTests.h"

    printf ("all tests passed - You are awesome!\n");

    return;
}
