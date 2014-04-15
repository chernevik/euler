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
    - per Stack Overflow, no, there isn't -- size of array must be stashed, or
      some end of array value used

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


