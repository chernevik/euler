#include <stdio.h>
#include "generate_primes.c"

void main()
{
    int f[4] = {1, 3, 5, -1};
    int g[4] = {2, 4, 6, -1};
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
