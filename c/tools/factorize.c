#include <stdio.h>
#include <stdlib.h>

#include "../euler.c"

#define TARGET 2520

int main()
{
    int *ry;
    int val, i = 0;
    ry = factorize(TARGET);
    while ( ( val = ry[i++] ) != -1 ) {
        printf("%d\n", val);
    }
    return 0; 
}
