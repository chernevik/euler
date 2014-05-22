/*
    PROBLEM
    Work out the first ten digits of the sum of the following one-hundred 50-digit numbers
    - numbers held in numbers.txt
 
 */

/*
    APPROACH

    Assume that simply summing the numbers results in a number larger than memory can handle.

    - Read each number in as a string
        - really? just put data into C code?

    - Get the last digit of each number (convert from character to integer)
        - strip that last digit off each number string?
    - Sum these digits
        - put result into stack of numbers, stripping off the last digit
        - put that last digit into summary array

    - repeat process for each of the 50 digits
        - at end, summary array will contain the digits of the sum, in reverse order

    TODO
    Add additional documentation for why this works


    TECHNIQUES TO LEARN
    - read data from file into C program
        - really? could also just put numbers in one large array

    - string handling to get last digit
        - really? don't I already have library functions for getting the last digit of a number?  see palindrome code
        - see get_final and strip_final in euler library
        

 */

#include <stdio.h>
#include <stdlib.h>

#include "../euler.c"


int sum_last(int *numbers_ry, int *digits_ry) 
/*
    Strips and the last digits of the numbers in numbers_ry, putting the last digit of that sum into digits_ry and putting that sum, stripped of that last digit, into numbers_ry

 */
{
    int sum = 0;
    int i = 0;

    int halt = 1;

    int val;

    while ( ( val = numbers_ry[i] ) != -1 ) {
        //-printf("%d\n", val);
        if ( val == 0 ) {
            i++;
            continue;
        }
        sum += get_final(val);
        numbers_ry[i] = strip_final(val);
        if ( numbers_ry[i] != 0 ) {
            halt = 0;
        }
        i++;
    }

    // Find end of digits_ry, put last digit of sum there, reset -1 element

    int j = 0;
    int val2;

    while ( ( val2 = digits_ry[j] ) != -1 ) {
        j++;
    }

    digits_ry[j++] = get_final(sum);
    digits_ry[j] = -1;

    // put sum, stripped of last digit, in numbers_ry, and reset -1 element
    numbers_ry[i++] = strip_final(sum);
    numbers_ry[i] = -1;

    return halt;

}

int main() 
{
    // STUB CODE

    int data[100] = {
        124,
        521,
        -1
    };

    int digits_ry[1000] = {-1};

    int summary_ry[1000];
    int i = 0, j= 0, val = 0;
    int sum = 0;

    /* 
        loop and following code sums last digits, puts last digit found in array, strips last digit off each value in array, and adds summed value (stripped of last value) to array of values to be summed
        - how to make this a function of its own?
        
        function must do the following:
        - put last digit of last digit sums into summary array
        - strip last digit from all values in array
        - add stripped sum of last digits to array of values to be summed
        
        do all of this by side effect, using pointers?


    */

    int halt = 0;

    while ( !halt ) {
        halt = sum_last(data, digits_ry);
    }

    reverse_ry(digits_ry);

    while ( ( val = digits_ry[i++] ) != -1 ) {
        printf("%d\n", val);
    }

}
