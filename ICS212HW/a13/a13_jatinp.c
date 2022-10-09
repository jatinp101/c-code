/*Commandline Calculator: using an array of functions to replace if-statements*/
// @author Jatin P
// @since 2/24/2019

#include <stdio.h>
#include <string.h>
#define MINIMUM 4
#define SIZE 5
//four function prototypes here
int addi (int, int);
int subt (int, int);
int mult (int, int);
int divi (int, int);

int main(int argc, char *argv[]){
    int number1 = 0;
    int number2 = 0;
    int index = 0;
    int outcome = 0;
    int (*array[SIZE])(int x, int y) = {addi,NULL,subt,mult,divi};
    //error checking here

    if (argc < MINIMUM) {
        puts ("ERROR: You have to enter 4 commandline arguments for the calculator.");
        exit(1);
    } else {
        if (argv [1][0] > 57 || argv [1][0] < 48) {
            puts ("ERROR: The second commandline argument should be an integer 0-9.");
            exit (1);
        } else if (argv [2][0] > 47 || argv [2][0] < 43 || argv [2][0] == 44) {
            puts ("ERROR: The third commandline argument should be a +, -, ., or / operator.");
            exit (1);
        } else if (argv [3][0] > 57 || argv [3][0] < 48) {
            puts ("ERROR: The fourth commandline argument should be an integer 0-9.");
            exit (1);
        }
    }

    //convert characters to integers 0-9 here
     number1 = argv[1][0] - '0'; 
     number2 = argv[3][0] - '0';
    //convert symbol input to integer 0-4 here                                                                     
     index = argv[2][0] - '+';

     if (index == 4 && number2 == 0) {
         puts ("ERROR: The fourth commandline argument cannot be 0 while dividing");
         exit (1);
     }
     if (argv [2][0] == 46) 
         argv [2][0] = 42;

     outcome = array[index](number1, number2);
     printf ("%i %c %i = %i\n",number1,argv [2][0], number2, outcome);
    // Creating funtion array

     return 0;
 } 

//four function definitions here
int addi(int x, int y){
       return x + y;
}

int subt(int x, int y){
       return x - y;
}

int mult(int x, int y){
       return x * y;
}

int divi(int x, int y){
       return x / y;
}

