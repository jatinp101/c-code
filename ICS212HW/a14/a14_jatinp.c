/**
 * Converting Morse code to words
 * @author Jatin Pandya
 * @since 03/02/2019
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 36

const char *morse[SIZE] = {
    "0 ----- ",
    "1 .---- ",
    "2 ..--- ",
    "3 ...-- ",
    "4 ....- ",
    "5 ..... ",
    "6 -.... ",
    "7 --... ",
    "8 ---.. ",
    "9 ----. ",
    "a .- ",
    "b -... ",
    "c -.-. ",
    "d -.. ",
    "e . ",
    "f ..-. ",
    "g --. ",
    "h .... ",
    "i .. ",
    "j .--- ",
    "k -.- ",
    "l .-.. ",
    "m -- ",
    "n -. ",
    "o --- ",
    "p .--. ",
    "q --.- ",
    "r .-. ",
    "s ... ",
    "t - ",
    "u ..- ",
    "v ...- ",
    "w .-- ",
    "x -..- ",
    "y -.-- ",
    "z --.. ",
};

int main(int argc, char *argv[]) {
    int index = 0;
    int i = 0;
    int h = 0;
    int check = 0;
   if (argc < 2) {
       puts ("ERROR: You only typed the executable. Enter the Morse Code on the commandline.");
       exit (1);
   }
   printf("\n");
   for (h = 1; h < argc; h++) {
       for (i = 0; i < SIZE; i++) {
           char *copy;
           char strO [SIZE];
           char *strT;
           strncpy(strO, morse[i], SIZE);
           
           copy = strtok(strO, " ");
           strT = strtok(NULL, " ");
          check = strcmp(argv[h], strT);
          if (check == 0) {
                printf ("%s", copy);
                break;
          }
         }
     }
   printf("\n");
   return 0;
 }


