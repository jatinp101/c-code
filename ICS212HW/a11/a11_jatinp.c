/**
 * Demonstration of Pointers.
 * @author Jatin Pandya
 * @since 2/18/2019
 */

#include <stdio.h>

int main () {
    // Initailizing variables
    char letter = 'B';
    int integer = 2;
    double decimal = 2.345678;
    // Initializing pointers
    char *pLetter = NULL;
    int *pInteger = NULL;
    double *pDecimal = NULL;
    // Assigning address to pointers
    pLetter = &letter;
    pInteger = &integer;
    pDecimal = &decimal;

    puts ("Here are the address of the 3 variables which are stored in the 3 pointers: ");
    printf ("address of pointer #1 = %p\n",pLetter);
    printf ("address of pointer #2 = %p\n",pInteger);
    printf ("address of pointer #3 = %p\n",pDecimal);

    puts ("\nHere are the values of the 3 variables using the 3 dereferenced pointers:");
    printf ("dereferenced pointer #1 = %c\n",*pLetter);
    printf ("dereferenced pointer #2 = %i\n",*pInteger);
    printf ("dereferenced pointer #3 = %f\n",*pDecimal);

    puts ("\nNow my program is adding 3 to the 3 dereferenced pointers...\n");

    *pLetter = *pLetter + 3;
    *pInteger = *pInteger + 3;
    *pDecimal = *pDecimal + 3;

    puts ("Here are the updated values of the 3 variables using the 3 dereferenced pointers:");
    printf ("dereferenced pointer #1 = %c\n",*pLetter);
    printf ("dereferenced pointer #2 = %i\n",*pInteger);
    printf ("dereferenced pointer #3 = %f\n",*pDecimal);

    puts ("\nHere are the updated values of the 3 variables:");
    printf ("character variable = %c\n",letter);
    printf ("integer variable = %i\n",integer);
    printf ("double variable = %f\n",decimal);
    return 0;
}
