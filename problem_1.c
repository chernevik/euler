#include <stdio.h>

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

 */

/*  Answer: 233168 */

int sum_divisibles()
{
    int ndx, sum = 0;  int LIMIT = 1000;
    while ( ++ndx < LIMIT ) {
        if ( !( ndx % 3 ) || !( ndx % 5 ) ) {
            sum += ndx ;
        };
    };
    return sum;
}

main()
{
    printf("%d\n", sum_divisibles() );
}

