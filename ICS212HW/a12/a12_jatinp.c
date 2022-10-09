/**
 * Demonstrating Call-By-Reference pointer tools and arrays.
 * @author Jatin P
 * @since 2/24/2018
 */

// libraries needed for program to work
#include <stdio.h>
// Constant for the array and printing array out
#define SIZE 5

// Function prototype
void cbRDoubleMult(double *);

// main method
int main (void) {
    // variables
    double number = 3.141593;
    int array[SIZE] = {101,202,303,404,505};
    int *pointer = NULL;
    int i = 0;
    pointer = array;

    // Using call-by-reference function to multiply pi by 2
    printf ("Here is the value of the variable BEFORE a call-by-reference function call:\n");
    printf ("number = %f\n",number);
    puts ("Making a call-by-reference function call...");
    cbRDoubleMult(&number);
    puts ("Here is the value of the variable AFTER a call-by-reference function call:");
    printf ("number = %f\n", number);

    // Printing out a specific element in array using both pointer and array
    puts ("\nHere is the 5th element, using array subscript notation with the array name:");
    printf ("array[4] = %i\n",array[4]);
    puts ("Here is the 5th element, using pointer/offset notation using array name:");
    printf ("*(array + 4) = %i\n", *(array + 4));
    puts ("Here is the 5th element, using array subscript notation with the pointer:");
    printf ("pointer[4] = %i\n", pointer[4]);
    puts ("Here is the 5th element, using pointer/offset notation with the pointer:");
    printf ("*(pointer + 4) = %i\n", *(pointer + 4));

    // Printing out array using both pointer and array
    puts ("\nHere is the whole array, using array subscript notation with the array name:");
    for (i = 0; i < SIZE; i++) {
        printf ("%i, ",array[i]);
    }
    puts ("\nHere is the whole array, using pointer/offset notation using array name:");
    for (i = 0; i < SIZE; i++) {
        printf ("%i, ", *(array + i));
    }
    puts ("\nHere is the whole array, using array subscript notation with the pointer:");
    for (i = 0; i < SIZE; i++) {
        printf ("%i, ",pointer[i]);
    }
    puts ("\nHere is the whole array, using pointer/offset notation using the pointer:");
    for (i = 0; i < SIZE; i++) {
        printf ("%i, ", *(pointer + i));
    }

    // Printing out memory addresses of array
    puts ("\n\nHere is the HEXADECIMAL VALUE (using %p) of the addresses of each element of the array:");
    for (i = 0; i < SIZE; i++) {
        printf ("&array[%i] = %p\n",i, &array[i]);
    }
    return 0;
}

void cbRDoubleMult(double *number) {
    puts ("Here is the value of the parameter DURING a call-by-reference function call, BEFORE changing the value:");
    printf ("number = %f\n", *number);
    puts ("Making changes now to the parameter...");
    *number = *number * 2;
    puts ("Here is the value of the parameter DURING a call-by-reference function call, AFTER changing the value:");
    printf ("number = %f\n", *number);
}
