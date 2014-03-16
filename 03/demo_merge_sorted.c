#include <stdio.h>
#include "generate_primes.c"

/*
    STATUS
    - works for simple lists

 */

void main()
{
    // works for these values 
    /*
    int f[4] = {1, 3, 5, -1};
    int g[4] = {2, 4, 6, -1};
     */

    // works for these values 
    int f[5] = {1, 3, 5, 20, -1};
    int g[4] = {12, 14, 16, -1};

    int i = 0;
    int *h;

    //-int h[10];

    h = merge_sorted(f, g);

    while ( h[i] != -1 )
    {
        printf("%d\n", h[i]);
        i++;
    }
    

}
