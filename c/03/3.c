/*----------------------------------------------------------------------------

Provides list of prime factors of TARGET value.
- Answers Project Euler #3

STATUS
- Solves problem on Thorin
- FAILS on Volundr
    - probably the target value is larger than can be held by long int on Volundr
        - am I sure that it isn't on Thorin?
    - If so, probably fixed by using type float (yes?) rather than long int


TODO:
- Revise to work on Volundr, dwarf, gloin
- Add function finding maximum value in an array
- Review and clean code
- Review and prune other files
- Copy core functions to an 'euler library', write solution drawing from that library
- Add unit tests?

NOTES
- For all arrays returned, end of intended values is marked with -1
- Is there a way to find end of arrays without using the -1 convention used here?


PROBLEM:

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?


PRIME FACTORIZATION PROCESS 
- Divide target number by prime numbers, greater than 1, in increasing
  sequence, until reaching a prime that divides the target evenly.
    - This prime is a factor of the target
    - The number of times that prime divides into the target, I term 'the
      dividend'
- If the dividend is not itself prime, find the prime factors of the dividend.
  Each of these is a prime factor of the target.
- If the dividend is itself prime, the dividend is a prime factor of the number. 


TO CHECK A NUMBER FOR PRIME
- Check all integers whose square is less than the number for a remainder,
  using the modulus operation.  If any have no remainder, the number is
  divisible by that integer, and is not prime.
- Algorithm taken from King.
- Don't know why integer square less than the number is the right limit --
  figure that out

----------------------------------------------------------------------------*/



#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define TARGET 600851475143

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
//- 600,851,475,143


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

    // this generates a lot of primes that aren't used -- costly
    // revise to define and use a function that returns the next prime number?

    /*
        How to revise this to use next_prime(), rather than generating a long
        list of primes?
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


