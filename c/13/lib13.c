/*
    Tools for handling numbers as strings.

 */

#include <stdio.h>
#include <string.h>

char get_final_chr (char *num_str)
/*
    Returns the final character of a string.
 */
{
    int len = strlen(num_str);
    char val;
    val = num_str[len-1];
    return val;
}

void *strip_final_chr (char *num_str)
/*
    Strips the last character off a string
    works by side effect
 */
{
    int len = strlen(num_str);
    num_str[len-1] = '\0';

}

