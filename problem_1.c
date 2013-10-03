#include <stdio.h>

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

 */

/*  Answer: 233168 */

int sum_divisibles()
{
    int ndx, sum = 0;  int LIMIT = 1000; int mult_3, mult_5;
    while ( ++ndx ) {
        if ( ( mult_3 = ndx * 3 ) < LIMIT ) {
            sum += mult_3;
            if ( ( mult_5 = ndx * 5 ) < LIMIT && mult_5 % 3 != 0 ) {
                sum += mult_5 ;
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

