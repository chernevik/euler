/* http://projecteuler.net/problem=1

PROBLEM
If we list all the natural numbers below 10 that are multiples of 3 or 5, we
get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

ANSWER
233168

*/

#include <stdio.h>

/*
    I'm sure this is very clever, but it is hard to read
 */

int sum_divisibles()
{
    int ndx, mult_3, mult_5, sum = 0,  LIMIT = 1000;
    while ( ( mult_3 = ++ndx * 3 ) < LIMIT ) {
        sum += mult_3 + ( ( mult_5 = ndx * 5 ) < LIMIT && mult_5 % 3 != 0 ) * mult_5;
    };
    return sum;


    /*
        How is works:
        - loop goes through multiples of 3 less than LIMIT
        - that multiple is added to sum, plus
        - the ndx value times 5 if that multiple is less than the limit and that multiple isn't divisible by 3

        Note that the logic test checking mult_5 against limit and divisibility returns 1 if true and 0 if not.  So that expression assigns a value to mult_5, checks that value for limit and divisibility by three, and multiplies that value by the 1 or 0 returned by the logic test.

     */
}

main()
{
    printf("%d\n", sum_divisibles() );
}


/*
    loop breaking from inside a switch:
    http://stackoverflow.com/questions/1420029/how-to-break-out-of-a-loop-from-inside-a-switch

    Extend to arbitrary divisors by breaking up the incrementing of << sum >>,
    putting incrementing for larger divisors in a loop through those larger
    divisors.  
    -   But then how to incorporate the logic check on duplication?  
    -   That isn't hard if the code abandons the one liner and puts that logic
        check in a loop.

 */

