/*
    PROBLEM
    Work out the first ten digits of the sum of the following one-hundred 50-digit numbers
    - numbers held in numbers.txt
 
    ANSWER:
        5537376230
 */

/*
    APPROACH

    Assume that simply summing the numbers results in a number larger than memory can handle.

    - Read each number in as a string
    - Get the last digit of each number (convert from character to integer)
        - strip that last digit off each number string?
    - Sum these digits
        - put result into stack of numbers, stripping off the last digit
        - put that last digit into summary array

    - repeat process for each of the 50 digits
        - at end, summary array will contain the digits of the sum, in reverse order

    TODO
    - Add additional documentation for why this works?
    - revise to use arrays of dynamically allocated size?
    - revise to take name of data file from command line
    - revise to use header files

    STATUS

    Works

    Compilationg generates some mysterious warnings

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../euler.h"
#include "../euler.c"
#include "lib13.c"

#define NUMBER_STR_SIZE 400
#define NUMBER_OF_NUMBERS 10000
#define FILE_NAME "numbers.txt"



/*--------------------------------------------------------------------------*/
int sum_last_str(char numbers_ry[NUMBER_OF_NUMBERS][NUMBER_STR_SIZE], int *digits_ry) 
/*
    Strips and the last digits of the numbers in numbers_ry, putting the last
    digit of that sum into digits_ry and putting that sum, stripped of that
    last digit, into numbers_ry

    numbers_ry:
        An array of character strings representing numbers

    digits_ry
        A pointer to an array that holds the digits of the sum

    returns:
        halt: a 1 or 0, depending on whether the numbers_ry passed in is exhausted.

 */
{
    int sum = 0, i = 0, halt = 1;

    char val[NUMBER_STR_SIZE] = "blank";

    // loop numbers_ry, sum and strip final digits
    while ( 1 ) {
        strcpy(val, numbers_ry[i]);

        // weed: I would rather put the loop ending condition in the while expression, but am not sure how to do so here
        if ( strcmp(val, "-1") == 0 ) {
            break;
        }

        // If array element is exhausted, skip it
        if ( strlen(val) == 0 ) {
            i++;
            continue;
        }

        sum += get_final_chr(val) - '0'; // convert char to int
        strip_final_chr(val);   // weed: works by side effect.  revise to return value?
        strcpy(numbers_ry[i], val);
        if ( strcmp(numbers_ry[i], "0") != 0 ) {
            halt = 0;
        }
        i++;
    }

    // convert sum to string

    char sum_str[NUMBER_STR_SIZE];
    sprintf(sum_str, "%d", sum);    // converts integer to character

    // Find end of digits_ry, put last digit of sum there, reset -1 element

    int j = 0;
    int val2;

    while ( ( val2 = digits_ry[j] ) != -1 ) {
        j++;
    }

    digits_ry[j++] = get_final_chr(sum_str) - '0';
    digits_ry[j] = -1;

    // put sum, stripped of last digit, in numbers_ry, and reset -1 element
    strip_final_chr(sum_str);
    strcpy(numbers_ry[i++], sum_str);
    strcpy(numbers_ry[i], "-1");

    return halt;
}


/*--------------------------------------------------------------------------*/
char * read_in_data( const char *file_name)
/*
    Reads data from file_name, returns that data as an array of strings.

    Intended for a file holding a list of numbers as strings.

 */
{
    /*
        QUESTION:
        - How to use dynamically sized arrays here?

        thoughts:
        - will have to start with some initial values

        - while reading in number strings, check if string is larger than NUMBER_STR_SIZE
            - how?
        - if string is larger, reset size of array 
            - but then, how to capture line than first signalled size problem?  Would this be done with some sort of file location functionality?


        - how to detect that strings available are greater than NUMBER_OF_NUMBERS?  

     */
    static char data[NUMBER_OF_NUMBERS][NUMBER_STR_SIZE];

    int i = 0, j = 0, k;
    FILE *fp;
    fp = fopen(file_name, "r");    
    while ( !feof(fp) ) {
        fgets(data[i], sizeof(data[i]), fp);
        i++;
    }

    strcpy(data[i], "-1");
    
    for ( j=0; j<=i; j++) {
        // strip off line termination characters
        for ( k=0; k <= sizeof(data[j]); k++ ) {
            if ( data[j][k] == '\n' ) {
                data[j][k] = '\0';
            }
        }
    }

    //-return data;
        // above gets "warning: return from incompatible pointer type [enabled by default]"
    return (char *)data;
        // weed: why does casting to char * remove the warning?  I thought I was already returning a pointer array
}


/*--------------------------------------------------------------------------*/
int * add_number_strings(
    char data[NUMBER_OF_NUMBERS][NUMBER_STR_SIZE]
)
{

    /* set up other arrays and variables */

    static int digits_ry[1000] = {-1};
    int halt = 0;

    /* 
        Add final digits of strings in array, until those strings are
        exhausted, storing the final digit of that sum in digits_ry

    */

    while ( !halt ) {
        halt = sum_last_str(data, digits_ry);
    }

    /* reverse the digits of the result array */
    reverse_ry(digits_ry);

    return digits_ry;

}

/*--------------------------------------------------------------------------*/
int main() 
{

    /* Read file into the array */

    char * data;
    data = read_in_data(FILE_NAME);

    /* Sum numbers as strings */

    int * digits_ry;
    digits_ry = add_number_strings(data);

    /* print out the answer */
    int i = 0, val;
    while ( ( val = digits_ry[i++] ) != -1  ) {
        printf("%d\n", val);
    }

}


/*--------------------------------------------------------------------------*/
