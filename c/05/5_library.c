/*
    Brute force approach to Problem #5

    STATUS
    - works for 10
    - doesn't work for 20

 */

#include <stdio.h>

#define TARGET 20
//-#define TARGET 10

int main()
{

    long int candidate=1, val, i;

    int n = TARGET;

    for ( i=1; i<=n; i++ ) {
        candidate *= i;
    }

    printf("candidate: %ld\n", candidate);

    long int smallest_divisible = candidate;
    long int answer = candidate;
    int divisible = 1;

    for ( smallest_divisible; smallest_divisible > 0; smallest_divisible-- ) {
        divisible = 1;
        for ( i=n; i > 0; i-- ) {
            if ( smallest_divisible % i != 0 ) {
                divisible = 0;
                break;
            }
        }

        if ( divisible == 1 ) {
            answer = smallest_divisible;
            printf("new candidate: %ld\n", answer);
        }
    }

    printf("%ld\n", answer);

}
