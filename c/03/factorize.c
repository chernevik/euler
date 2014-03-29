#include "generate_primes.c"


int *factorize(n)
/*
    Returns pointer to array of prime factors of n.

    Array ends with -1.

 */
{
    printf("ENTER factorize(), for %d\n", n);

    int *primes;
    int *dividend_factors;
    int *factors = calloc(n, sizeof(int));
    int i=0, val, factors_ndx=0, dividend, j=0, df_val;

    primes = list_primes(n/2);

    while ( ( val = primes[i] ) != -1 ) {
        printf("val is %d\n", val);
        if ( n % val == 0 ) {
            factors[factors_ndx] = val;
            factors_ndx++;
            dividend = n / val;
            if (!is_prime(dividend)) {
                // segfault before this
                printf("no segfault yet\n");
                dividend_factors = factorize(dividend);
                while ( ( df_val = dividend_factors[j] ) != -1 ) {
                    factors[factors_ndx] = val;
                    factors_ndx++;
                }
            }
        }
        i++;
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

    prime_list = factorize(20);
    //-prime_list = list_primes(20);
    while ( ( val = prime_list[j] ) != -1 ) {
        printf("%d\n", val);
        j++;
    }
}


/*
    STATUS

    generating segmentation fault: 11 when factorizing
 */
