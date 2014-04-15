/*--------------------------------------------------------------------------*/
/*
    Provides library of functions written while solving Project Euler problems

 */
/*--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/*--------------------------------------------------------------------------*/
#define TRUE 1
#define FALSE 0

typedef int Bool;


Bool is_prime(int n) 
/* 
    Tests whether << n >> is prime
 */
{

    int divisor;

    if (n <= 1) return FALSE;
    for (divisor = 2; divisor * divisor <= n; divisor++)
    {
        if (n % divisor == 0) 
        {
            return FALSE;
        }
    }
    return TRUE;
}


/*--------------------------------------------------------------------------*/
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

    /*
        PROBLEM
        How to revise this to return an array holding only the primes, and not ending on -1

        DRAFT CODE

        int new_array_size = pl_ndx;    // if the prior array holds 3 elements, its last index will be 2, while the new array must be size 3 to hold all the elements including the -1.  So the new array must be size 2 to hold all elements but the -1.

        int *new_list = calloc(new_array_size, sizeof(int));

        for ( i = 0; i < new_array_size; i++ ) {   
            new_list[i] = prime_list[i];
        }

     */

}


/*--------------------------------------------------------------------------*/
long int next_prime(long int n)
/*
    Returns the next prime number after n.

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

/*--------------------------------------------------------------------------*/
int *factorize(long n)
/*
    Returns pointer to array of prime factors of n.

    Array ends with -1.

 */
{
    int *primes;
    int *dividend_factors;
    int *factors = calloc(n, sizeof(int));
    int i=0, factors_ndx=0, j=0, df_val;
    long int dividend=0;

    if (is_prime(n)) {
        factors[factors_ndx++] = n;
        factors[factors_ndx] = -1;
        return factors;
    }

    /*
     */

    long int val = 1;
    while ( ( val = next_prime(val) ) != -1 && !dividend ) {
        if ( n % val == 0 ) {
            factors[factors_ndx++] = val;
            dividend = n / val;
            if (!is_prime(dividend)) {
                dividend_factors = factorize(dividend);
                while ( ( df_val = dividend_factors[j++] ) != -1 ) {
                    factors[factors_ndx++] = df_val;
                }
            } else {
                factors[factors_ndx++] = dividend;
            }
        }
    }
    factors[factors_ndx] = -1;

    // add back check on factors
    // add -- somewhere -- check to get maximum value

    long int check_val = 1;
    int k = 0;
    while ( ( val = factors[k++] ) != -1 ) {
        check_val = check_val * val;
    }
    if ( check_val != n ) {
        // weed: provide better error handling here?
        printf("ERROR\n");
        printf("%ld is not equal to \n", check_val);
        printf("%ld", n);
    }

    return factors;

}


/*--------------------------------------------------------------------------*/
long int max(int *ry)
/*
    Returns value of largest element in array.
    - Presumes array ends with -1
 */
{
    int i = 0;
    long int val=0, max=0;

    while ( ( val = ry[i++] ) != -1 ) {
        if ( val > max ) {
            max = val;
        }
    }

    return max;

}

/*--------------------------------------------------------------------------*/
