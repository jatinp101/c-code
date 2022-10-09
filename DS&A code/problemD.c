#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define UNFILLED -1  /* Indicates a memo entry is unfilled */

int ** create_memo(int n);  /* Creates an nxn memo array and initializes it */
int ** create_int_matrix(int n); /* Creates an nxn integer array */
void destroy_int_matrix(int ** matrix, int n); /* Destroys an nxn array */
void display_scores(int a[], int length); /* Displays score values in a[] */

int win(int a[], int length);
int getTotalScores (int scores[], int length);
int win_rec (int scores[], int s, int e, int **memo);


void main()
{
int scores1[3] = {1, 5, 2};
int length1 = 3;
display_scores(scores1, length1);
printf("Outcome: %d\n\n", win(scores1, length1));

int scores2[4] = {1, 5, 233, 7};
int length2 = 4;
display_scores(scores2, length2);
printf("Outcome: %d\n\n", win(scores2, length2));

int scores3[7] = {1, 2, 1, 3, 1, 4, 1};
int length3 = 7;
display_scores(scores3, length3);
printf("Outcome: %d\n\n", win(scores3, length3));

int scores4[7] = {1, 2, 8, 12, 1, 4, 2};
int length4 = 7;
display_scores(scores4, length4);
printf("Outcome: %d\n\n", win(scores4, length4));

int scores5[6] = {4, 8, 21, 1, 4, 2};
int length5 = 6;
display_scores(scores5, length5);
printf("Outcome: %d\n\n", win(scores5, length5));
}

/*
 *  You modify "win()".  You can also create another function
 *  "win_rec()" that win() calls.
 */
int win(int scores[], int length)
{
    int** memo;
    memo = create_memo(length);
   
   int scoreFirst = win_rec(scores, 0, length-1, memo); // Final score of the first player.
  
    int scoreTotal = getTotalScores(scores, length);
  
        // Compare final scores of two players.
        int score2 = scoreTotal - scoreFirst;
        if (score2 > scoreFirst) return 0;
        else return 1;
}
 int getTotalScores (int scores[], int length) {
        int scoreTotal = 0;
        for (int i=0; i<length; i++) {
            scoreTotal += scores[i];
        }
        
        return scoreTotal;
    }

int win_rec (int scores[], int i, int j, int **memo) {
        // Base cases
        if (i > j){
             return 0;

        }
        if (i == j) return scores[i];
        if (memo[i][j] != UNFILLED) {
            return memo[i][j];
        } 

        int a = scores[i];
        int b = scores[j];

        // Recursive cases.
        int a1 = win_rec(scores, i+2, j, memo);
        int a2 = win_rec(scores, i + 1, j -1, memo);
        if ( a1 <= a2 ) a += a1;
        else a += a2;

        int b1 = win_rec(scores, i, j - 2, memo);
        int b2 = win_rec(scores, i + 1, j -1, memo);
        if ( b1 <= b2 ) b += b1;
        else b += b2;
        int currScore = 0;
        if (a >= b) currScore = a;
        else currScore = b;
        memo[i][j] = currScore;
        
        return currScore;
}


void display_scores(int a[], int length)
{
printf("Scores: ");
for (int i=0; i<length; i++) {
    printf("%d ",a[i]);
}
printf("\n");
}

int ** create_memo(int n)
{
int ** matrix = create_int_matrix(n);
for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
	matrix[i][j] = UNFILLED;
    }
}
return matrix;
}

int ** create_int_matrix(int n)
{
int ** matrix = (int **) malloc(n*sizeof(int *));
for (int i=0; i<n; i++) {
    matrix[i] = (int *) malloc(n*sizeof(int));
}
return matrix;
}

void destroy_int_matrix(int ** matrix, int n)
{
for (int i=0; i<n; i++) {
    free(matrix[i]);
}
free(matrix);
}


