#include <stdio.h>
#include <stdlib.h>

#define SEQUENCE_LEN 1000000

long long collatz (long long val) {
/*
    Returns the next term in a Collatz sequence
 */
    
    long long ret;

    if ( val % 2 == 0 ) {
        ret = val / 2;
    } else {
        ret = ( val * 3 + 1 );
    };

    return ret;
}


int main () {
    int top = 1000000;
    int seed = 1;
    int max_len = 0;
    int max_seed = 0;
    long long val;
    int i;

    for ( seed = 1; seed <= top; seed++ ) {
        val = seed;
        for ( i = 1; val != 1; i++ ) {
            val = collatz(val);
        }

        if ( i > max_len ) {
            max_len = i;
            max_seed = seed;
        }

    }

    printf("max seed is %d\n", max_seed);

}
