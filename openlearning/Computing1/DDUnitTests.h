   assert (dayOfWeek (THURSDAY, FALSE,   5, 27) == MONDAY);
   assert (dayOfWeek (SATURDAY,  TRUE,   1, 17) == FRIDAY);
   assert (dayOfWeek (MONDAY,    TRUE,   2, 11) == THURSDAY);
   assert (dayOfWeek (SUNDAY,    FALSE,  2, 11) == THURSDAY);
 
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
 
   assert (dayOfWeek (TUESDAY,   FALSE,  2, 28) == TUESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE,  2, 27) == MONDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  1,  3) == THURSDAY);
 
// Additional tests
   assert (dayOfWeek (WEDNESDAY, TRUE,   1, 31) == TUESDAY);
   assert (dayOfWeek (MONDAY,    FALSE,  1, 31) == MONDAY);
 
   assert (dayOfWeek (TUESDAY,   TRUE,   1,  4) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE,  1,  6) == SATURDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 12, 25) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   2, 29) == WEDNESDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,   2, 11) == SUNDAY);
 
   assert (dayOfWeek (MONDAY,    TRUE,   2, 29) == MONDAY);
   assert (dayOfWeek (MONDAY,    TRUE,   2, 28) == SUNDAY);
   assert (dayOfWeek (MONDAY,    TRUE,   2, 27) == SATURDAY);
   assert (dayOfWeek (MONDAY,    TRUE,   1,  3) == SUNDAY);
 
   assert (dayOfWeek (WEDNESDAY, TRUE,  1,  23) == MONDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,  3,  19) == TUESDAY);
 
   //Testing boundaries for different kind of year
   //year: 2000 - doomsday: TUESDAY - leap year
   assert (dayOfWeek (TUESDAY, TRUE,  1,  1) == SATURDAY);
   assert (dayOfWeek (TUESDAY, TRUE, 12, 31) == SUNDAY);
   assert (dayOfWeek (TUESDAY, TRUE,  2, 29) == TUESDAY);
   assert (dayOfWeek (TUESDAY, TRUE,  3,  1) == WEDNESDAY);
 
   //year: 1984 - doomsday: WEDNESDAY - leap year
   assert (dayOfWeek (WEDNESDAY, TRUE,  1,  1) == SUNDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 12, 31) == MONDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  2, 29) == WEDNESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  3,  1) == THURSDAY);
 
   //year: 1900 - doomsday: WEDNESDAY - non leap year
   assert (dayOfWeek (WEDNESDAY, FALSE,  1,  1) == MONDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 12, 31) == MONDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE,  2, 28) == WEDNESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE,  3,  1) == THURSDAY);
 
   //year: 2011 - doomsday: MONDAY - non leap year
   assert (dayOfWeek (MONDAY, FALSE,  1,  1) == SATURDAY);
   assert (dayOfWeek (MONDAY, FALSE, 12, 31) == SATURDAY);
   assert (dayOfWeek (MONDAY, FALSE,  2, 28) == MONDAY);
   assert (dayOfWeek (MONDAY, FALSE,  3,  1) == TUESDAY);
 
   //testing each month for a leap year (2012)
   assert (dayOfWeek (WEDNESDAY, TRUE,  1,  1) == SUNDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  2,  1) == WEDNESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  3,  1) == THURSDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  4,  1) == SUNDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  5,  1) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  6,  1) == FRIDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  7,  1) == SUNDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  8,  1) == WEDNESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  9,  1) == SATURDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 10,  1) == MONDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 11,  1) == THURSDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 12,  1) == SATURDAY);
 
   //testing each month for a non leap year (2009)
   assert (dayOfWeek (SATURDAY, FALSE,  1,  1) == THURSDAY);
   assert (dayOfWeek (SATURDAY, FALSE,  2,  1) == SUNDAY);
   assert (dayOfWeek (SATURDAY, FALSE,  3,  1) == SUNDAY);
   assert (dayOfWeek (SATURDAY, FALSE,  4,  1) == WEDNESDAY);
   assert (dayOfWeek (SATURDAY, FALSE,  5,  1) == FRIDAY);
   assert (dayOfWeek (SATURDAY, FALSE,  6,  1) == MONDAY);
   assert (dayOfWeek (SATURDAY, FALSE,  7,  1) == WEDNESDAY);
   assert (dayOfWeek (SATURDAY, FALSE,  8,  1) == SATURDAY);
   assert (dayOfWeek (SATURDAY, FALSE,  9,  1) == TUESDAY);
   assert (dayOfWeek (SATURDAY, FALSE, 10,  1) == THURSDAY);
   assert (dayOfWeek (SATURDAY, FALSE, 11,  1) == SUNDAY);
   assert (dayOfWeek (SATURDAY, FALSE, 12,  1) == TUESDAY);
 
   //random various tests
   assert (dayOfWeek (MONDAY,   TRUE,  3, 24) == THURSDAY);
   assert (dayOfWeek (MONDAY,   FALSE, 3, 24) == THURSDAY);
   assert (dayOfWeek (THURSDAY, FALSE, 2, 17) == SUNDAY);
   assert (dayOfWeek (THURSDAY, TRUE,  2, 17) == SATURDAY);
   assert (dayOfWeek (SUNDAY,   TRUE, 11, 14) == SUNDAY);
   assert (dayOfWeek (SUNDAY,   TRUE,  2, 21) == SATURDAY);
   assert (dayOfWeek (MONDAY,   TRUE,  5,  7) == SATURDAY);
   assert (dayOfWeek (MONDAY,   FALSE, 7,  5) == TUESDAY);
   assert (dayOfWeek (SATURDAY, FALSE, 2, 28) == SATURDAY);
   assert (dayOfWeek (MONDAY,   TRUE,  2, 28) == SUNDAY);
   assert (dayOfWeek (MONDAY,   TRUE,  2, 29) == MONDAY);
   assert (dayOfWeek (MONDAY,   TRUE,  1,  3) == SUNDAY);
   assert (dayOfWeek (MONDAY,   TRUE,  1,  4) == MONDAY);
   assert (dayOfWeek (SATURDAY, FALSE, 1,  3) == SATURDAY);
   assert (dayOfWeek (SATURDAY, FALSE, 1,  4) == SUNDAY);
   assert (dayOfWeek (TUESDAY,  FALSE, 6, 6) == TUESDAY);
   assert (dayOfWeek (TUESDAY,  TRUE, 1, 31) == MONDAY);
   //different fix for the commented issue
   assert (dayOfWeek (WEDNESDAY, TRUE,  1,  6) == FRIDAY);
 
   // tests 2012
   assert (dayOfWeek(WEDNESDAY, TRUE, 11, 16) == FRIDAY); // today
   assert (dayOfWeek(WEDNESDAY, TRUE, 11, 17) == SATURDAY); // tomorrow
   assert (dayOfWeek(WEDNESDAY, TRUE, 10, 13) == SATURDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 6, 28) == THURSDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 1, 8) == SUNDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 1, 23) == MONDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 2, 9) == THURSDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 2, 14) == TUESDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 2, 26) == SUNDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 2, 28) == TUESDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 3, 1) == THURSDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 3, 5) == MONDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 4, 6) == FRIDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 4, 30) == MONDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 5, 9) == WEDNESDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 5, 18) == FRIDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 5, 28) == MONDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 6, 3) == SUNDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 6, 20) == WEDNESDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 6, 30) == SATURDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 7, 3) == TUESDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 7, 12) == THURSDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 7, 27) == FRIDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 8, 1) == WEDNESDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 8, 13) == MONDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 9, 11) == TUESDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 9, 24) == MONDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 10, 11) == THURSDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 10, 26) == FRIDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 11, 19) == MONDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 11, 24) == SATURDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 12, 24) == MONDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 12, 30) == SUNDAY);
 
   // 2011
   assert (dayOfWeek(MONDAY, FALSE, 1, 12) == WEDNESDAY);
   assert (dayOfWeek(MONDAY, FALSE, 2, 22) == TUESDAY);
   assert (dayOfWeek(MONDAY, FALSE, 3, 4) == FRIDAY);
   assert (dayOfWeek(MONDAY, FALSE, 4, 23) == SATURDAY);
   assert (dayOfWeek(MONDAY, FALSE, 5, 8) == SUNDAY);
   assert (dayOfWeek(MONDAY, FALSE, 6, 17) == FRIDAY);
   assert (dayOfWeek(MONDAY, FALSE, 7, 12) == TUESDAY);
   assert (dayOfWeek(MONDAY, FALSE, 8, 7) == SUNDAY);
   assert (dayOfWeek(MONDAY, FALSE, 9, 27) == TUESDAY);
   assert (dayOfWeek(MONDAY, FALSE, 10, 5) == WEDNESDAY);
   assert (dayOfWeek(MONDAY, FALSE, 11, 30) == WEDNESDAY);
   assert (dayOfWeek(MONDAY, FALSE, 12, 19) == MONDAY);
 
    // 2013
   assert (dayOfWeek(THURSDAY, FALSE, 4, 20) == SATURDAY);
   assert (dayOfWeek(THURSDAY, FALSE, 2, 13) == WEDNESDAY);
 
   // contribution to the unit tests
   assert (dayOfWeek(SATURDAY, FALSE, 10, 9) == FRIDAY);
   assert (dayOfWeek(THURSDAY, FALSE, 10, 19) == SATURDAY);
   assert (dayOfWeek(MONDAY, TRUE, 1, 1) == FRIDAY);
   assert (dayOfWeek(WEDNESDAY, TRUE, 11, 15) == THURSDAY);
 
 
 
   // Contribution by AB. Random months and dates for all years starting from 2012 (at top) to 1900.
   // Calculated using Excel with correction for Excel's wrong leap year determination for 1900, the reason
   // for which this is interesting in itself)
 
   assert (dayOfWeek (WEDNESDAY, TRUE, 12, 19) ==  WEDNESDAY);
   assert (dayOfWeek (MONDAY,     FALSE, 3, 9) ==  WEDNESDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 8, 26) ==  THURSDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 12, 12) ==  SATURDAY);
   assert (dayOfWeek (FRIDAY,    TRUE, 9, 12) ==  FRIDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 12, 29) ==  SATURDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 6, 8) ==  THURSDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 9, 31) ==  SATURDAY);
   assert (dayOfWeek (SUNDAY,    TRUE, 10, 26) ==  TUESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 7, 19) ==  SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 10, 1) ==  TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 8, 15) ==  WEDNESDAY);
   assert (dayOfWeek (TUESDAY,   TRUE, 7, 21) ==  FRIDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 7, 18) ==  SUNDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 4, 6) ==  MONDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 6, 10) ==  TUESDAY);
   assert (dayOfWeek (THURSDAY,  TRUE, 10, 10) ==  THURSDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 1, 24) ==  TUESDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 3, 17) ==  THURSDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 11, 19) ==  FRIDAY);
   assert (dayOfWeek (SATURDAY,  TRUE, 12, 12) ==  SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 9, 17) ==  TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 7, 20) ==  FRIDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 12, 29) ==  FRIDAY);
   assert (dayOfWeek (MONDAY,    TRUE, 1, 8) ==  FRIDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 3, 19) ==  THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 5, 3) ==  SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 8, 15) ==  THURSDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 8, 17) ==  FRIDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 10, 5) ==  WEDNESDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 2, 25) ==  THURSDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 4, 8) ==  WEDNESDAY);
   assert (dayOfWeek (FRIDAY,    TRUE, 6, 2) ==  MONDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 10, 28) ==  SUNDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 7, 9) ==  SUNDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 9, 25) ==  SUNDAY);
   assert (dayOfWeek (SUNDAY,    TRUE, 7, 3) ==  SATURDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 10, 29) ==  WEDNESDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 2, 6) ==  WEDNESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 2, 1) ==  THURSDAY);
   assert (dayOfWeek (TUESDAY,   TRUE, 6, 16) ==  FRIDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 2, 20) ==  SATURDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 8, 17) ==  MONDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 5, 4) ==  SUNDAY);
   assert (dayOfWeek (THURSDAY,  TRUE, 12, 30) ==  MONDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 7, 1) ==  SATURDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 5, 25) ==  WEDNESDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 7, 14) ==  WEDNESDAY);
   assert (dayOfWeek (SATURDAY,  TRUE, 12, 7) ==  MONDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 2, 9) ==  SATURDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 2, 29) ==  THURSDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 10, 1) ==  SUNDAY);
   assert (dayOfWeek (MONDAY,    TRUE, 4, 24) ==  SUNDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 10, 20) ==  TUESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 10, 29) ==  WEDNESDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 5, 20) ==  MONDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 9, 1) ==  SATURDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 5, 9) ==  MONDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 5, 14) ==  FRIDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 4, 29) ==  WEDNESDAY);
   assert (dayOfWeek (FRIDAY,    TRUE, 4, 26) ==  SATURDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 8, 9) ==  THURSDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11, 18) ==  SATURDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 1, 8) ==  SATURDAY);
   assert (dayOfWeek (SUNDAY,    TRUE, 1, 31) ==  SATURDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 5, 7) ==  WEDNESDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 6, 3) ==  MONDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 5, 24) ==  THURSDAY);
   assert (dayOfWeek (TUESDAY,   TRUE, 12, 27) ==  WEDNESDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 1, 12) ==  TUESDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 10, 27) ==  TUESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 11, 25) ==  TUESDAY);
   assert (dayOfWeek (THURSDAY,  TRUE, 2, 17) ==  SATURDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 5, 4) ==  THURSDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 7, 1) ==  FRIDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 11, 19) ==  FRIDAY);
   assert (dayOfWeek (SATURDAY,  TRUE, 11, 1) ==  SUNDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 1, 28) ==  MONDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 8, 17) ==  FRIDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11, 1) ==  WEDNESDAY);
   assert (dayOfWeek (MONDAY,    TRUE, 11, 28) ==  MONDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 7, 3) ==  FRIDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 2, 18) ==  TUESDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 4, 12) ==  FRIDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 6, 23) ==  SATURDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 5, 31) ==  TUESDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 5, 22) ==  SATURDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 8, 7) ==  FRIDAY);
   assert (dayOfWeek (FRIDAY,    TRUE, 11, 9) ==  SUNDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 8, 7) ==  TUESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 12, 2) ==  SATURDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 5, 14) ==  SATURDAY);
   assert (dayOfWeek (SUNDAY,    TRUE, 8, 14) ==  SATURDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 6, 2) ==  MONDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 10, 10) ==  THURSDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 5, 29) ==  TUESDAY);
   assert (dayOfWeek (TUESDAY,   TRUE, 7, 15) ==  SATURDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 5, 29) ==  SATURDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 5, 28) ==  THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 1, 7) ==  TUESDAY);
   assert (dayOfWeek (THURSDAY,  TRUE, 10, 4) ==  FRIDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 6, 26) ==  MONDAY);
   assert (dayOfWeek (MONDAY,    FALSE, 5, 2) ==  MONDAY);
   assert (dayOfWeek (SUNDAY,    FALSE, 1, 31) ==  SUNDAY);
   assert (dayOfWeek (SATURDAY,  TRUE, 8, 17) ==  MONDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 12, 19) ==  THURSDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 8, 16) ==  THURSDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 6, 7) ==  WEDNESDAY);
   assert (dayOfWeek (MONDAY,    TRUE, 1, 9) ==  SATURDAY);
   assert (dayOfWeek (SATURDAY,  FALSE, 11, 18) ==  WEDNESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 1, 7) ==  TUESDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 11, 22) ==  FRIDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 11, 11) ==  SUNDAY);
 
