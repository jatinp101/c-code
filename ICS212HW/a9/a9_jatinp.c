/**
 * Fun with recursion.
 * @author Jatin Pandya
 * @since 2/13/2019
 */

#include <stdio.h>
#include "getdouble.h"

// Counting numbers.
void counting (int first, int last) {
    if (first == last)
        printf("%i\n",first);
    else {
        printf("%i ",first);
        first++;
        counting(first,last);
    }
}

// Adding up numbers.
int sumUp (int first, int last) {
    if (first == last)
        return first;
    else
        return first + sumUp(first + 1,last);
}
// Multiplying the numbers.
int multiply (int first, int last) {
     if (first == last)
         return first;
     else
         return first * multiply(first + 1,last);
}
// Finding the powers of the number.
int powers(int first, int last) {
    if (last != 0)
        return (first * powers(first, last - 1));
    else
        return 1;
}
// Finding the GCD of the two numbers.
int gcdCal(int first, int last) {
    if (last == 0)
        return first;
    else
        return gcdCal(last, first % last);
}
int main (void){
    int first = 0;
    int last = 0;
    int sum = 0;
    int product = 0;
    int power = 0;
    int gcd = 0;
    int eLoop = 0;

    while (eLoop != 1) {
        printf ("Enter two positive integers, separated by a space, the first smaller than the second:\n");

        first = getdouble();
        last = getdouble();

        if (first > last)
            printf ("%i is not smaller than %i",first,last);
        if (first < 0 || last < 0)
            printf("ERROR: both numbers must be positive");
        else 
            break;
    }
    printf ("Counting from %i to %i: ",first,last);
    counting(first, last);
    sum = sumUp(first, last);
    printf ("The sum from %i to %i: %i\n", first, last, sum);
    product = multiply(first, last);
    printf ("The product of %i to %i: %i\n", first, last, product);
    power = powers(first, last);
    printf("The power of %i to the %i power is: %i\n",first, last,power);
    gcd = gcdCal(first, last);
    printf("The GCD of %i and %i is: %i\n", first, last, gcd);
}

