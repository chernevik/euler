#include "generate_primes.c"

//#define TARGET   13195
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
    int i=0, val, factors_ndx=0, dividend=0, j=0, df_val;

    if (is_prime(n)) {
        factors[factors_ndx++] = n;
        factors[factors_ndx] = -1;
        return factors;
    }

    // this generates a lot of primes that aren't used -- costly
    // revise to define and use a function that returns the next prime number?
    primes = list_primes(n/2);

    while ( ( val = primes[i++] ) != -1 && !dividend ) {
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
    - could use back-check -- does multiplication of factors return n?

    BUT
    - segfaults on problem #3 target value
        - segfault resolved by specifying long int for arguments of is_prime, factorize
        - still slow
    - very slow

 */
