#include <stdio.h>

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

 */

/*  ANSWER IS 

    233168

 */

/*
    NOTES

    Can the loops be tightened by assigning the value of the multiplication
    operations to a variable in the if checks?  I thought C offered some way of
    doing that.


    KEY OPTIMIZATION QUESTION

    The two approaches are:
    -   loop all integers under the limit, checking each for divisibility
        -   loops 3x the integers, which means:
        -   More addition operations -- 3x
        -   More divisibility checks on numbers that won't match
        -   per loop: 1 increment, 2 divisibility, 1 lesser than 
        -   per hit: 1 addition
    -   loop all integers until multiplication by the smallest dividend exceeds the limit
        -   loops only those numbers divisible by one of the divisors
        -   substitutes lesser than checks for divisibility checks 
        -   requires an additional divisibility by lesser divisor check to avoid duplication
        -   per loop: 1 increment, 2 lesser than, 1 divisibility 
        -   per hit: 1 addition
        !   BUT this ignores the multiplications of the base integers!


    If lesser than checks are no more expensive than divisibility checks, second approach will be faster
    !   NOT NECESSARILY RIGHT see BUT in notes above
    +   adds 1 check (divisibility) per loop
    -   removes 1 lesser than
    -   removes 2/3 of the loops

 */

/*  WORKS   --  v1
 v1     */
main()
{
    int ndx, sum, LIMIT;
    
    ndx     =   0;  
    sum     =   0;  
    LIMIT   =   1000;

    while ( ++ndx < LIMIT ) {
        //  Note that putting the increment operator ++ before the variable
        //  (e.g., ++ndx) causes it to act before the comparison operation.
        //  Placing it after ('ndx++') causes action after the comparison.  The
        //  latter causes the algorithm to fail, bc it means the value compared
        //  for the loop condition isn't the same as the value used in the
        //  loop.  Thus the last iteration of the loop compares 999 < 1000
        //  (true), but uses 1000 for the loop internals (which the loop
        //  condition is intended to prevent).  

        //  In both cases, the value of variable is the same inside the loop,
        //  as the increment operation occurs after the comparison operation.

        if ( !( ndx % 3 ) || !( ndx % 5 ) ) {
            // works bc % returns 0 if first argument divisible by second, 0 is
            // logical FALSE, so reversal by ! makes it TRUE
            sum += ndx ;
        }
    }

    //  Result
    printf("%d\n", sum );
    //  Check
    printf("%d\n", sum == 233168 );

}

//-w3-  WORKS
//-w3-main()
//-w3-{
//-w3-    int ndx;
//-w3-    int sum     =   0;  
//-w3-    int LIMIT   =   1000;
//-w3-
//-w3-    for ( ndx = 0; ndx < LIMIT; ndx++ ) {
//-w3-        if ( ndx % 3 == 0  || ndx % 5 == 0) {
//-w3-            sum += ndx ;
//-w3-            // printf("%d\n", ndx );
//-w3-        }
//-w3-
//-w3-        /*  
//-w3-            Any pattern of remainders of 5 for integers divisible by 3?
//-w3-            - early values are in a cycle, for each three the remainder
//-w3-              increases -- might be interesting to see those tabulated against
//-w3-              one another for meta-cycles
//-w3-
//-w3-        if ( ndx % 3 ) {
//-w3-            printf("%d\n", ndx % 5);
//-w3-        }
//-w3-         */
//-w3-    }
//-w3-
//-w3-    //  Result
//-w3-    printf("%d\n", sum );
//-w3-    //  Check
//-w3-    printf("%d\n", sum == 233168 );
//-w3-
//-w3-}
//-w3-

/* WORKS
main()
{
    int ndx     =   0;
    int sum     =   0;  
    int LIMIT   =   1000;

    while ( 1 ) {
        if ( ndx * 3 < LIMIT ) {
            sum += ndx * 3 ;
            // printf("%d\n", ndx );
        } else {
            break;
        }

        if ( ndx * 5 < LIMIT && ( ndx * 5 ) % 3 != 0 ) {
            sum += ndx * 5 ;
            // printf("%d\n", ndx );
        }

        ndx++;
    }

    //  Result
    printf("%d\n", sum );
    //  Check
    printf("%d\n", sum == 233168 );

}
 */

/* WORKS
main()
{
    int ndx     =   0;
    int sum     =   0;  
    int LIMIT   =   1000;

    while ( 1 ) {
        if ( ndx * 3 < LIMIT ) {
            sum += ndx * 3 ;
            if ( ndx * 5 < LIMIT && ( ndx * 5 ) % 3 ) {
                // works bc any value but zero is true
            // if ( ndx * 5 < LIMIT && ( ndx * 5 ) % 3 != 0 ) {
                sum += ndx * 5 ;
            }
        } else {
            break;
        }

        ndx++;
    }

    //  Result
    printf("%d\n", sum );
    //  Check
    printf("%d\n", sum == 233168 );

}
 */
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
        sum += ( ( mult_3 = ndx * 3 ) < LIMIT ) * mult_3 ;
        if ( mult_3 >= LIMIT ) { break; };
        sum += ( ( mult_5 = ndx * 5 ) < LIMIT && mult_5 % 3 != 0 ) * mult_5;
    };
    return sum;
}

main()
{
    printf("%d\n", sum_divisibles() );
}

