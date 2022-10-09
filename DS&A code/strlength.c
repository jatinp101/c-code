/* This program is O(n) as it goes through the entire string 
 * checking whether the character is equal to the two characters
 * in the specific substring.
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * The function's input is the char string 'str[]' and its length
 * It will find the longest substring that has just one character.
 * We will refer to such a substring as a "single-string" since 
 * it has only a single character.
 * For example, the longest substring in "aababbbbaa" is "bbbb".
 * It returns the index of the first and last characters in the 
 * substring.  In the example, first = 4 and last = 7.
 */ 
int strlength(char str[], int length, int *first, int *last, int debug);

/*
 * This function will return the length of the char string
 */
int total_length(char str[]);

char str1[] = "aababbbbaabba";
char str2[] = "acbcbbabcccbbca";

void main(int argc, char *argv[])
{
int first, last;

int length = strlength(str1, total_length(str1), &first, &last, 0);
printf("Longest substring of '%s' has length=%d, starts at %d, ends at %d\n", str1, length,first, last);

length = strlength(str2, total_length(str2), &first, &last, 0);
printf("Longest substring of '%s' has length=%d, starts at %d, ends at %d\n", str2, length,first, last);

}



int strlength(char str[], int length, int *first, int *last , int debug)
{
int ssFirst = 0;      /* Beginning of the current single-string */
int bestFirst = 0;    /* Best single-string so far */
int bestLast = 0;
int bestLength = 0;
int k;
char firstChar = str[0];
char secondChar = '^';

if(firstChar == str[1]) secondChar = str[2];
for (k=0; k<length; k++) {
    //if (debug == 1 && (k >= 7)) printf("%c", str[k]);
     if (str[k] == secondChar || str[k] == firstChar) {
        //if (debug == 1 && (k >= 7)) printf("%c", str[k]);
        //if (debug == 1 && (k >= 7)) printf("%c", secondChar);
        bestFirst = ssFirst;
           bestLast = k;
            bestLength = bestLast - bestFirst + 1;
    }
    if (str[k] != firstChar && str[k] != secondChar) { /* End of current substring */
    //if (debug == 1 && (k >= 7)) printf("here %c ", str[k]);
	if((bestLength < length - k)){
               firstChar = str[k-1];
               secondChar = str[k];
               ssFirst = k-1;
            }
    }
}
// if (debug == 1) printf("\n");
// ssLast = k-1;
// if ((ssLast - ssFirst) > (bestLast - bestFirst)) {
//    bestFirst = ssFirst;
//    bestLast = ssLast;
// }

*first = bestFirst;
*last = bestLast;
return bestLength;
}

int total_length(char str[])
{
int k;
for (k=0; str[k]!='\0'; k++);
return k;
}



