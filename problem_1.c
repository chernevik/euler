#include <stdio.h>

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

 */

main()
{
    int ndx, sum, LIMIT;
    
    ndx     =   0;  
    sum     =   0;  
    LIMIT   =   1000;

    while ( 1 ) {

        if ( ndx * 3 < LIMIT ) {
            sum += ndx * 3 ;
            // printf("%d\n", ndx * 3 );
        } else {
            break;
        }

        if ( ndx * 5 < LIMIT && ( ndx * 5 ) % 3 != 0 ) {
            sum += ndx * 5 ;
            // printf("%d\n", ndx * 5 );
        } 
    
        ndx++;
    }

    printf("%d\n", sum);
    //  Gives 233168, which is correct 

}
