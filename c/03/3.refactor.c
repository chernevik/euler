/*----------------------------------------------------------------------------

STATUS
- compiles
- program returns segmentation fault on execution


REFACTORS AWAY FROM USE OF -1 TO SIGNAL END OF ARRAY
- Actually, the way to do this is with unit tests
- This refactor is not tenable.  The idea was to get the size of an array,
  pointed to by a pointer, with the sizeof operator.  But Stack Overflow states
  that the size of these arrays is not available, and that either their size
  must be stashed somewhere, or the end of the array values signalled by an out
  of range value (such as the -1 value used in the present code).  So this
  refactor will be abandoned.


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
? WHEN DOES THIS PROCESS STOP? -- if the dividend is prime, we're done


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

//-#define TARGET 21
//-#define TARGET 35
#define TARGET 105
//-#define TARGET 377
//-#define TARGET 13195
//-#define TARGET 600851475143

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

    // resize array
    int *new_ry = calloc(pl_ndx, sizeof(int));
    for ( i=0; i<pl_ndx; i++) {
        new_ry[i] = prime_list[i];
    }

    return new_ry;

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


int *factorize(long n)
/*
    Returns pointer to array of prime factors of n.

 */
{
    printf("factorize %ld\n", n);

    int *dividend_factors;
    long int *factors = calloc(n, sizeof(long int));
    int i=0, factors_ndx=0, j=0, k;
    long int df_val;
    long int dividend=0;

    if (is_prime(n)) {
        factors[factors_ndx++] = n;
        int *new_ry = calloc(1, sizeof(long int));
        new_ry[0] = n;
        return new_ry;
    }

    long int val = 1;
    //-while ( !is_prime(dividend) ) {
    while ( !dividend ) {
        val = next_prime(val);
        if ( n % val == 0 ) {
            factors[factors_ndx++] = val;
            dividend = n / val;
            if (!is_prime(dividend)) {
                dividend_factors = factorize(dividend);
                for ( k=0; k < sizeof(dividend_factors) / sizeof(dividend_factors[0]); k++ ) {
                    factors[factors_ndx++] = dividend_factors[k];
                }
            } else {
                factors[factors_ndx++] = dividend;
            }
        }
    }

    // weed: this array initialization doesn't seem to be creating an array of the proper size
    // is new_ry a pointer?  or an array?
    // how to attack this?  maybe right simple dumb code on array and pointer creation so I can lock down those concepts?
    int *new_ry = calloc(factors_ndx + 1, sizeof(long int));
    for ( j=0; j < factors_ndx; j++ ) {
    //-for ( j=0; j < (sizeof(factors) / sizeof(factors[0])); j++ ) {
        new_ry[j] = factors[j];
    }

    long int check_val = 1;
    /*
        check is failing bc sizeof new_ry is 8, of [0] is 4, so loop only goes through 2 array elements.  BUT there is a third array element, [2] has value 7.  So the array seems okay, but the idiom here isn't working
     */
    for ( k = 0; k < (sizeof(new_ry) / sizeof(new_ry[0])); k++) {
        val = new_ry[k];
        check_val = check_val * val;
    }
    if ( check_val != n ) {
        // weed: provide better error handling here?
        printf("ERROR factoring %ld\n", n);
        printf("%ld is not equal to \n", check_val);
        printf("%ld\n", n);
        printf("last val: %ld\n", val);
        for ( k = 0; k < (sizeof(new_ry) / sizeof(new_ry[0])); k++) {
            printf("%d\n", new_ry[k]);
        }
        exit(1);

    }

    return new_ry;

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

    int ry_size = sizeof(ry) / sizeof(ry[0]);
    for ( i=0; i < ry_size; i++ ) {
        val = ry[i];
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
    /*
    for ( j = 0; j < sizeof(prime_list) / sizeof(prime_list[0]); j++ ) {
        printf("%d\n", prime_list[0]);
    }
     */

    printf("%ld\n", max(prime_list));

    return 0;   // successful bash functions return 0
}


