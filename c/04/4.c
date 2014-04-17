/* ------------------------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10       // until I find a better way of sizing arrays

/* ------------------------------------------------------------------------ */
int get_final(int n)
/*
    Gets the final digit of n
 */
{
    return n % 10;
}

/* ------------------------------------------------------------------------ */
int strip_final(int n)
/*
    Removes the last digit from n
 */
{
    int stripped;
    if ( n < 10 ) {
        stripped = 0;
    } else {
        stripped = (n -  get_final(n)) / 10;
    }
    return stripped;
}

/* ------------------------------------------------------------------------ */
int size_ry(int *ry)
/*
    Returns the size of an array, values ending with -1
    - does not include the -1 in the array size
 */
 {
    int i = 0;
    while (ry[i] != -1) {
        i++;
    }
    return i;
 }
/* ------------------------------------------------------------------------ */
void *reverse_ry(int *ry)
/*
    Takes a pointer to an array, ending in -1, and reverses the values in the array.

    Works by side effect.

 */
{
    int swap, i=0;

    int ry_size = size_ry(ry);
    int reversals = ry_size / 2;   

    for ( i=0; i <= reversals; i++) {
        swap = ry[i];
        ry[i] = ry[ry_size - 1 - i];
        ry[ry_size -1 - i] = swap;

    }
}

/* ------------------------------------------------------------------------ */
int *get_digits(int n)
/* 
    Returns array holding each digit of n
 */
{
    int *digit_ry = calloc(ARRAY_SIZE, sizeof(int));
    int d_ndx = 0;

    while ( n > 0 ) {
        digit_ry[d_ndx++] = get_final(n);
        n = strip_final(n);
    }

    digit_ry[d_ndx] = -1;

    reverse_ry(digit_ry);

    return digit_ry;
}

/* ------------------------------------------------------------------------ */
int is_palindrome_ry(int *ry)
/*
    Returns whether array ry is palindromic
    - assumes array ends in -1
 */
{
    int ry_size = size_ry(ry);
    int checks = ry_size / 2;
    int palindromic = 1;
    int i;

    for ( i = 0; i <= checks; i++ ) {
        if ( ry[i] != ry[ry_size -1 -i] ) {
            palindromic = 0;
        }
    }

    return palindromic;

}


/* ------------------------------------------------------------------------ */
int is_palindrome(int n)
/*
    Returns whether number is palindromic
 */
{
    int *digits;
    digits = get_digits(n);
    return is_palindrome_ry(digits);
}

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
int *get_palindromes(int d1, int d2)
/*
    Returns pointer to array of palindromes resulting from multiplication of all number of n1 digits by numbers of n2 digits
 */
{
    int val1, val2, prod, ry_ndx=0;
    int min1 = power(10, d1 - 1);
    int max1 = power(10, d1) - 1;
    int min2 = power(10, d1 - 1);
    int max2 = power(10, d1) - 1;

    int *palindromes = calloc(ARRAY_SIZE, sizeof(int));


    /*
        We don't need to loop all the values of val2, as this duplicates values
        already checked
     */

    for ( val1 = min1; val1 <= max1; val1++ ) {
        for ( val2 = min2; val2 <= max2 && val2 <= val1; val2++ ) {
            prod = val1 * val2;
            if ( is_palindrome(prod) ) {
            /*
                printf("%d\n", val1);
                printf("%d\n", val2);
                printf("%d\n", prod);
             */
                palindromes[ry_ndx++] = prod;
            }
        }
    }

    return palindromes;
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


    /*
        We don't need to loop all the values of val2, as this duplicates values
        already checked
     */

    for ( val1 = min1; val1 <= max1; val1++ ) {
        for ( val2 = min2; val2 <= max2 && val2 <= val1; val2++ ) {
            prod = val1 * val2;
                // check prod for palindrome
                // if palindrome, check for max
        }
    }

    return palindromes;
}


/*--------------------------------------------------------------------------*/
int max(int *ry)
/*
    Returns value of largest element in array.
    - Presumes array ends with -1
 */
{
    int i = 0;
    int val=0, max=0;

    while ( ( val = ry[i++] ) != -1 ) {
        if ( val > max ) {
            max = val;
        }
    }

    return max;

}

/* ------------------------------------------------------------------------ */
int get_first(int n)
/*
    Gets the first digit of n
 */
{
    int i;
    while ( power(10, i) < n ) {
        i++;
    }

    int p = i - 1;
    i = 0;
    while ( power(10, p) * i < n ) {
        i++;
    }

    return i - 1;
}

/* ------------------------------------------------------------------------ */
int main ()
{
/*
    int *palindromes;
    palindromes = get_palindromes(2, 2);
    printf("largest palindrome is %d\n", max(palindromes));
    return 0;
 */
    
    printf("%d\n", get_first(9123));

    // returning 906609
    // takes 0.101 seconds (real) on Thorin
}

/* ------------------------------------------------------------------------ */

