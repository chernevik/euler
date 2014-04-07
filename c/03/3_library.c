/*----------------------------------------------------------------------------

Provides list of prime factors of TARGET value.
- Answers Project Euler #3
- Uses Euler library

STATUS
- Solves problem on Thorin
- FAILS on Volundr
    - probably the target value is larger than can be held by long int on Volundr
        - am I sure that it isn't on Thorin?
    - If so, probably fixed by using type float (yes?) rather than long int


TODO:
- Revise to work on Volundr, dwarf, gloin
- Add function finding maximum value in an array
- Review and clean code
- Review and prune other files
- Copy core functions to an 'euler library', write solution drawing from that library
- Add unit tests?

NOTES
- For all arrays returned, end of intended values is marked with -1
- Is there a way to find end of arrays without using the -1 convention used here?


PROBLEM:

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?


PRIME FACTORIZATION PROCESS 
- Divide target number by prime numbers, greater than 1, in increasing
  sequence, until reaching a prime that divides the target evenly.
    - This prime is a factor of the target
    - The number of times that prime divides into the target, I term 'the
      dividend'
- If the dividend is not itself prime, find the prime factors of the dividend.
  Each of these is a prime factor of the target.
- If the dividend is itself prime, the dividend is a prime factor of the number. 


TO CHECK A NUMBER FOR PRIME
- Check all integers whose square is less than the number for a remainder,
  using the modulus operation.  If any have no remainder, the number is
  divisible by that integer, and is not prime.
- Algorithm taken from King.
- Don't know why integer square less than the number is the right limit --
  figure that out

----------------------------------------------------------------------------*/



#include <stdio.h>
#include <stdlib.h>

#include "../euler.c"

#define TARGET 600851475143



int main()
/*
    Outputs list_primes() contents.

 */
{
    int *prime_list;    
    int j = 0;
    int val;

    prime_list = factorize(TARGET);

    printf("%ld\n", max(prime_list));
    /*
    while ( ( val = prime_list[j] ) != -1 ) {
        printf("%d\n", val);
        j++;
    }
     */
}


