/*
PROBLEM:

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

PRIME FACTORIZATION PROCESS 
- Divide target number by prime numbers, greater than 1, in increasing sequence, until reaching a prime that divides the target evenly.
    - This prime is a factor of the target
    - The number of times that prime divides into the target, I term 'the dividend'
- If the dividend is not itself prime, find the prime factors of the dividend.  Each of these is a prime factor of the target.

Check a number for prime?
- I don't know of any other way than either consult a list, or do prime factorization until the numer itself emerges in the sequence of primes

CONCEPTUAL REQUIREMENTS
- generate a sequence of primes

 */



/*

PATH:
- write code for generation of list of primes
    - go to generate_primes.c
- learn to include code from one file in another
    - eg, bring prime list function into this file

 */
