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

char *strip_final_crh (char *num_str)
/*
    Strips the last character off a string
 */
{
    int len = strlen(num_str);
    num_str[len-1] = '\0';

}

/*
int main() {

    char num[4] = "123";

    printf("the number is %s\n", num);

    char last;
    last = get_final_chr(num);

    printf("the last digit is %c\n", last);

    strip_final_crh(num);
    printf("number is now %s\n", num);

    int final_num = last - '0';
    printf("%d is an integer, %d\n", final_num, final_num * final_num);
}
 */
