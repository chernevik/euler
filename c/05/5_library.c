/*
    Uses Euler library to solve Problem #5

    STATUS:
        
        compiles
        doesn't generate correct answer for 10
        - approach isn't right
 
 */

#include <stdio.h>
#include <stdlib.h>

#include "../euler.c"

#define TARGET 10
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
    int prodcopy;
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

    factor_set[fs_ndx] = -1;
    unique_factors = unique(factor_set);

    // see what's in factor_set
    i = 0;
    while ( ( val = factor_set[i++] ) != -1 ) {
        printf("fs: %d\n", val);
    }

    i = 0;
    while ( (val = unique_factors[i++] ) != -1  )  {
        printf("val: %d\n", val);
        prod = prod *  val;    
    }

    //-printf("candidate: %d\n", prod);
    for ( prodcopy = prod; prodcopy > 0; prodcopy-- ) {
        //-printf("prodcopy: %d\n", prodcopy);
        divisible = 1;
        for ( j = 1; j <= n; j++ ) {
            //-printf("j:%d\n", j);
            if ( prodcopy % j != 0 ) {
                divisible = 0;
                //-break;
            }
        }
        if ( divisible == 1 ) {
            //-printf("nc: %d\n", prodcopy);
            prod = prodcopy;
        }
    }

    printf("%d\n", prod);
}
