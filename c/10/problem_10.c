/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

ANSWER: 142913828922

 */


#include <stdio.h>

#include "../euler.c"

int main(int argc, char *argv[]) 
{

    long int n = atoi(argv[1]);
    //-long int n = TARGET;
    long int prime_sum, prime=1;

    while ( ( prime = next_prime(prime) ) <= n ) {
        prime_sum += prime;
    }

    printf("%ld\n", prime_sum);

    return 0;
}
