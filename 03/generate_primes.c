/*

Library for generation of lists of prime numbers

ALGORITHM:
Generate a list of all prime numbers less than N.

Sieve of Eratosthenes

Source: http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

To find all the prime numbers less than or equal to a given integer n by Eratosthenes' method:

Create a list of consecutive integers from 2 through n: (2, 3, 4, ..., n).
Initially, let p equal 2, the first prime number.
Starting from p, enumerate its multiples by counting to n in increments of p, and mark them in the list (these will be 2p, 3p, 4p, etc.; the p itself should not be marked).
Find the first number greater than p in the list that is not marked. If there was no such number, stop. Otherwise, let p now equal this new number (which is the next prime), and repeat from step 3.
When the algorithm terminates, all the numbers in the list that are not marked are prime.

NOTES:
- This method considered good for limits below 10 million
- There are other algorithms
- There are possible refinements to this algorithm, such as ignoring all even numbers after two

 */

/* 
returning arrays:
http://stackoverflow.com/questions/1453410/declaring-a-c-function-to-return-an-array

*/

#include <stdio.h>

//-4-int NUMBER_OF_PRIMES = 10000;

int size(int *ry)
/* 
    Returns length of array
    - assumes array ends on -1 value
 */
{
    int i = 0;

    while ( ry[i] != -1 )
    {
        i++;
    }

    return i + 1;
}

int* merge_sorted(int *l1, int *l2)  // what is syntanx for taking pointer argument?  or array argument?
/* Takes two sorted arrays (ascending) and combines them into one sorted array
 */
{
    // weed: how do i iterate an array of unknown length?
   /*
        Keys here:
        - figure out looping arrays of unknown size
            - must end array with some known not-good value -- 0, or -1
        - resizing output array to be large enough but no larger
            - how to dynamically resize an array?
    */

    int i, j, k=0;
    int size_l1, size_l2;

    size_l1 = size(l1);
    size_l2 = size(l2);

    int* new_ry[size_l1 + size_l2];     // how to size this?
    /*
        strategy:
        iterate items in one list, for each taking items from other list until finding one equal or greater
     */

    // process all l1 elements
    while ( l1[i] != -1 )
    {
        while ( l2[j] != -1 && l2[j] <= l1[i] )
        {
            new_ry[k] = l2[j];
            /* gets warning, 'assignment makes pointer from integer without a cast'
            j++;
            k++;
        }
        new_ry[k] = l1[i];
        i++;
        k++;
    }

    // check for end of l2; if not, process remaining l2 elements
    while ( l2[j] != -1 )
    {
        new_ry[k] = l2[j];
        j++;
        k++;
    }

    //  add end of array value
    k++;
    new_ry[k] = -1;
    return new_ry;

}


//-int* prime_list(int n) {
//-/* 
//-    Returns pointer to array listing primes less than n
//-    Algorithm is Sieve of Eratosthenes
//- */
//-
//-    // create counter variables;
//-    int i, j, k;
//-    // create array to hold primes and to be returned
//-    int* primeArr = malloc(sizeof(int) * n);
//-
//-    // initialize primeArr values
//-
//-    int candidates[n];  // initialization of candidates array -- syntax?
//-    int not_primes[n];  // initialization of not_primes -- syntax?
//-    int k_candidates[n];
//-    int not_candidates[n];
//-    int primes[n];  // initialization of primes -- syntax?
//-
//-    // populate candidates
//-
//-    for ( i = 2; i < n; i++ ) {
//-        candidates[i-2] = i;
//-    }
//-
//-    // populate not_candidates
//-    // it's all gibberish just yet
//-    /*
//-        - how to iterate candidates
//-        - populate not_primes
//-     */
//-
//-    k = 0;
//-    for ( j = 0; j - 2 < n; j++ ) {
//-        // must add first candidate value to primes array
//-        candidate = candidates[j];
//-        // check if candidate is in not_primes; if not, put in primes
//-        // if in not_primes, skip
//-        
//-        // puts not candidates numbers in array, but must be synced with the prior not candidates in array
//-        while ( val = candidates * k ) < n {
//-            k_candidates[k] = val;
//-            k++;
//-        }
//-        k_candidates[k] = -1;
//-        not_candidates = merge_sorted(not_candidates, k_candidates);
//-    }
//-
//-    /*
//-        PROCEDURE:
//-        - create list of integers, 'candidates', up to n 
//-        - let p = 2
//-        - put p in list of primes
//-        - enumerate multiples of p less than n, putting these in list of not-primes
//-        - the first value in candidates, which is greater than p, and which is not in the list of not-primes, is itself prime
//-            - if there is no such value, stop algorithm; otherwise,
//-            - put this value in list of primes
//-            - set p equal to this value and repeat process from enumeration step
//-
//-
//-     */
//-
//-    // return array
//-    return primeArr;
//-
//-}
    

/*

To do:
- learn arrays
    - initialization
    - assigment
    - removal
    - iteration

- learn return of pointer values
- learn usage of returned pointer values

PATH:
- write function that prints out list of primes
    see print_prime_list.c
- write function that calls a prime list generation function and prints its output
    - extend first function to return a pointer to an array of primes
    - write function taking that pointer and iterating the list pointed to
    ! this establishes:
        - prime list / array generation function
        - pattern for calling functions returning lists, that is, pointers to arrays, and using the pointer returned
- then ready to return to 3.c to learn how to include prime list generation function in the 3.c file

 */
