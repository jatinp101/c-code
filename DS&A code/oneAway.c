#include <stdlib.h>
#include <stdio.h>

#define MAXLENGTH 100  /* Max length of a string */

int one_away(char str1[], char str2[]);
int str_length(char str[], int max_length);

char str[] = "pale";
char strA[] = "ple";
char strB[] = "pales";
char strC[] = "bale";
char strD[] = "bake";


void main() 
{
printf("'%s' and '%s' have result %d\n", str, strA, one_away(str, strA));
printf("'%s' and '%s' have result %d\n", str, strB, one_away(str, strB));
printf("'%s' and '%s' have result %d\n", str, strC, one_away(str, strC));
printf("'%s' and '%s' have result %d\n", str, strD, one_away(str, strD));
}


int one_away(char str1[], char str2[])
{
    int i = 0;
    int j = 0;
    int total = 0;
    while ((str1[i] != NULL) && (str2[j] != NULL)) {
        if (str1[i] == str2[j]) {
            i++;
            j++;
            continue;
        }
        if (str1[i+1] == str2[j]) {
            total++;
            i += 2;
            j++;
            continue;
        }
        total++;
        i++;
        j++;
    }
    if (str2[j] != 0) {
        total++;
    }
    if (total > 1){
        return 0;
    } else{
        return total;
    }
}



int str_length(char str[], int max_length)
{
int length;
for (length = 0; (str[length] != '\0') && (length < max_length); length++); 
return length;
}


