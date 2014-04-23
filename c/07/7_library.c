/*
    Answers Euler #7

    The 10001 prime is 104743.

 */


#include <stdio.h>
#include "../euler.c"

#define TARGET 10001

int main()
{
    int n = TARGET;
    int i=1;
    long int prime = 1; 


    while ( i++<=n ) {
        prime = next_prime(prime);
    }

/*
    for ( i=1; i<=n; i++) {
        prime = next_prime(prime);
    }
 */

    printf("%ld\n", prime);

    return 0;
}
