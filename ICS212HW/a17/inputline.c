/*
Example of safely reading a line from standard input 
by limiting the number of characters.
*/
#include <stdio.h>  
#define MAX 10

int main(){

   char string[MAX] = {'\0'};
   printf("Enter up to %d characters: \n", MAX-1);
   fgets(string, MAX, stdin); 
   printf("You entered: %s \n", string);
   
   return 0;   
} 



