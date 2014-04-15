/*
    Works through concepts of array size, and size of pointers to arrays
 */

#include <stdio.h>
#include <stdlib.h>


int *return_array(int n)
/*
    Returns an array of length n, populated with consecutive integers
 */
{
    int ry_d[n];
    int i;

    for ( i=0; i < n; i++ ) {
        ry_d[i] = i;
    }

    // this return value generates a warning
    return ry_d;
}


int *return_array_pointer(int n)
/*
    Returns a pointer to an array of length n, populated with consecutive
    integers
 */
{
    int *ry_c = calloc(n, sizeof(int));
    int i;

    for ( i=0; i < n; i++ ) {
        ry_c[i] = i;
    }

    printf("sizeof ry_c, in function: %lu\n", sizeof(ry_c));
    return ry_c;
}


int main()
{
    int ry_a[5];

    printf("size of ry_a: %lu\n", sizeof(ry_a));
    printf("size of ry_a element: %lu\n", sizeof(ry_a[0]));

    long int ry_b[5];

    printf("size of ry_b: %lu\n", sizeof(ry_b));
    printf("size of ry_b element: %lu\n", sizeof(ry_b[0]));

    int *ry_c;
    ry_c = return_array_pointer(5);
    printf("size of ry_c: %lu\n", sizeof(ry_c));
    printf("size of ry_c element: %lu\n", sizeof(ry_c[0]));
    printf("size of &ry_c: %lu\n", sizeof(&ry_c));
    printf("size of *ry_c: %lu\n", sizeof(*ry_c));

    int i;

    for ( i=0; i < 5; i++ ) {
        printf("%d\n", ry_c[i]);
    }

    /*
        ry_c has sizeof 8, its elements sizeof 4 -- but the array represented by ry_c has 5 elements.  Shouldn't it have sizeof 20?

     */

    int *ry_d;
    ry_d = return_array_pointer(5);
    printf("size of ry_d: %lu\n", sizeof(ry_d));
    printf("size of ry_d element: %lu\n", sizeof(ry_d[0]));

    for ( i=0; i < 5; i++ ) {
        printf("%d\n", ry_d[i]);
    }

    return 0;

}
