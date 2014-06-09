/*
    Reads lines from a file into an array of strings.

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "numbers.txt"

main ()
{

    char ry[1000][200];

    int i = 0, j = 0, k;
    FILE *fp;
    fp = fopen(FILE_NAME, "r");    
    while ( !feof(fp) ) {
        fgets(ry[i], sizeof(ry[i]), fp);
        i++;
    }

    
    for ( j=0; j<=i; j++) {
        // strip off line termination characters
        for ( k=0; k <= sizeof(ry[j]); k++ ) {
            if ( ry[j][k] == '\n' ) {
                ry[j][k] = '\0';
            }
        }
    }


/*
    for ( j=0; j<=i; j++) {
        printf("%s", ry[j]);
    }
 */


}
