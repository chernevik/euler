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
    int i=0, val, factors_ndx=0, dividend, j=0, df_val;

    if (is_prime(n)) {
        factors[factors_ndx] = n;
        return factors;
    }

    primes = list_primes(n);
    // debug shows that at some point, values in primes are reset to lots and lots of 2s

    while ( ( val = primes[i] ) != -1 ) {
        if ( n % val == 0 ) {
            factors[factors_ndx] = val;
            factors_ndx++;
            dividend = n / val;
            if (!is_prime(dividend)) {
                // segfault before this
                dividend_factors = factorize(dividend);
                while ( ( df_val = dividend_factors[j] ) != -1 ) {
                    // gdb says we're segfaulting here
                    // value of factors_ndx is crazy high -- 258648, why so high?
                    // MANY more values in array primes than expected -- array 100 has value
                    // all values in primes seem to be 2
                    // is there some problem with list_primes?
                    factors[factors_ndx] = val;
                    factors_ndx++;
                    j++;
                }
            } else {
                factors[factors_ndx] = dividend;
                factors_ndx++;
            }
        }
        i++;
    }
    factors[factors_ndx] = -1;
    // segmentation fault seems to happen here.  why?
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
