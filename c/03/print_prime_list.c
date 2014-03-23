/*

PROBLEM:
Print a list returned by a function

MOTIVATION:
- Demonstration basic array usage, return of an array by a function

 */

#include <stdio.h>
#include <stdlib.h>

#include "generate_primes.c"

int* return_list() {
/*
    Demonstrates return of pointer to a list

 */
    int i, j;
    int* ary = malloc(sizeof(int) * 10);

    // initialize array values
    for (i=0; i<10; i++) 
    {
        ary[i] = i * 2;
    }

    return ary;
    // how do i return a pointer to this array?
};

int main() {
    /* prints a list of prime numbers

        STATUS
        segmentation fault
    */

    int *p_ry;
    int j = 0;
    int val;

    p_ry = prime_list(10);
    //-p_ry = return_list();
    while ( p_ry[j] != -1 ) {
        printf("%d\n", p_ry[j]);
        j++;
    }
}
