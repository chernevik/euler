/*
    Solves Euler #8

 */

/*
    Really this is a string handling problem.

    - Put the number into a string
    - Read the first five digits
    - Get the product of those digits, place value in register
    - For each subsequent digit:
        - Read the digit
        - Get the product of new consecutive five digits represented by that digit
            Two ways:
            ONE:
            - keep an array of the five digits, in order of occurence in the number
            - pop the first digit off (moving remaining four forward)
            - put the new digit at the end of the array
            - get product of the array

            TWO:
            - keep an array of the five digits, in order of occurence in the number
            - pop the first digit off (moving remaining four forward)
            - put the new digit at the end of the array
            - divide the register value by the popped value and multiply by new value

            Either way, program needs a stack of digits
        - check new product with prior max value

    OR
    - Read entire number into 100 element array
    - Get product of first five elements
    - for elements 6 through 100:
        - get prior first value (current array index less five)
        - get new value (current array value)
        - do the division and multiplying thing

    This approach uses the initial storage array of the read digits, and avoids popping and pushing operations

    REFERENCES
    converting an integer to a string:
    http://stackoverflow.com/questions/8257714/how-to-convert-an-int-to-string-in-c
    http://stackoverflow.com/questions/9655202/how-to-convert-integer-to-string-in-c

    Also:
    http://stackoverflow.com/questions/8232634/simple-use-of-sprintf-c


    TODO: 
    Re-read King on string handling.  

    I don't wanna!  I just want to code!

 */


#include <stdio.h>
#include <stdlib.h>

int main()
{

    //-char *num;
    char *ptr;

    char num[1001] = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

    int num_len = 1000;
    int lim = 5;

    long ret, max=0, reg=1;
    int i, j;

    for ( i=0; i<num_len-lim; i++ ) {
        /*
        ret = num[i] - '0';
        printf("%d\n", i);
        printf("%c\n", num[i]);
        printf("%ld\n", ret);
        printf("%ld\n", 2 * ret);
         */
        
        reg = 1;
        for ( j=0; j < lim; j++ ) {
            ret = num[i+j] - '0';
            reg *= ret;
        }

        if ( reg > max ) {
            max = reg;
        }

    }
    
    printf("%ld\n", max);

    return 0;
}
