/*

PROBLEM
The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

Let us list the factors of the first seven triangle numbers:

 1: 1
 3: 1,3
 6: 1,2,3,6
10: 1,2,5,10
15: 1,3,5,15
21: 1,3,7,21
28: 1,2,4,7,14,28

We can see that 28 is the first triangle number to have over five divisors.

What is the value of the first triangle number to have OVER five hundred divisors?

ANSWER
76576500


 */


#include <stdio.h>
#include <stdlib.h>

#include "../euler.c"

long triangular(tri, n)
/*
    Returns triangular number n, given the prior triangular number
 */
{
    return tri + n;
}

int *list_factors(long int n)
/*
 Returns a pointer to an array of the factors of n.
 */
{
    int *factors = calloc(1000, sizeof(long int));
    long int i, cap;
    int j=0;

    cap = n;

    for ( i=1; i <= cap; i++ ) {
        if ( n % i == 0 ) {
            factors[j++] = i;
            factors[j++] = n / i;   // add reciprocal factor of i to factors
            cap = n / i - 1;        
                // reset value of cap to reciprocal less one, as reciprocal is
                // added to factors and no other factor will be greater than
                // that reciprocal
        }
    }

    factors[j] = -1;

    return factors;
}


int main ()
{
    int i = 1;
    int *factors;
    int factors_count, tri = 0;

    factors = list_factors(1);

    while ( (factors_count = size_ry(factors)) <= 500 ) {
        tri = triangular(tri, i++);
        factors = list_factors(tri);
    }

    printf("Answer: %d\n", tri);

}
