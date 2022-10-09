/*
  Example of reading from a file
*/
#include <stdio.h>  
#include <stdlib.h>

int main(){
  /*
    FILE is a structure defined in <stdio.h>.
    Contains data used to process the file.
  */
  FILE *filePointer = NULL;
  char *fileName = "file.txt";
  char character = '\0';
  int fileClosed = 0; 
  
  //open a connection to a file
  filePointer = fopen(fileName,"r");
  //if error, filePointer is NULL 
  if(filePointer == NULL){
    printf("File could not be opened\n"); 
    exit(1); //end the program
  }//end of if          
  else{
    //read one character from the file
    character = fgetc(filePointer);
    //keep reading while not end of file
    while(0 == feof(filePointer)){
      fputc(character, stdout);  /*screen output*/
      //read one character from the file
      character = fgetc(filePointer);
    }//end of while
    
    printf("\nRead from the file again: \n");
    //re-read the file
    rewind(filePointer);
    //read one character from the file             
    character = fgetc(filePointer);
    //keep reading while not end of file                
    while(0 == feof(filePointer)){
      fputc(character, stdout);  /*screen output*/
      //read one character from the file          
      character = fgetc(filePointer);
    }//end of while 
    
    //close the file connection
    fileClosed = fclose(filePointer);
    if(0 == fileClosed){
      printf("File connection to \"%s\" closed successfully.\n", fileName);
    }//end of if
    else{
      printf("File connection to \"%s\" did NOT close successfully.\n", fileName);
    }//end of else
  }//end of else
  
  return 0;   
} 





