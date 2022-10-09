#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int perfectSquares(int n);

void main()
{
int n=12;
printf("n=%d: perfect squares = %d\n", n, perfectSquares(n));
n=13;
printf("n=%d: perfect squares = %d\n", n, perfectSquares(n));
n=500;
printf("n=%d: perfect squares = %d\n", n, perfectSquares(n));
n=724;
printf("n=%d: perfect squares = %d\n", n, perfectSquares(n));
return;
}


int perfectSquares(int n)
{
    while (n % 4 == 0) n = n/4;

    if (n % 8 == 7) return 4;

    for (int i = 0; i * i <= n; i++) 
    {
        int temp = sqrt(n - i * i);

        if (i * i + temp * temp == n){
            if (i != 0) return 1 + 1;
            else return 1 + 0;
        } 
    }
    return 3;

   
}