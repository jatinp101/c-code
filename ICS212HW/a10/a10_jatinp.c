/**
 * Demonstrating arrays
 * @author Jatin Pandya
 * @since 2/14/2019
 */

#include <stdio.h>
#define SIZE 26
// Printing instructions
void printInstructions (void) {
    printf("Please enter in text and once you're done press CTRL + D to view number of times you used each letter\n");
}
// Getting letters and increasing value of array
void loopAndCountLetters (int letters[]) {
    char temp = "";
    int i = 0;
    while (temp != EOF){
    temp = getchar();
    i = temp - 'a';
    if (0 <= i && i <= 26){
        letters[i] += 1;
    }
    else if (i < 0) {
        i = temp - 'A';
        letters[i] += 1;
    }
    }
}
// Printing out array.
void outputResults(int letters[]) {
    int i = 0;
    char low = 'a';
    char cap = 'A';
    while (i < SIZE) {
        printf("%c or %c : %i\n", low, cap, letters[i]);
        i++;
        low++;
        cap++;
    }
}
int main(){
    //create array for 26 letters
   int letters[SIZE] = {0};
   printInstructions();
   loopAndCountLetters(letters);
   outputResults(letters);
   return 0;
}
