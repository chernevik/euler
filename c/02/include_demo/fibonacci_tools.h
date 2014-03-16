#include "../fibonacci.h"

int sum_fibonacci_even(int first, int second, int max_term)
/*
    Prints out sum of even terms of Fibonacci sequence less than max_term
 */
{
    int nxt, total=0;

    if ( first % 2 == 0 ) {
        total += first;
    }
    if ( second % 2 == 0 ) {
        total += second;
    }

    while ( ( nxt = fibonacci(first, second) ) < max_term ) {
        /* Check for even */
        if ( nxt % 2 == 0 ) {
            total += nxt;
        }
        first = second;
        second = nxt;
    }  

    return total;
}  
