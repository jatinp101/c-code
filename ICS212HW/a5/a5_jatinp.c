/**
 * Takes in a number and outputs it in a foreign language.
 * @author Jatin P
 * @since 1/28/2018
 */

//Libraries needed for program to work
#include <stdio.h>

    int main (void)
    {
        char takeIn = 'a';
        printf("Program will take in an inputted number and output the same number in spanish\n");

        printf("Please enter in a number(integer) from 0-9: \n");
        takeIn = getchar();

        switch (takeIn) 
            {
                case '0': puts("cero"); break;
                case '1': puts("uno"); break;
                case '2': puts("dos"); break;
                case '3': puts("tres"); break;
                case '4': puts("cuatro"); break;
                case '5': puts("cinco"); break;
                case '6': puts("seis"); break;
                case '7': puts("siete"); break;
                case '8': puts("ocho"); break;
                case '9': puts("nueve"); break;
                default:
                         puts("You have either entered a special character or a letter please run the program and try again");
                         break;
            }
        return 0;
    }
