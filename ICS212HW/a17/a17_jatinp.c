/**
 * Editing files.
 * @author Jatin Pandya
 * @since 3/20/2019
 */

#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "getdouble.h"
#include "stringinput.h"

// Function prototypes
// Prints students out.
void printStudent(Student);
// Function that makes changes to records.
Student makeChanges (Student);

int main (void) {
    Student studentX = {-1, "", "", 0, 0.0 };
    Student studentArray[MAX_RECORDS] = {-1, "", "", 0, 0.0 };
    FILE *filePointer = NULL;    
    char *fileName = "students.dat";
    int fileClosed = 0;  
    int seekError = 0;
    int writeError = 0;
    int endLoop = 0;
    char dummyString[MAX_STRING] = {'\0'};
    int i = 0;
    int firstR = 0;
    int readError = 0;
    int record = 0;
    int eLoop = 0;

    filePointer = fopen(fileName,"rb+");

    if (filePointer == NULL) {
         printf("File \"%s\" could not be opened. \n", fileName); 
         exit(1); //end the program
     }
    
  while(0 == feof(filePointer)){
      readError = fread(&studentX,sizeof(Student),1,filePointer);
      if(1 == readError){
          if(-1 != studentArray[i].number){
              studentArray[i] = studentX;
          }
      }
      i++;
  }
  while (endLoop != 1) {
      printf("\nNumber  FirstName  LastName  Age  GPA  \n"); 
      printf("------  ---------  --------  ---  ---  \n");
      
      for(i=0;i<MAX_RECORDS;i++){
          if(-1 != studentArray[i].number){  
              printStudent(studentArray[i]); 
          }
      }
      if (firstR == 0) {
          while (eLoop != 1) {
              puts ("Please enter the record number you wish to edit: ");
              record = getdouble();
              if (record > 20) {
                  puts ("ERROR: No records 20 or above exist!");
              } else if (record < 0) {
                  puts ("ERROR: No records below 0 exist!");
              } else {
                  if (studentArray[record].number == -1) {
                      printf ("ERROR: Record %i does not exist\n",record);
                      continue;
                  } else {
                      eLoop = 1;
                      studentX = studentArray[record];
                      seekError = fseek(filePointer,(studentArray[record].number)*sizeof(Student), SEEK_SET);
                      studentArray[record] = makeChanges(studentArray[record]);
                      studentX = studentArray[record];
                      writeError = fwrite(&studentArray[record],sizeof(Student),1,filePointer);
                  }
              }
          }
          firstR = 1;
      }
      else {
          char check = 'A';
          puts ("Keep editing records? Yes(y) or No(n)?");
          check = getchar();
          getchar();
          eLoop = 0;
          while (eLoop != 1) {
              if (check == 'y') {
                  eLoop = 1;
                  int eLoop2 = 0;
                  while (eLoop2 != 1)  {
                      puts ("Enter the record number you wish to edit:");
                      record = getdouble();
                      if (record > 20) {
                          puts ("ERROR: No records 20 or above exist!");
                      } else if (record < 0) {
                          puts ("ERROR: No records below 0 exist");
                      } else {
                          eLoop2 = 1;
                          if (studentArray[record].number == -1) {
                              printf ("ERROR: Record %i does not exist\n", record);
                              continue;
                          } else {
                              studentX = studentArray[record];
                              seekError = fseek(filePointer,(studentArray[record].number)*sizeof(Student), SEEK_SET);
                              studentArray[record] = makeChanges(studentArray[record]);
                              studentX = studentArray[record];
                              writeError = fwrite(&studentArray[record],sizeof(Student),1,filePointer);
                          }
                      }
                  }
                 } else if (check == 'n') {
                     puts ("The file \"students.dat\" was successfully updated.");
                     endLoop = 1; 
                     break;
                 } else {
                     puts ("Please enter only y or n");
                 }
             }
        }
  }
    fileClosed = fclose(filePointer);
    if(0 == fileClosed){
        printf("File connection to \"%s\" closed successfully.\n", fileName);
    }//end of if
    else{
        printf("File connection to \"%s\" did NOT close successfully.\n", fileName);
    }//end of else
return 0;
}

/**
 * Makes changes to array.
 * @args studentX is the record being changed.
 */
Student makeChanges (Student studentX) {
    char selection = 'A';
    int eLoop = 0;
    puts ("You have selected: ");
    printStudent(studentX);
    while (eLoop != 1) {
        puts ("Do you wish to edit first name (f), last name (l), age (a), or gpa (g)?");
        selection = getchar();
        getchar();
        switch (selection) {
            case 'f': 
                puts ("Enter First Name: ");
                eLoop = 1;
                getstring(studentX.first, MAX_STRING);
                printf ("\n");
                break;
            case 'l':
                puts ("Enter Last Name: ");
                eLoop = 1;
                getstring(studentX.last, MAX_STRING);
                printf ("\n");
                break;
            case 'a':
                puts ("Enter Age: ");
                eLoop = 1;
                studentX.age = getdouble();
                printf ("\n");
                break;
            case 'g':
                puts ("Enter gpa: ");
                eLoop = 1;
                studentX.gpa = getdouble();
                printf ("\n");
                break;
            default:
                puts ("Please enter a valid choice!");
                printf ("You entered: %c\n", selection);
        }
    }
    return studentX;
}
void printStudent(Student studentX){
    printf("%6d  %10s  %10s  %3d  %3.1f  \n", 
            studentX.number, 
            studentX.first, 
            studentX.last, 
            studentX.age, 
            studentX.gpa);
}
