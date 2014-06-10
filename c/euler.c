/*--------------------------------------------------------------------------*/
/*
    Provides library of functions written while solving Project Euler problems

 */
/*--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/*--------------------------------------------------------------------------*/
#define TRUE 1
#define FALSE 0

typedef int Bool;


Bool is_prime(int n) 
/* 
    Tests whether << n >> is prime
 */
{

    int divisor;

    if (n <= 1) return FALSE;
    for (divisor = 2; divisor * divisor <= n; divisor++)
    {
        if (n % divisor == 0) 
        {
            return FALSE;
        }
    }
    return TRUE;
}


/*--------------------------------------------------------------------------*/
int *list_primes(long int n)
/*
    Returns a pointer to an array of all primes less than equal to n.

    Array ends on -1.

 */
{
    // initialize point to array full of zeroes
    int *prime_list = calloc(n, sizeof(int));
    int pl_ndx = 0;

    int i;

    for ( i = 0; i <= n; i++ ) {
        if ( is_prime(i) ) {
            prime_list[pl_ndx] = i;
            pl_ndx++;
        }
    }

    prime_list[pl_ndx] = -1;

    return prime_list;

    /*
        PROBLEM
        How to revise this to return an array holding only the primes, and not ending on -1

        DRAFT CODE

        int new_array_size = pl_ndx;    // if the prior array holds 3 elements, its last index will be 2, while the new array must be size 3 to hold all the elements including the -1.  So the new array must be size 2 to hold all elements but the -1.

        int *new_list = calloc(new_array_size, sizeof(int));

        for ( i = 0; i < new_array_size; i++ ) {   
            new_list[i] = prime_list[i];
        }

     */

}


/*--------------------------------------------------------------------------*/
long int next_prime(long int n)
/*
    Returns the next prime number after n.

 */
{
    long int j = n;
    for (j = n+1; !is_prime(j); j++ ) {
    }

    // check
    if (!is_prime(j)) {
        printf("%ld is not a prime -- ERROR", j);
    }
    return j;
}

/*--------------------------------------------------------------------------*/
int *factorize(long n)
/*
    Returns pointer to array of prime factors of n.

    Array ends with -1.

    weed: must define handling when passed 0 or 1
    weed: should be named prime_factorize

 */
{
    int *dividend_factors;
    int *factors = calloc(n, sizeof(int));
    int factors_ndx=0, j=0, df_val;
    long int dividend=0;

    if (is_prime(n)) {
        factors[factors_ndx++] = n;
        factors[factors_ndx] = -1;
        return factors;
    }

    /*
     */

    long int val = 1;
    while ( ( val = next_prime(val) ) != -1 && !dividend ) {
        if ( n % val == 0 ) {
            factors[factors_ndx++] = val;
            dividend = n / val;
            if (!is_prime(dividend)) {
                dividend_factors = factorize(dividend);
                while ( ( df_val = dividend_factors[j++] ) != -1 ) {
                    factors[factors_ndx++] = df_val;
                }
            } else {
                factors[factors_ndx++] = dividend;
            }
        }
    }
    factors[factors_ndx] = -1;

    // add back check on factors
    // add -- somewhere -- check to get maximum value

    long int check_val = 1;
    int k = 0;
    while ( ( val = factors[k++] ) != -1 ) {
        check_val = check_val * val;
    }
    if ( check_val != n ) {
        // weed: provide better error handling here?
        printf("ERROR\n");
        printf("%ld is not equal to \n", check_val);
        printf("%ld", n);
    }

    return factors;

}


/*--------------------------------------------------------------------------*/
long int max(int *ry)
/*
    Returns value of largest element in array.
    - Presumes array ends with -1
 */
{
    int i = 0;
    long int val=0, max=0;

    while ( ( val = ry[i++] ) != -1 ) {
        if ( val > max ) {
            max = val;
        }
    }

    return max;

}

/*--------------------------------------------------------------------------*/
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
    int swap=0, i=0;

    int ry_size = size_ry(ry);
    int reversals = ry_size / 2;   

    for ( i=0; i < reversals; i++) {
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


/*--------------------------------------------------------------------------*/
int max_int(int *ry)
/*
    Returns value of largest element in array.
    - Presumes array ends with -1
    - for int types
    - weed: any way to write this to handle long int and int?
    - weed: renaming function probably breaks solution to #4
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
int in(int val, int *ry)
/*
    Checks whether val is equal to any member of array ry
    - assumes ry ends in -1

 */
{
    int in=0, chk_val, i=0;

    while ( ( chk_val = ry[i++] ) != -1 ) {
        if ( val == chk_val ) {
            in = 1;
            break;
        }
    }

    return in;

}

/* ------------------------------------------------------------------------ */
int *unique(int *ry)
/*
    Returns an array holding unique members of ry
    - presumes ry ends in -1
 */
{
    int *set = calloc(1000, sizeof(int));
    int i=0, val;
    int set_ndx = 0;

    set[set_ndx] = -1;

    while ( ( val = ry[i++] ) != -1 ) {
        if ( !in(val, set) ) {
            set[set_ndx++] = val;    
            set[set_ndx] = -1;    
        }
    }

    //-set[set_ndx] = -1;

    return set;

}
/* ------------------------------------------------------------------------ */
