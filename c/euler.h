/*--------------------------------------------------------------------------*/
#include "boolean.h"

/*--------------------------------------------------------------------------*/


Bool is_prime(int n); 
/* 
    Tests whether << n >> is prime
 */


/*--------------------------------------------------------------------------*/
int *list_primes(long int n);
/*
    Returns a pointer to an array of all primes less than equal to n.

    Array ends on -1.

 */


/*--------------------------------------------------------------------------*/
long int next_prime(long int n);
/*
    Returns the next prime number after n.

 */

/*--------------------------------------------------------------------------*/
int *factorize(long n);
/*
    Returns pointer to array of prime factors of n.

    Array ends with -1.

    weed: must define handling when passed 0 or 1
    weed: should be named prime_factorize

 */


/*--------------------------------------------------------------------------*/
long int max(int *ry);
/*
    Returns value of largest element in array.
    - Presumes array ends with -1
 */

/*--------------------------------------------------------------------------*/
#define ARRAY_SIZE 10       // until I find a better way of sizing arrays

/* ------------------------------------------------------------------------ */
int get_final(int n);
/*
    Gets the final digit of n
 */

/* ------------------------------------------------------------------------ */
int strip_final(int n);
/*
    Removes the last digit from n
 */

/* ------------------------------------------------------------------------ */
int size_ry(int *ry);
/*
    Returns the size of an array, values ending with -1
    - does not include the -1 in the array size
 */
/* ------------------------------------------------------------------------ */
void *reverse_ry(int *ry);
/*
    Takes a pointer to an array, ending in -1, and reverses the values in the array.

    Works by side effect.

 */

/* ------------------------------------------------------------------------ */
int *get_digits(int n);
/* 
    Returns array holding each digit of n
 */

/* ------------------------------------------------------------------------ */
int is_palindrome_ry(int *ry);
/*
    Returns whether array ry is palindromic
    - assumes array ends in -1
 */


/* ------------------------------------------------------------------------ */
int is_palindrome(int n);
/*
    Returns whether number is palindromic
 */

/* ------------------------------------------------------------------------ */
int power (int base, int exponent);
/*
    Raises base to exponent
 */

/* ------------------------------------------------------------------------ */
int *get_palindromes(int d1, int d2);
/*
    Returns pointer to array of palindromes resulting from multiplication of all number of n1 digits by numbers of n2 digits
 */


/*--------------------------------------------------------------------------*/
int max_int(int *ry);
/*
    Returns value of largest element in array.
    - Presumes array ends with -1
    - for int types
    - weed: any way to write this to handle long int and int?
    - weed: renaming function probably breaks solution to #4
 */

/* ------------------------------------------------------------------------ */
int get_first(int n);
/*
    Gets the first digit of n
 */

/* ------------------------------------------------------------------------ */
int in(int val, int *ry);
/*
    Checks whether val is equal to any member of array ry
    - assumes ry ends in -1

 */

/* ------------------------------------------------------------------------ */
int *unique(int *ry);
/*
    Returns an array holding unique members of ry
    - presumes ry ends in -1
 */
/* ------------------------------------------------------------------------ */
