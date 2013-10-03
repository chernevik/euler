#include <stdio.h>

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

 */

main()
{
    int i, mult_3, mult_5, min_max, sum;
    
    i       =   0;
    min_max =   0;
    sum     =   0;  
    mult_3 = i * 3;
    mult_5 = i * 5;
    min_max = mult_3;
    /* min_max = min(mult_3, mult_5); */
    
    while ( min_max < 1000 ) {
        printf("%d\n", i);
        printf("%d\n", mult_3);
        printf("%d\n", mult_5);
        printf("%d\n", sum);
        printf("\n");

        sum += mult_3;
        if ( mult_5 < 1000 ) {
            sum += mult_5;
        };
    
        i++;
        mult_3 = i * 3;
        mult_5 = i * 5;
        min_max = mult_3;
        /* min_max = min(mult_3, mult_5);   */
    }

    printf("%d", sum);
}
