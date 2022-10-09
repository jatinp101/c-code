/**
 * Sort and shuffle a deck of cards.
 * @author Jatin P
 * @since 9/12/2019
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX 9
#define MAX_CARDS 52
#define MAX_RANKS 13
#define MAX_SUITS 4
#define COLS 2 //number of columns to display in output
#define MAX_COLOURS 2

//structure definition
struct card{ 
    char *rank;    
    char suit[MAX];
    char *colour;
};
typedef struct card Card;

//array of pointers to strings for ranks
char *ranks[MAX_RANKS] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", 
                  "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

//two-dimensional array of strings for suits
char suits[MAX_SUITS][MAX] = {"Clubs", "Diamonds", "Hearts", "Spades"};

char *colours [MAX_COLOURS] = {"Red", "Black"};

void initialize(Card []);
void shuffle(Card []);
void display(const Card[]);

int main (){
    char newLine = '\n';
    // Declare and array of 52 cards
     Card deck[MAX_CARDS] = {"","",""};
     initialize(deck);
     printf("Display an ordered deck of cards:\n");
     display(deck);
     while('\n' == newLine){
         printf("\nshuffling deck ... \n\n");
         shuffle(deck);
         display(deck);
         printf("\n\nWould you like to shuffle again?\nIf so, press \"Enter\" key. If not, enter any other char. ");
         newLine = getchar();
     }
     return 0;
}

/*
 *   initialize the deck of cards to string values
 *     deck: an array of structure cards 
 */
void initialize(Card deck[]){
      int i = 0;
      for(i=0;i<MAX_CARDS;i++){
            deck[i].rank = ranks[i%MAX_RANKS];
            strncpy(deck[i].suit, suits[i/MAX_RANKS], MAX);
            deck[i].colour = colours[i%MAX_COLOURS];
      }
}

/*
 *   use the pseudo-random number generator to shuffle the cards
 *     deck: an array of structure cards 
 */
void shuffle(Card deck[]){
      int swapper = 0; //index of card to be swapped
      int i = 0; //counter
      Card temp = {"", ""}; //temp holding place for swap
      srand(time(NULL)); //seed the random numbers with current time
      for(i=0;i<MAX_CARDS;i++){
          //generate a pseudo-random number from 0 to 51
          swapper = rand() % MAX_CARDS; 
          //swap current card with da swapper
          temp = deck[i];
          deck[i] = deck[swapper];
          deck[swapper] = temp;
      }
}

/*
 *   display the deck of cards
 *     deck: an array of structure cards 
*/
void display(const Card deck[]){
    int i = 0;
    for(i=0;i<MAX_CARDS;i++){
        printf("%5s of %s (%s)%-10s", deck[i].rank, deck[i].suit, deck[i].colour, "");//%5s makes "of" line up -10 makes cols.
        //put in a newline every %x loops
        if((COLS-1) == (i%COLS)){
            printf("\n");
        }
    }
}
