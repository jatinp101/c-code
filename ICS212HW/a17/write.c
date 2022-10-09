/*
  Reads from the keyboard, 
  and then writes to a file.
*/
#include <stdio.h>   

int main(){
  /*
    FILE is a structure defined in <stdio.h>.
    Contains data used to process the file.
  */
  FILE *filePointer = NULL;
  char *fileName = "file.txt";
  char character = '\0';
  int fputsError = 0; 
  int fileClosed = 0; 

  //open a connection to a file
  filePointer = fopen(fileName,"w");
  //if error, filePointer is NULL 
  if(filePointer == NULL){
    printf("File could not be opened\n"); 
    exit(1); //end the program
  }//end of else
  else{ 
    /*
      stdin = read from keyboard
      fgetc() = read one character at a time 
    */
    printf("Enter some characters, which will get stored in file \"%s\"\n", fileName);
    printf("Enter EOF (Ctrl-D) to end the loop.\n");
    
    character = fgetc(stdin);
    while(EOF != character){
      /*
	write one character at a time to a file
      */
      fputc(character, filePointer); 
      character = fgetc(stdin);
    }//end of while

    //write a string to the file
    fputsError = fputs("\nWriting a string on the last line of the file!\n", filePointer);
    if(fputsError >= 0){
      printf("String was successfully written to file \"%s\" (#%d).\n", fileName, fputsError);
    }//end of if
    if(EOF == fputsError){
      printf("String was NOT successfully written to file \"%s\".\n", fileName);
    }//end of else 

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

