/* ------------------------------------------------------------------------ */
/*
    Short solution to problem, unfactored into functions

 */
/* ------------------------------------------------------------------------ */
int power (int base, int exponent)
/*
    Raises base to exponent
 */
{
    int i;
    int val = 1;

    for ( i=0; i <= exponent; i++ ) {
        val = base * val;
    }
    return val;
}

/* ------------------------------------------------------------------------ */
int largest_palindrome(int d1, int d2)
/*
    Returns largest palindrome without using subfunctions
 */
{
    int val1, val2, prod, ry_ndx=0;
    int min1 = power(10, d1 - 1);
    int max1 = power(10, d1) - 1;
    int min2 = power(10, d1 - 1);
    int max2 = power(10, d1) - 1;

    int *palindromes = calloc(ARRAY_SIZE, sizeof(int));

    int chk_ry[ARRAY_SIZE];
    int i, prod_copy, j, palindromic, max = 0;

    /*
        We don't need to loop all the values of val2, as this duplicates values
        already checked
     */

    for ( ; min1 <= max1; min1++ ) {
        for ( val2 = min2; val2 <= max2 && val2 <= min1; val2++ ) {

            prod = min1 * val2;
            prod_copy = prod;
            i = 0;

            // get prod digits into array
            while ( prod > 0 ) {
                chk_ry[i] = prod % 10;
                prod = ( prod - chk_ry[i] ) / 10;
                i++;
            }

            // check array for palindrome
            j = 0;
            palindromic = 1;
            for ( j = 0; j < i/2; j++ ) {
                if ( chk_ry[j] != chk_ry[i -1 -j] ) {
                    palindromic = 0;
                }
            }

            if ( palindromic ) {
                if ( prod_copy > max ) {
                    max = prod_copy;
                }
            }
        }
    }

    return max;
}


/* ------------------------------------------------------------------------ */
int main ()
{
    printf("%d\n", largest_palindrome(2, 2));
}

/* ------------------------------------------------------------------------ */

