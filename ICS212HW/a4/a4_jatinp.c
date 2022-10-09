/**
 * Age Calculator which figures out how old a person is in days.
 * @author Jatin Pandya
 * @since 1/23/2018
 */

// Libraries that allow program to work
#include <stdio.h>
#include "getdouble.h"
// Constants
#define DAYINYEAR 365.25
#define MONTHINYEAR 12.0


    int main (void)
    {
        // Variables
        int month = 0;
        int day = 0;
        int year = 0;
        int currentM = 1;
        int currentD = 28;
        int currentY = 2019;
        int numOfDay = 0;
        int currNumODay = (currentY * DAYINYEAR) + ((currentM - 1) * DAYINYEAR / MONTHINYEAR) + currentD;
        int numOfDayOld = 0;

        puts ("This program shows your age in days");
        puts ("Please enter the month you are born in: ");
        month = getdouble();
        puts ("Please enter the day you were born on: ");
        day = getdouble();
        puts ("Please enter the year you were born in: ");
        year = getdouble();
        numOfDay = (year * DAYINYEAR) + ((month - 1) * DAYINYEAR / MONTHINYEAR) + day;
        numOfDayOld = currNumODay - numOfDay;
       
        printf("Current date is 1/28/2019\n");
        if (numOfDayOld < 1000)
        {
            printf("You are ");
            printf("%d",numOfDayOld);
            printf(" days old\n");

        }
        else 
        {
            printf("You are ");
            // Taken from https://stackoverflow.com/questions/1449805
            // /how-to-format-a-number-from-1123456789-to-1-123-456-789-in-c
            printf("%i",numOfDayOld/1000);
            int partB =  numOfDayOld;
           partB =  partB %  1000;
            printf(",%03i", partB);
            printf(" days old\n");
        }
        return 0;
    }
