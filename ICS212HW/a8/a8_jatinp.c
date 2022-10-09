/**
 * Rock Paper Scissors game.
 * @author Jatin P
 * @since 2/11/2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int showPlayers(int PO, int PT) {
    printf("User picked: ");
    if (PO == 1) 
        printf("rock\n");
    if (PO == 2)
        printf("paper\n");
    if (PO == 3)
        printf("sissors\n");

    printf("Computer picked: ");
    if (PT == 1)
        printf("rock\n");
    if (PT == 2)
        printf("paper\n");
    if (PT == 3)
        printf("sissors\n");
}
int conclusion (int comWin, int usWin, int ties) {
    printf("User wins: %i\n", usWin);
    printf("Computer wins: %i\n", comWin);
    printf("Ties: %i\n", ties);
    return 0;
}
int ranGenPT (void) {
    int computer = rand()%3+1;
    return computer;
}

int checkWin (int PO, int PT) {
    if (PO == 1){
        if (PT == 1)
            return 2;
        if (PT == 2)
            return 0;
        if (PT == 3)
            return 1;
    }
    else if (PO == 2) {
        if (PT == 1)
            return 1;
        if (PT == 2)
            return 2;
        if (PT == 3)
            return 0;
    }
    else {
        if (PT == 1)
            return 0;
        if (PT == 2)
            return 1;
        if (PT == 3)
            return 2;
    }
}

int main (void) {
    char pOIn = "";
    int PO = 0;
    int PT = 0;
    int eLoop = 0;
    int cWins = 0;
    int uWins = 0;
    int chWin = 0;
    int ties = 0;

    puts("Welcome to the rock-paper-scissors game!");
    puts("To quit the game, press Ctrl-D (which will output '^D' on the screen).");

    while (eLoop != 1) {
    PT = ranGenPT();
    while (eLoop != 1){
     printf("Enter 'r', 'p', or 's' for rock, paper, or scissors: ");
     pOIn = getchar();
     getchar();
     switch (pOIn) {
         case 'r' : PO = 1; eLoop = 1; break;
         case 'p' : PO = 2; eLoop = 1; break;
         case 's' : PO = 3; eLoop = 1; break;
         case EOF : eLoop = 1; break;
         default: puts ("USER INPUT ERROR"); break;
     }
     }
     eLoop = 0;
     if (pOIn == EOF)
         break;

     chWin = checkWin(PO, PT);
    showPlayers(PO, PT);
    printf("Therefore ");
     if (chWin == 1){
         uWins++;
         puts("User wins");
     }
     else if (chWin == 2){
         ties++;
         puts("Its a tie");
     }
     else {
         cWins++;
         puts ("Computer wins");
    }

    }
    conclusion(cWins, uWins, ties);
    return 0;
}
