/**
 * Function for C.
 * @author Jatin P 
 * @since 2/05/2019
 */

// got equation from
// https://www.thecrazyprogrammer.com/2013/02/c-program-to-calculate-compound-interest.html
#include <stdio.h>
#include <math.h>
#include "getdouble.h"
#include <stdlib.h>
#include <time.h>
int main (void) {

    int  power = 0.0;
    double eLoop = 0.0;
    int n = 0;
    int p = 0;
    int t = 0;
    // Used random function.
    double i = (float)rand()/RAND_MAX;
    printf("Please enter in the principle amount:\n ");
    p = getdouble();
    while (eLoop != 1) {
        puts("Please enter in the amount of times during the year money will be compounded");
        puts("1 for yearly");
        puts("2 for monthly");
        puts("3 for quarterly");
        puts("4 for daily");
        char s = getchar();
        getchar();

        switch (s) {
            case '1' : t = 1; eLoop = 1; break;
            case '2' : t = 12; eLoop = 1; break;
            case '3' : t = 4; eLoop = 1; break;
            case '4' : t = 365; eLoop = 1; break;
            default:  puts("Please select a number on the list");
                      break;
        }
    }
    printf("Please enter in the amount of years the money will be compunded by: ");
    n = getdouble();
    power = n * t;
    // (uses absolue value function and power) Compound interest regular.
    float ci=p*pow(fabs((1+i/t)),power);
    printf("Amount that would be compounded not rounded $%.2f\n",ci);

    // (uses ceiling function) Compund interest rounding up.
    float bi=ceil(p*pow((1+i/t),power));
    printf("Amount that would be compunded rounded up $%.2f\n",bi);

    //(uses floor function) Compund interest rounding down.
    float ai=floor(p*pow((1+i/t),power));
    printf("Amount that would be compunded rounded down $%.2f\n",ai);


    return 0;
}
