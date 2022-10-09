/**
 * Reads 2 charactes and numbers from user and returns them.
 * @author Jatin P
 * @since 1/21/2018
 */


#include <stdio.h>  /*library needed for printf and getchar*/
#include "getdouble.h" /*library needed for getdouble function*/

int main (void) 
{
    /*declare variable and initialize variable*/
    char letter = 'A';
char letterTwo = 'A';
char takeBlank = 'A';
double one = 0.00;
double two = 0.00;
        /*ask for user input, get the character, and display*/
        printf("Please enter a letter: \n");
          letter = getchar();
          takeBlank = getchar();
          
          printf("Please enter another letter:\n ");
                    letterTwo = getchar();
                    takeBlank = getchar();
            /*
             *
               i%c is the format specifier, which outputs in a specific format
             *         in this case, the ASCII character format 
             *           */
          printf("The first letter entered is: '%c'\n", letter);
          printf("The second letter entered is: '%c'\n", letterTwo);

          printf("Please enter a number: ");
          one = getdouble();

          printf("Please enter another number: ");
          two = getdouble();

          /*%f is the format specifier for floats*/
            printf("The first number is: %f\n", one);
            printf("The second number is: %f\n", two);
            return 0;
}
