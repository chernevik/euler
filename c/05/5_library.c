/*
    Uses Euler library to solve Problem #5

    STATUS:
        
        compiles
        prints candidate 1 (clearly wrong), fails on floating point exception: 8
 
 */

#include <stdio.h>
#include <stdlib.h>

#include "../euler.c"

#define TARGET 20
#define ARRAY_SIZE_2 1000

int main ()
{
    int n = TARGET;
    int *primes =           calloc(ARRAY_SIZE_2, sizeof(int));
    int *i_factors =        calloc(ARRAY_SIZE_2, sizeof(int));
    int *unique_factors =   calloc(ARRAY_SIZE_2, sizeof(int));
    int *factor_set =       calloc(ARRAY_SIZE_2, sizeof(int));
    int prod = 1;
    int val, i=0, fs_ndx=0, j;
    int prodcopy = prod;
    int divisible;


    primes = factorize(n);

    // get array of factors of numbers less than n
    for ( i=2; i <= n; i++ ) {
        i_factors = factorize(i);
        j = 0;
        while  ( (val = i_factors[j++] ) != -1 ) {
            factor_set[fs_ndx++] = val;
        }
    }

    unique_factors = unique(factor_set);

    while ( (val = unique_factors[i++] != -1 ) )  {
        prod = prod *  val;    
    }

    printf("candidate: %d\n", prod);
    for ( ; prodcopy > 0; prodcopy-- ) {
        divisible = 1;
        for ( j = 0; j <= n; j++ ) {
            if ( prodcopy % j != 0 ) {
                divisible = 0;
                break;
            }
        }
        if ( divisible ) {
            prod = prodcopy;
        }
    }

    printf("%d\n", prod);
}
