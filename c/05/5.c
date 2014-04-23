/*
    Brute force solution to Euler problem 5

    answer is 232792560 (for value 20)

 */


#include <stdio.h>
#include <stdlib.h>

#define TARGET 20
//-#define TARGET 10

int main ()
{
    int n = TARGET;
    long int i, j;
    int divisible = 0;

    for ( i=1; divisible != 1; i++ ) {
        divisible = 1;
        for ( j=1; j <= n; j++ ) {
            if ( i % j != 0 ) {
                divisible = 0;
                break;
            }
        }
    }

    printf("%ld\n", i-1);
    return 0;
}
