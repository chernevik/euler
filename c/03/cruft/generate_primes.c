/*  Supports generation of a list of prime numbers  */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Bool;


Bool is_prime(int n) 
/* 
    Tests whether << n >> is prime
 */
{
//-1-    printf("entering is_prime for %d\n", n);

    int divisor;

    if (n <= 1) return FALSE;
    for (divisor = 2; divisor * divisor <= n; divisor++)
    {
        if (n % divisor == 0) 
        {
//-1-            printf("leaving false\n");
            return FALSE;
        }
    }
//-1-    printf("leaving true \n");
    return TRUE;
}


int *list_primes(long int n)
/*
    Returns a pointer to an array of all primes less than equal to n.

    Array ends on -1.

 */
{
    // initialize point to array full of zeroes
    int *prime_list = calloc(n, sizeof(int));
    int pl_ndx = 0;

    int i;

    for ( i = 0; i <= n; i++ ) {
        if ( is_prime(i) ) {
            prime_list[pl_ndx] = i;
            pl_ndx++;
        }
    }

    prime_list[pl_ndx] = -1;

    return prime_list;

}


long int next_prime(long int n)
/*
    Returns the next prime number after n.

    STATUS Not working.

 */
{
    long int j = n;
    for (j = n+1; !is_prime(j); j++ ) {
    }

    // check
    if (!is_prime(j)) {
        printf("%ld is not a prime -- ERROR", j);
    }
    return j;
}

