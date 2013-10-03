/* http://projecteuler.net/problem=1

If we list all the natural numbers below 10 that are multiples of 3 or 5, we
get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

Answer: 233168

*/

#include <stdio.h>

int sum_divisibles()
{
    int ndx, mult_3, mult_5, sum = 0,  LIMIT = 1000;
    while ( ( mult_3 = ++ndx * 3 ) < LIMIT ) {
        sum += mult_3 + ( ( mult_5 = ndx * 5 ) < LIMIT && mult_5 % 3 != 0 ) * mult_5;
    };
    return sum;
}

main()
{
    printf("%d\n", sum_divisibles() );
}


/*
    loop breaking from inside a switch:
    http://stackoverflow.com/questions/1420029/how-to-break-out-of-a-loop-from-inside-a-switch

 */

