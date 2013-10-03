#include <stdio.h>

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

 */

/*  Answer: 233168 */

/*
    Complaints:

    Any way to reduce the number of duplicative multiplication operations?

 */

int sum_divisibles()
{
    int ndx, sum = 0;  int LIMIT = 1000;
    while ( ++ndx ) {
        if ( ndx * 3 < LIMIT ) {
            sum += ndx * 3 ;
            if ( ndx * 5 < LIMIT && ( ndx * 5 ) % 3 != 0 ) {
                sum += ndx * 5 ;
            }
        } else {
            break;
        }
    };
    return sum;
}

main()
{
    printf("%d\n", sum_divisibles() );
}

