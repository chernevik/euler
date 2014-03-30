#include "generate_primes.c"


int *factorize(n)
/*
    Returns pointer to array of prime factors of n.

    Array ends with -1.

 */
{

    int *primes;
    int *dividend_factors;
    int *factors = calloc(n, sizeof(int));
    int i=0, val, factors_ndx=0, dividend=0, j=0, df_val;

    if (is_prime(n)) {
        factors[factors_ndx++] = n;
        factors[factors_ndx] = -1;
        return factors;
    }

    primes = list_primes(n);

    while ( ( val = primes[i++] ) != -1 && !dividend ) {
        if ( n % val == 0 ) {
            factors[factors_ndx++] = val;
            dividend = n / val;
            if (!is_prime(dividend)) {
                dividend_factors = factorize(dividend);
                while ( ( df_val = dividend_factors[j++] ) != -1 ) {
                    factors[factors_ndx++] = val;
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

    prime_list = factorize(20);
    //-prime_list = list_primes(20);

    while ( ( val = prime_list[j] ) != -1 ) {
        printf("%d\n", val);
        j++;
    }
}


/*
    STATUS

    segmentation fault issue fixed (had a runaway loop)
    now printing out prime factors of 20, but too many of them
    - now printing out the right number of prime factors for 20, but not printing 5
        - getting 2, 2, 2, instead of 2, 2, 5

 */
