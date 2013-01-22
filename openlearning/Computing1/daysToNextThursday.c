/* given a date after START_GREGORIAN_CALENDAR this function returns
 * the number of days until the next thursday.
 * eg for 16 March 2011 (2011,3,16) the function will return 1
 * eg for 17 March 2011 (2011,3,17) the function will return 7
 *
 */

int daysToNextThursday (int year, int month, int day) {
    //yearToDoomsDay() returns doomsday of given year
    int doomsday = yearToDoomsDay(year);
    //isLeapYear() returns 1 | 0 if year is leap or not
    int leapYear = isLeapYear(year);
    //weekDay is day of the week for given date
    int weekDay = dayOfWeek(doomsday, leapyear, month, day);

    int daysToThursday = //some simple calculation

    return daysToThursday;
}
