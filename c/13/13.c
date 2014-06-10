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


    TECHNIQUES TO LEARN
    - read data from file into C program
        - really? could also just put numbers in one large array
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int sum = 0, i = 0, halt = 1, digit_int;

    char val[NUMBER_STR_SIZE] = "blank";
    char digit_chr;

    // loop numbers_ry, sum and strip final digits
    while ( 1 ) {
        strcpy(val, numbers_ry[i]);

        if ( strcmp(val, "-1") == 0 ) {
            break;
        }

        if ( strlen(val) == 0 ) {
            i++;
            continue;
        }

        sum += get_final_chr(val) - '0'; // convert char to int
        strip_final_chr(val);
        strcpy(numbers_ry[i], val);
        if ( strcmp(numbers_ry[i], "0") != 0 ) {
            halt = 0;
        }
        i++;
    }

    // convert sum to string

    char sum_str[NUMBER_STR_SIZE];
    sprintf(sum_str, "%d", sum);

    // Find end of digits_ry, put last digit of sum there, reset -1 element

    int j = 0;
    int val2;

    while ( ( val2 = digits_ry[j] ) != -1 ) {
        j++;
    }

    char sum_final_char;
    int sum_final_int;

    digits_ry[j++] = get_final_chr(sum_str) - '0';
    digits_ry[j] = -1;

    // put sum, stripped of last digit, in numbers_ry, and reset -1 element
    strip_final_chr(sum_str);
    strcpy(numbers_ry[i++], sum_str);
    strcpy(numbers_ry[i], "-1");

    return halt;
}


/*--------------------------------------------------------------------------*/
void read_in_data(char *file_name, char data[NUMBER_OF_NUMBERS][NUMBER_STR_SIZE])
{
    int ii = 0, jj = 0, kk;
    FILE *fp;
    fp = fopen(file_name, "r");    
    while ( !feof(fp) ) {
        fgets(data[ii], sizeof(data[ii]), fp);
        ii++;
    }

    strcpy(data[ii], "-1");
    
    for ( jj=0; jj<=ii; jj++) {
        // strip off line termination characters
        for ( kk=0; kk <= sizeof(data[jj]); kk++ ) {
            if ( data[jj][kk] == '\n' ) {
                data[jj][kk] = '\0';
            }
        }
    }
}


/*--------------------------------------------------------------------------*/
void add_number_strings(char data[NUMBER_OF_NUMBERS][NUMBER_STR_SIZE], int digits_ry[1000])
{

    /* set up other arrays and variables */

    int summary_ry[1000];
    int i = 0, j= 0, val = 0, sum = 0, halt = 0;

    /* 
        Add final digits of strings in array, until those strings are
        exhausted, storing the final digit of that sum in digits_ry

    */

    while ( !halt ) {
        halt = sum_last_str(data, digits_ry);
    }

    /* reverse the digits of the result array */
    reverse_ry(digits_ry);
}

/*--------------------------------------------------------------------------*/
int main() 
{

    /* Read file into the array */

        /* revise function to return array, or pointer to array */
    char data[NUMBER_OF_NUMBERS][NUMBER_STR_SIZE];
    read_in_data(FILE_NAME, data);

    /* Sum numbers as strings */
        /* revise function to return digits_ry, or pointer thereto */
    int digits_ry[1000] = {-1};
    add_number_strings(data, digits_ry);

    /* print out the answer */
    int i = 0, val;
    while ( ( val = digits_ry[i++] ) != -1  ) {
        printf("%d\n", val);
    }

}


/*--------------------------------------------------------------------------*/
