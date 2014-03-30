#include <stdio.h>

#include "generate_primes.c"

#define TARGET 117 

int main()
{
    printf("next prime is %ld\n", next_prime(TARGET));
}
