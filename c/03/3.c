/*--------------------------------------------------------------------------*/
/*

    Complete code implementing solution for Project Euler Problem #3

 */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#define TARGET 600851475143


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

    long int val = 1;
    while ( !dividend ) {
        val = next_prime(val);
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

    // back check on factors
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
int main()
/*
    Outputs list_primes() contents.

 */
{
    int *prime_list;    
    int j = 0;
    int val;

    prime_list = factorize(TARGET);
    printf("%ld\n", max(prime_list));
}


/*--------------------------------------------------------------------------*/
