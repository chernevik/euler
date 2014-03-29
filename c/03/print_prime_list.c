/*

PROBLEM:
Print a list returned by a function

MOTIVATION:
- Demonstration basic array usage, return of an array by a function

 */

#include <stdio.h>
#include <stdlib.h>

#include "generate_primes.c"

int main() {
    /* prints a list of prime numbers

        STATUS
        segmentation fault
    */

    int *p_ry;
    int j = 0;
    int val;

    p_ry = prime_list(10);
    //-fails for 20-p_ry = prime_list(20);
    //-p_ry = return_list();
    while ( p_ry[j] != -1 ) {
        printf("%d\n", p_ry[j]);
        j++;
    }
}

