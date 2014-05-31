/*
PROBLEM:

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

PRIME FACTORIZATION PROCESS 
- Divide target number by prime numbers, greater than 1, in increasing sequence, until reaching a prime that divides the target evenly.
    - This prime is a factor of the target
    - The number of times that prime divides into the target, I term 'the dividend'
- If the dividend is not itself prime, find the prime factors of the dividend.  Each of these is a prime factor of the target.
- If the dividend is itself prime, the dividend is a prime factor of the number.  (Yes?)

Check a number for prime?
- I don't know of any other way than either consult a list, or do prime factorization until the numer itself emerges in the sequence of primes

CONCEPTUAL REQUIREMENTS
- generate a sequence of primes

 */



/*

PATH:
- write code for generation of list of primes
    - go to generate_primes.c
- learn to include code from one file in another
    - eg, bring prime list function into this file

 */


 
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


//-#define TARGET   13195
//-#define TARGET 600000000
#define TARGET 600851475143
//- 600,851,475,143


int *factorize(long n)
/*
    Returns pointer to array of prime factors of n.

    Array ends with -1.

 */
{
    printf("entering factorize for %ld\n", n);

    int *primes;
    int *dividend_factors;
    int *factors = calloc(n, sizeof(int));
    int i=0, factors_ndx=0, j=0, df_val;
    long int dividend=0;
    //-2-int i=0, factors_ndx=0, dividend=0, j=0, df_val;
    //-1-int i=0, val, factors_ndx=0, dividend=0, j=0, df_val;

    if (is_prime(n)) {
        factors[factors_ndx++] = n;
        factors[factors_ndx] = -1;
        return factors;
    }

    // this generates a lot of primes that aren't used -- costly
    // revise to define and use a function that returns the next prime number?
    //-1-primes = list_primes(n/2);

    /*
        How to revise this to use next_prime(), rather than generating a long
        list of primes?
     */

    long int val = 1;
    while ( ( val = next_prime(val) ) != -1 && !dividend ) {
    //-1-while ( ( val = primes[i++] ) != -1 && !dividend ) {
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
        printf("ERROR\n");
        printf("%ld is not equal to \n", check_val);
        printf("%ld", n);
    }

    return factors;

}



int main()
/*
    Outputs list_primes() contents.

 */
{
    int *prime_list;    
    int j = 0;
    int val;

    prime_list = factorize(TARGET);
    //-prime_list = list_primes(20);

    while ( ( val = prime_list[j] ) != -1 ) {
        printf("%d\n", val);
        j++;
    }
}


/*
    STATUS

    - seems to be working
        gives 2, 2, 5 for 20
        gives 2, 2, 2, 5 for 40

    - has back-check



 */
