#include <stdlib.h>
#include <stdio.h>

#define NOT_FILLED -1

char str1[] = "abcccdbaa";
char str2[] = "bccabaabc";

int str_length(char str[]) {
    int k=0;
    for (; str[k] != '\0'; k++);
    return k;
}

/*
 **  Create an integer matrix with 'row' and 'col' dimensions
 **  Basically this is an array of 1-dimensional arrays, 
 **  each having length 'col'.
 */
int ** create_matrix(int row, int col) {
    int ** matrix = (int **) malloc(row*sizeof(int *));
    for (int i=0; i<row; i++) {
        matrix[i] = (int *) malloc(col*sizeof(int));
    }
    return matrix; 
}

void destroy_matrix(int ** matrix, int row) {
    for (int i=0; i<row; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void init_matrix(int ** matrix, int row, int col, int val) {
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            matrix[i][j] = val;
        }
    }
}

int lcs_top_rec(int ** memo, char str1[], char str2[], int length1, int length2)
{
if (memo[length1][length2] == NOT_FILLED) {
    if (length1 == 0 || length2 == 0) {
        memo[length1][length2] = 0;
    }
    else if (str1[length1-1] == str2[length2-1]) {
        memo[length1][length2] = 1+lcs_top_rec(memo, str1, str2, length1-1, length2-1);
    }
    else {
	memo[length1][length2] = lcs_top_rec(memo, str1, str2, length1, length2-1);
	int temp = lcs_top_rec(memo, str1, str2, length1-1, length2);
	if (temp > memo[length1][length2]) {
            memo[length1][length2] = temp;
	}
    }

}
return memo[length1][length2];
}

void lcs_display(int ** memo, char str1[], char str2[], int length1, int length2) {
    printf("LCS:\n");
    int index = memo[length1][length2]; 
    char lcs[index+1]; 
    lcs[index] = '\0'; 
  
   int i = length1, j = length2; 
   while (i > 0 && j > 0) 
   { 
      
      if (str1[i-1] == str2[j-1]) 
      { 
          lcs[index-1] = str1[i-1]; 
          i--; j--; index--;     
      } 
  
      else if (memo[i-1][j] > memo[i][j-1]) 
         i--; 
      else
         j--; 
   } 
  
   printf("LCS of %s and %s is %s \n",str1,str2,lcs); 
}

int lcs_top(char str1[], char str2[]) {
    int length1 = str_length(str1);
    int length2 = str_length(str2);
    int ** memo = create_matrix(length1+1, length2+1);
    init_matrix(memo, length1+1, length2+1, NOT_FILLED);
    int lcs_length = lcs_top_rec(memo, str1, str2, length1, length2);
    printf("Top-down: Length of lcs of '%s' and '%s' = %d\n", str1, str2, lcs_length);

    lcs_display(memo, str1, str2, length1, length2);

    destroy_matrix(memo, length1);
    return lcs_length;
}

int lcs_bottom_up(char str1[], char str2[],int length1,int length2) {
     int memo[length1+1][length2+1]; 
     int i, j; 
   
   for (i=0; i<=length1; i++) 
   { 
     for (j=0; j<=length2; j++) 
     { 
       if (i == 0 || j == 0) 
         memo[i][j] = 0; 
   
       else if (str1[i-1] == str2[j-1]) 
         memo[i][j] = memo[i-1][j-1] + 1; 
   
       else{
           if (memo[i-1][j] > memo[i][j-1])
                memo[i][j] = memo[i-1][j];
            else
            {
                memo[i][j] =  memo[i][j-1];
            }
       }
     } 
   }
   return memo[length1][length2]; 
}
int main() {
    lcs_top(str1, str2);
    int length1 = str_length(str1);
    int length2 = str_length(str2);
    printf("Bottom-up: Length of lcs of %s and %s = %d\n", str1, str2, lcs_bottom_up(str1, str2, length1, length2));

    return 0;
}


