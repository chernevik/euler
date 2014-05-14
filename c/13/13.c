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


int main() 
{
    // STUB CODE

    int summary_ry[1000];

    NOW WHAT? 

}
