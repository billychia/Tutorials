//  makeAsserts.c
//  by Dave Klick
//  December 24, 2012
//
//  This program creates a list of all valid possible
//  assertions to be used for testing the doomsday
//  programming assignment.
 
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
 
int main (int argc, char* argv[]) {
    char* dow[] = { "SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY",
        "THURSDAY", "FRIDAY", "SATURDAY" };
    char* extraSpace[] = { "   ", "   ", "  ", "", " ", "   ", " " };
    char* booleanText[] = { "FALSE", "TRUE" };
    char* booleanExtraText[] = { "", " " };
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int years[] = { 2000, 2001, 2002, 2003, 2004, 2005,
        2006, 2008, 2009, 2010, 2012, 2016, 2020, 2024 };
    int isLeapYear[] = { 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1 };
    int dd[] = { 2, 3, 4, 5, 0, 1, 2, 5, 6, 0, 3, 1, 6, 4 };
    int jan1[] = { 6, 1, 2, 3, 4, 6, 0, 2, 4, 5, 0, 5, 3, 1 };
 
    int dayOfWeek;
    int leapYear;
    int month;
    int day;
    int maxDay;
    int year;
 
    for (year=0; year<14; year++) {
        printf("        // asserts for year %4d\n", years[year]);
        dayOfWeek = jan1[year];
        leapYear = isLeapYear[year];
        if (leapYear == 1) {
            daysInMonth[1] = 29;
        } else {
            daysInMonth[1] = 28;
        }
        for (month=1; month<=12; month++) {
            maxDay = daysInMonth[month-1];
            for (day=1; day<=maxDay; day++) {
                printf("        assert (dayOfWeek (%s,%s %s,%s %2d, %2d) == %s);\n",
                    dow[dd[year]], extraSpace[dd[year]],
                    booleanText[leapYear], booleanExtraText[leapYear],
                    month, day, dow[dayOfWeek]);
                dayOfWeek++;
                if (dayOfWeek == 7) {
                    dayOfWeek = 0;
                }
            }
        }
    }
    return EXIT_SUCCESS;
}