// Just to test peoples handling of neg numbers :D
   assert (dayOfWeek (THURSDAY,  FALSE, 10, 31) ==  THURSDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 11,  0) ==  THURSDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 11, -1) ==  WEDNESDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 11, -20) ==  FRIDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 1, -1) ==  SUNDAY);
   assert (dayOfWeek (THURSDAY,  TRUE, 1, -1) ==  SATURDAY);
 
// year 1988 - doomsday is MONDAY
   assert (dayOfWeek (MONDAY,    TRUE,   1,  4) == MONDAY);
   assert (dayOfWeek (MONDAY,    TRUE,   2, 29) == MONDAY);
   assert (dayOfWeek (MONDAY,    TRUE,   4, 16) == SATURDAY);
   assert (dayOfWeek (MONDAY,    TRUE,   3,  7) == MONDAY);
 
// FALSE DATES (with true assertions)
   assert (dayOfWeek (MONDAY,    FALSE,  2, 29) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE,  9, 31) == MONDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  12, 32) == TUESDAY);
 
   // First and last day of each month in 2012.
   assert (dayOfWeek (WEDNESDAY, TRUE,   1,  1)  ==  SUNDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   1,  31) ==  TUESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   2,  1)  ==  WEDNESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   2,  29) ==  WEDNESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   3,  1)  ==  THURSDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   3,  31) ==  SATURDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   4,  1)  ==  SUNDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   4,  30) ==  MONDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   5,  1)  ==  TUESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   5,  31) ==  THURSDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   6,  1)  ==  FRIDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   6,  30) ==  SATURDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   7,  1)  ==  SUNDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   7,  31) ==  TUESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   8,  1)  ==  WEDNESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   8,  31) ==  FRIDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   9,  1)  ==  SATURDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   9,  30) ==  SUNDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   10, 1)  ==  MONDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   10, 31) ==  WEDNESDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   11, 1)  ==  THURSDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   11, 30) ==  FRIDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   12, 1)  ==  SATURDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,   12, 31) ==  MONDAY);
 
   assert (dayOfWeek (FRIDAY,    TRUE,  1,  11) == FRIDAY);
 
   // Testing Christmas day of this year (2012) which is a leap
   // year and next year (2013) which is not a leap year
   assert (dayOfWeek (WEDNESDAY, TRUE,  12, 25) == TUESDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 12, 25) == WEDNESDAY);
 
   assert (dayOfWeek (MONDAY,  FALSE, 4, 3) == SUNDAY);
   assert (dayOfWeek (MONDAY,  FALSE, 4, 5) == TUESDAY);
 
   // LB: two 'random' dates added.
   assert (dayOfWeek (WEDNESDAY, TRUE,  5,  10) == THURSDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE,  9,  29) == SATURDAY);
 
   assert (dayOfWeek (WEDNESDAY, TRUE, 11, 12) == MONDAY);
 
   // My birthday this year, because I was creative enough to think of it
   assert (dayOfWeek (WEDNESDAY, FALSE,  3,  24) == SATURDAY);


