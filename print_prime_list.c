/*

PROBLEM:
Print a list of prime numbers less than N

MOTIVATION:
- Demonstration basic array usage
- Development of prime list generation algorithm

THOUGHT:
- if I'm working toward handling of pointers to arrays, wouldn't it be better to establish the pointer handling stuff with a less involved array generation problem?

 */

#include <stdio.h>

void print_list() {
/*
    Demonstrates initialization and retrieval of array values.

 */
    int i, j;
    int ary[10];

    // initialize array values
    for (i=0; i<10; i++) 
    {
        ary[i] = i * 2;
    }

    // iterate and print array values
    for (j=0; j<10; j++) 
    {
        printf("%d\n", ary[j]);
    }
}

int return_list() {
/*
    Demonstrates return of pointer to a list

 */
    int i, j;
    int ary[10];

    // initialize array values
    for (i=0; i<10; i++) 
    {
        ary[i] = i * 2;
    }

    // how do i return a pointer to this array?
}

void main() {
    print_list();
}

