#include <stdio.h>

/*

Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
 */


int fibonacci(int first, int second)
/*
    Returns the next Fibonacci term, given first and second
*/
{
    int nxt;
    nxt = first + second;
    return nxt;
}

void fibonacci_sequence(int first, int second, int max)
/*
    Prints out Fibonacci sequence, stopping when term exceeds max value
 */
{
    int nxt;

    printf("%d\n", first);
    printf("%d\n", second);

/*
    while ( second < max ) {
        nxt = fibonacci(first, second);
        printf("%d\n", nxt);
        first = second;
        second = nxt;
    }
 */

    while ( ( nxt = fibonacci(first, second) ) < max ) {
        printf("%d\n", nxt);
        first = second;
        second = nxt;
    }  
}  

main()
{
    fibonacci_sequence(1, 2, 100);
}
