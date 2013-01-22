// DDUTgen.c by Billy Chia
// Dec 24, 2012
// A script to generate all unit tests for a doomsday function
// part of UNSW Computing 1 on openlearning.com
// 7 posible doomsdays (Monday - Sunday) 
// leapYear && non-leapYear 
// 365 or 366 days in year
// 7 * 2 * 365 + 7 = 5117 asserts
// Thanks to David Klick for the idea
// Yes, I know this isn't really a pramatic idea
// I just thought it'd be a good challange for a new C coder
// On a Unix-based system run "./DDUTgen > doomsdayUntiTests.h" 
// Freely licensed under Creative Commons CC-BY-3.0

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define THURSDAY  0
#define FRIDAY    1
#define SATURDAY  2
#define SUNDAY    3
#define MONDAY    4
#define TUESDAY   5
#define WEDNESDAY 6

typedef char * string;

int getDaysInMonth (int leapYear, int month);
int getDayOfWeek (int leapYear, int doomsday,
                  int month, int day, int dayOfWeek);
void printAssert (int leapYear, int doomsday,
                  int month, int day, int dayOfWeek);


int main (int argc, char *argv[]) {

    int leapYear;
    int doomsday;
    int month;
    int daysInMonth;
    int day;
    int dayOfWeek;

    //get leap and non-leap years
    for (leapYear = 0; leapYear < 2; leapYear++) {
        // get doomsdays for each day of the week
        for (doomsday = 0; doomsday < 7; doomsday++) { 
            // for every month
            for (month = 1; month <= 12; month++) {
                daysInMonth = getDaysInMonth (leapYear, month);
                // for each day of the month print an assert
                for (day = 1; day <= daysInMonth; day++) {
                    dayOfWeek = getDayOfWeek (leapYear, doomsday,
                                             month, day, dayOfWeek);
                    printAssert(leapYear, doomsday,
                                month, day, dayOfWeek);
                }
            }
        }
    }

    return EXIT_SUCCESS;
}

int getDaysInMonth (int leapYear, int month) {

    int days[] = { 31, 28, 31, 30, 31, 30, 
                   31, 31, 30, 31, 30, 31 };

    int daysInMonth = days[month - 1];

    if (leapYear && month == 2) {
        daysInMonth++;
    }

    return daysInMonth;
}

int getDayOfWeek (int leapYear, int doomsday,
             int month, int day, int dayOfWeek) {

    if (month == 1 && day == 1 && leapYear) {
        dayOfWeek = (doomsday + 4) % 7;
    } else if (month == 1 && day == 1 && !leapYear) {
        dayOfWeek = (doomsday + 5) % 7;
    } else {
        dayOfWeek = (dayOfWeek + 1) % 7;
    }

    return dayOfWeek;
}

void printAssert (int leapYear, int doomsday,
            int month, int day, int dayOfWeek) {

    string days[7] = { "THURSDAY",
                       "FRIDAY",
                       "SATURDAY",
                       "SUNDAY",
                       "MONDAY",
                       "TUESDAY",
                       "WEDNESDAY" };

    string boolean[2] = { "FALSE", "TRUE" };

    printf("assert (dayOfWeek (%s, %s, %2d, %2d) == %s);\n",
                    days[doomsday], boolean[leapYear], month,
                    day, days[dayOfWeek]);

    return;
}
