/**
 * Demonstrating bitwise operators.
 * @author Jatin Pandya
 * @since 3/6/2019
 */
#include <stdio.h>
#include <string.h>
#include "printbits.h"

//function prototypes

int twosComplement(unsigned int); 
unsigned int charPacker(unsigned char, unsigned char, unsigned char, unsigned char);
void intChopper(unsigned int, unsigned char*, unsigned char*, unsigned char*, unsigned char*);
unsigned int circleLeft(unsigned int, unsigned int);

int main(int argc, char *argv[]){
    //error checking
    int checkS = 0;
    int i = 0;
    int h = 5;
    if (argc != 7){
        puts ("ERROR: Please enter the executable name, followed by FOUR characters and then TWO integers on the commandline.");
        printf ("You entered %i argument(s)\n", argc);
        exit (1);
    } 
    for (i = 1; i < 5; i++) {
        checkS = strlen(argv[i]);
        if (isalnum(*argv[i]) == 0) {
        printf ("ERROR: Please enter a character for character #%i on the commandline.\n",i);
        printf ("You entered %s\n", argv[i]);
        exit (1);
        }
        if (checkS > 1) {
        printf ("ERROR: Please enter a character for character #%i on the commandline.\n", i);
        printf ("You entered %s\n", argv[i]);
        exit (1);
        }
    }
    for (h = 5; h < 7; h++) {
        checkS = strlen (argv[h]);
        if (isdigit(*argv[h]) == 0){
                puts ("ERROR: You are missing an integer argument.");
                printf ("You entered %s\n", argv[h]);
                exit (1);
        }
    }
    //function calls
    unsigned int numOne = atoi(argv[5]);
    unsigned int numTwo = atoi(argv[6]);
    unsigned char charOne = *argv[1];
    unsigned char charTwo = *argv[2];
    unsigned char charThree = *argv[3];
    unsigned char charFour = *argv[4];

    puts ("function 1:");

    twosComplement (numTwo);

    puts ("function 2:");

    charPacker (charOne, charTwo, charThree, charFour);

    puts ("function 3:");

    intChopper (numOne, charOne, charTwo, charThree, charFour);
    puts ("funtion 4:");

    circleLeft (numOne, numTwo);
    return 0;
}
//function definitions

int twosComplement (unsigned int x) {
    int temp = x;
    temp -= 1;
    temp = ~temp;

    puts ("Input is unsigned integer:");
    printbits (x);
    puts ("Output is the two's complement of the integer: ");
    printbits (temp);
    return temp;
}

unsigned int charPacker (unsigned char one, unsigned char two, unsigned char three, unsigned char four) {
    unsigned int temp = one;
    temp <<= 8;
    temp |= two;
    temp <<= 8;
    temp |= three; 
    temp <<= 8;
    temp |= four;
    puts ("Input is four characters:");
    printf ("%c = ", one);
    printbits(one);
    printf ("%c = ", two);
    printbits(two);
    printf ("%c = ", three);
    printbits(three);
    printf ("%c = ", four);
    printbits(four);
    puts ("Output is unsigned integer variable in bit format: ");
    printbits(temp);
    return temp;
}

void intChopper (unsigned int x, unsigned char* one, unsigned char* two, unsigned char* three, unsigned char* four) {
    unsigned int temp = 0;
    one = x;
    two = x;
    three = x;
    four = x;
    puts ("Input is unsigned integer: ");
    printbits (one);
    unsigned int mask1 = 0xFF000000;
    unsigned int mask2 = 0xFF0000;
    unsigned int mask3 = 0xFF00;
    unsigned int mask4 = 0xFF;
    puts ("Output is four characters: ");
    // bitshifting and masking one
    temp = one;
    temp = temp & mask1;
    one = temp;
    one = (unsigned int)one >> 24;
    printf ("'%c' = ", (unsigned char)one);
    printbits ((unsigned int)one);
    // bitshifting and masking two
    temp = two;
    temp = temp & mask2;
    two = temp;
    two = (unsigned int) two >> 16;
    printf ("'%c' = ", (unsigned char)two);
    printbits ((unsigned int)two);
    // bitshifting and masking three
    temp = three;
    temp = temp & mask3;
    three = temp;
    three = (unsigned int) three >> 8;
    printf ("'%c' = ", (unsigned char)three);
    printbits ((unsigned int)three);
    // masking four
    temp = four;
    temp = temp & mask4;
    four = temp;
    printf ("'%c' = ", (unsigned char)four);
    printbits ((unsigned int)four);
}

unsigned int circleLeft (unsigned int x, unsigned int y) {
    unsigned int z = (y << x) | (y >> (8 - x));
    puts ("Input is unsigned integer: ");
    printbits (y);
    printf ("Rotated %i bit(s) to the left", x);
    puts ("Output is unsigned integer: ");
    printbits (z);
    return z;
}
