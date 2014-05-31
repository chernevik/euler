#include "generate_primes.c"

//-#define TARGET   13195
//-#define TARGET 600000000
#define TARGET 600851475143
//- 600,851,475,143


int *factorize(long int n)
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

    - not compiling properly on Volundr, does compile on Thorin
        - differences in size of number handled by long int?

 */
