#include <stdio.h>

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

 */

/*  WORKS

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
 */


/* WORKS
main()
{
    int ndx, sum, LIMIT;
    
    ndx     =   0;  
    sum     =   0;  
    LIMIT   =   1000;

    while ( ndx < LIMIT ) {

        if ( ndx % 3 == 0  ) {
            sum += ndx ;
            // printf("%d\n", ndx );
        }

        if ( ndx % 5 == 0 && ndx % 3 != 0 ) {
            sum += ndx ;
            // printf("%d\n", ndx  );
        } 
    
        ndx++;
    }

    if ( sum == 233168 ) {
        printf("ok\n");
    } else {
        printf("%d is incorrect\n", sum );
    }

}
 */

/*  WORKS
main()
{
    int ndx, sum, LIMIT;
    
    ndx     =   0;  
    sum     =   0;  
    LIMIT   =   1000;

    while ( ndx < LIMIT ) {
        if ( ndx % 3 == 0  || ndx % 5 == 0) {
            sum += ndx ;
            // printf("%d\n", ndx );
        }
        ndx++;
    }

    if ( sum == 233168 ) {
        printf("ok\n");
    } else {
        printf("%d is incorrect\n", sum );
    }

}
 */

main()
{
    int ndx;
    int sum     =   0;  
    int LIMIT   =   1000;

    for ( ndx = 0; ndx < LIMIT; ndx++ ) {
        if ( ndx % 3 == 0  || ndx % 5 == 0) {
            sum += ndx ;
            // printf("%d\n", ndx );
        }
    }

    if ( sum == 233168 ) {
        printf("ok\n");
    } else {
        printf("%d is incorrect\n", sum );
    }

}
