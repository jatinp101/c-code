/*
Example of C language streams 
stdin: standard input stream to keyboard 
stdout: standard output stream to screen 
stderr: standard error stream to screen 
fgetc(): reads one character at a time from a file
fputc(): writes one character at a time to a file
*/
#include <stdio.h>

int main(){
 //initialize variables
   char character1 = '\0';
   char character2 = '\0';
   int error = 0;
   
   //prompt user and get character input
   fprintf(stdout, "Enter a character: "); 
   character1 = fgetc(stdin); //same as getchar()
   if(EOF == character1){
     printf("Error occured for 1st character inputted!\n"); 
   }
   character2 = getchar(); //get the newline character '\n'
   if(EOF == character2){
     printf("Error occured for 2nd character inputted!\n");
   }   

   //output
   fprintf(stdout, "\nCharacter is: ");
   error = fputc(character1, stdout); //same as putchar()
   if(EOF == error){
     printf("Error occured for 1st character outputted!\n");
   }
   error = putchar(character1);
   if(EOF == error){
     printf("Error occured for 2nd character outputted!\n");
   }
   fprintf(stdout,"%c",character1); //same as printf()
   printf("%c",character1);
   fprintf(stdout, "\n\n");
   
   //standard error output
   fprintf(stderr, "This is stderr output.\n\n");

   return 0;
}



