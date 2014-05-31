/*
    Euler Problem #9

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    int a, b, sum, lim=1000;
    double c, intpart, fracpart;

    for ( a=1; a<lim; a++) {
        for (b=1; b<lim && b<=a; b++) {
            c = sqrt(a*a + b*b);
            fracpart = modf(c, &intpart);
            // http://www.cplusplus.com/reference/cmath/modf/
            if ( fracpart == 0 ) {
                // printf("%d, %d\n", a, b);
                if ( a + b + c == 1000 ) {
                    printf("one answer:\n");
                    printf("a: %d\n", a);
                    printf("b: %d\n", b);
                    printf("c: %f\n", c);
                    printf("product: %f\n", a * b * c);
                }
            }
        }
    }
    
    return 0;
}
