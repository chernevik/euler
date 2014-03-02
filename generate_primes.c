/*

PROBLEM:

Generate a list of all prime numbers less than N.

ALGORITHM:

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

NUMBER_OF_PRIMES = 10000

int (*prime_list(int n)) {
/* 
    Returns pointer to array listing primes less than n
    Algorithm is Sieve of Eratosthenes
 */

    // weed: i am not sure what this does or if it is even proper syntax
    int (*primeArr)[NUMBER_OF_PRIMES] = malloc(sizeof *primeArr * n);

    // initialize primeArr values

    /*
        PROCEDURE:
        - create list of integers, 'candidates', up to n 
        - let p = 2
        - put p in list of primes
        - enumerate multiples of p less than n, putting these in list of not-primes
        - the first value in candidates, which is greater than p, and which is not in the list of not-primes, is itself prime
            - if there is no such value, stop algorithm; otherwise,
            - put this value in list of primes
            - set p equal to this value and repeat process from enumeration step


     */

    // return array
    return primeArr;

}
    

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
- write function that calls a prime list generation function and prints its output
    - extend first function to return a pointer to an array of primes
    - write function taking that pointer and iterating the list pointed to
    ! this establishes:
        - prime list / array generation function
        - pattern for calling functions returning lists, that is, pointers to arrays, and using the pointer returned
- then ready to return to 3.c to learn how to include prime list generation function in the 3.c file

 */
