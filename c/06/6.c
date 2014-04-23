/*
    Brute force solution to Euler #6

    Answer for 100 is 25164150

 */

#include <stdio.h>

#define TARGET 100

int main()
{
    int n = TARGET;
    int i;
    long int sum, sum_squares, square_of_sum, answer;

    for ( i=1; i <= n; i++ ) {
        sum += i;
        sum_squares += i * i;
    }

    square_of_sum = sum * sum;

    answer = square_of_sum - sum_squares;

    printf("%ld\n", answer);


}

