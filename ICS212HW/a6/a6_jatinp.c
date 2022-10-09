/**
 * Output numbers from 1 - 9999 in spanish.
 * @author Jatin P
 * @since 2/01/2019
 */
// Taken abit from https://cboard.cprogramming.com/c-programming
// /112410-program-reads-number-between-1-999-spells-english.html
#include <stdio.h>
#define LIMIT 10000
int main (void) 
{
    puts("This program will print numbers 1 - 9999 in Spanish"); 
    for (int i = 1; i < LIMIT; i++)
    {
        printf("%i = ", i);
        int oP = 0;
        int tP = 0;
        int hP = 0;
        int thP = 0;

        thP = i / 1000;
        hP = (i - (thP * 1000)) / 100;
        tP = (i - (thP * 1000) - (hP * 100)) / 10;
        oP = i - (thP * 1000) - (hP * 100) - (tP * 10);

        if (thP > 0) 
        {
             if (thP == 9) printf("Nueve");
             else if (thP == 8) printf("Ocho");
             else if (thP == 7) printf("Siete");
             else if (thP == 6) printf("Seis");
             else if (thP == 5) printf("Cinco");
             else if (thP == 4) printf("Cuatro");
             else if (thP == 3) printf("Tres");
             else if (thP == 2) printf("Dos");
             printf(" Mil ");
        }

        if (hP > 0) 
        {
            if (hP == 9) printf("novecientos ");
            else if (hP == 8) printf ("ochocientos ");
            else if (hP == 7) printf ("setecientos ");
            else if (hP == 6) printf ("seiscientos ");
            else if (hP == 5) printf ("quinientos ");
            else if (hP == 4) printf ("cuatrocientos ");
            else if (hP == 3) printf ("trescientos ");
            else if (hP == 2) printf ("doscientos ");
            else printf("cien ");

        }

       int b =  (i - (thP * 1000) - (hP * 100));
        if (b == 11 || i == 11)
        {
            printf("once\n");
            continue;
        }
         if (b == 12 || i == 12)
         {
             printf("doce\n");
             continue;
         }
         if (b == 13 || i == 13)
         {
             printf("trece\n");
             continue;
         }
         if (b == 14 || i == 14)
         {
             printf("catorce\n");
             continue;
         }
         if (b == 15 || i == 15)
         {
             printf ("quince\n");
             continue;
         }
         if (b == 10 || i == 10)
         {
             printf ("diez\n");
             continue;
         }

         if (tP > 0)
         {
             if (tP == 9) printf ("noventa ");
             else if (tP == 8) printf ("ochenta ");
             else if (tP == 7) printf ("setenta ");
             else if (tP == 6) printf ("sesenta ");
             else if (tP == 5) printf ("cincuenta ");
             else if (tP == 4) printf ("cuarenta ");
             else if (tP == 3) printf ("treinta ");
             else if (tP == 2) printf ("veinte ");
             else printf ("deci ");
         }

         if (oP > 0)
         {
             if (oP == 9) printf ("nueve");
             else if (oP == 8) printf("ocho");
             else if (oP == 7) printf ("siete");
             else if (oP == 6) printf ("seis");
             else if (oP == 5) printf ("cinco");
             else if (oP == 4) printf ("cuatro");
             else if (oP == 3) printf ("tres");
             else if (oP == 2) printf ("dos");
             else printf ("uno");

         }
    printf("\n");
 }
    return 0;
}
