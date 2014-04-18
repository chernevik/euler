/* ------------------------------------------------------------------------ */
/*
    Solves problem with processes factored into functions.
 */

/* ------------------------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>

#include "../euler.c"

/* ------------------------------------------------------------------------ */
int main ()
{
    int *palindromes;
    palindromes = get_palindromes(2, 2);
    printf("largest palindrome is %d\n", max(palindromes));
    return 0;
    

    // returning 906609
    // takes 0.101 seconds (real) on Thorin
}

/* ------------------------------------------------------------------------ */

