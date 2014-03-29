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
#include <stdlib.h>

int NUMBER_OF_PRIMES = 10000;

/*--------------------------------------------------------------------------*/
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

/*--------------------------------------------------------------------------*/
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

    int i=0;
    int j=0;
    int k=0;
    int size_l1, size_l2;

    size_l1 = size(l1);
    size_l2 = size(l2);

    int* new_ry = malloc(sizeof(int) * (size_l1 + size_l2) );     // how to size this?
    //-int new_ry[size_l1 + size_l2];     // how to size this?
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
            /* gets warning, 'assignment makes pointer from integer without a cast' */
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
    new_ry[k] = -1;
    return new_ry;

}


/*--------------------------------------------------------------------------*/
int *return_list() {
/*
    Demonstrates return of pointer to a list

 */

    int i, j;
    int* ary = malloc(sizeof(int) * ( 10 + 1 ) );

    // initialize array values
    for (i=0; i<10; i++) 
    {
        ary[i] = i * 2;
    }

    // Send end of array value
    ary[11 - 1] = -1;

    // Return pointer to array
    return ary;
    
};


/*--------------------------------------------------------------------------*/
int *prime_list(int n) {
/*
    Returns a pointer to an incomplete list of not primes

 */

    int i, val;
    int candidates_ndx = 0;
    int *primeAry = calloc(n+1, sizeof(int));
    //-int *primeAry = malloc(sizeof(int) * ( n + 1 ) );
    primeAry[n] = -1;

    /*
    printf("contents of primeAry\n");
    i=0;
    while ((val=primeAry[i++])!=-1) {printf("%d\n", val);}
    printf("done primeAry\n");
     */

    int candidates[n];
    int *not_prime_swap;
    int not_prime[n];
    int not_prime_addition[n];
    int prime[n];

    // initialize candidate array values
    for (i=0; i+2 < n; i++) 
    {
        candidates[i] = i+2; 
    }

    // Set end of array value
    candidates[i] = -1;

    // initialize not prime array values
    for (i=0; i < n; i++) 
    {
        not_prime[i] = 0; 
    }

    // Set end of not_prime array value
    not_prime[i] = -1;

    /*
    printf("contents of not_prime\n");
    i=0;
    while ((val=not_prime[i++])!=-1) {printf("%d\n", val);}
    printf("done \n");
     */


    // start algorithm
    int prime_candidate = candidates[candidates_ndx];  // value is 2
    candidates_ndx++;

    // check for presence in not_prime
    int is_prime = 1;

    i = 0;
    while ( ( val = not_prime[i] ) != 1 && is_prime == 1 ) {
        if ( val == prime_candidate ) {
            is_prime = 0;
        }
        i++;
    }

    // put multiples of this prime number in not_prime
    for ( i=2; ( val = prime_candidate * i ) < n; i++ ) {
        not_prime_addition[i-2] = val;
    }
    not_prime_addition[i-2] = -1;

    /*
    printf("contents of not_prime_addition\n");
    i=0;
    while ((val=not_prime_addition[i++])!=-1) {printf("%d\n", val);}
    printf("done \n");
     */


    not_prime_swap = merge_sorted(not_prime, not_prime_addition);

    i = 0;
    while ( ( val = not_prime_swap[i] ) != -1) 
    {
        not_prime[i] = val;
        i++;
    }
    // catch -1 value
    not_prime[i] = not_prime_swap[i]; 

    /*
    printf("contents of not_prime_swap\n");
    i=0;
    while ((val=not_prime_swap[i++])!=-1) {printf("%d\n", val);}
    printf("done \n");
     */

    // show some array's values in primeAry
    i = 0;
    while ( ( val = not_prime[i] ) != -1 ) 
    //-for (i=0; i < n + 1; i++) 
    {
        /* inspection
        printf("loopcheck\n");
        printf("%d\n", i);
        printf("%d\n", primeAry[i]);
        printf("%d\n", val);
        printf("%d\n", not_prime_swap[i]);
        printf("donecheck\n");
         */
        primeAry[i] = not_prime[i]; 
        i++;
    }
    // catch -1 value
    primeAry[i] = not_prime[i]; 

    // Return pointer to array

    return primeAry;
    
};


/*--------------------------------------------------------------------------*/
int *prime_list_seg_fault(int n) {
/* 
    This code segment faults.

    Returns pointer to array listing primes less than n
    Algorithm is Sieve of Eratosthenes


    STATUS:
    - returns segmentation fault on execution
    - I suspect the issue is related to usage of merge_sorted

 */

    // create counter variables;
    int i, j, k, l;
    int pA_ndx = 0;

    // create array to hold primes and to be returned
    int *primeArr;
    primeArr = malloc(sizeof(int) * ( n + 1 ) );

    int candidates[n];
    int *not_primes;
    int multiples[n];
    int val, np_val, val_multiple;

    // Return basic list -- to establish proper pointer handling

//-w-    // initialize array values
//-w-    for (i=0; i<n; i++) 
//-w-    {
//-w-        primeArr[i] = i * 2;
//-w-    }
//-w-
//-w-    // Send end of array value
//-w-    primeArr[n] = -1;
//-w-

    // initialize primeArr values

    // populate candidates

    for ( i = 2; i < n; i++ ) {
        candidates[i-2] = i;
    }

    i++;
    candidates[i-2] = -1;
    
    // Scan candidates for prime possibility
    while ( ( val = candidates[j] ) != -1 ) {
        // check if val is in not_primes
        int prime_flag = 1;
        int k = 0;
        while ( ( np_val = not_primes[k] ) >= val ) {
            if ( np_val == val ) {
                prime_flag = 0;
            }
        }

        // if val is not in not_primes, put in prime, and put multiples of val in not_prime 
        if ( prime_flag == 1 ) {
            primeArr[pA_ndx] = val;
            pA_ndx++;

            // collect multiples of val less than or equal to n
            int l = 0;
            while ( ( val_multiple = l * val ) <= n ) {
                multiples[l] = val_multiple;
            }

            // merge multiples with not_primes
            // suspect that segmentation fault is related to this line
            not_primes = merge_sorted(not_primes, multiples);
        }

    }

    return primeArr;

}
/*--------------------------------------------------------------------------*/
    

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
/*--------------------------------------------------------------------------*/
