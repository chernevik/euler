int *prime_list_seg_fault(int n) {
/* 
    This code segment faults.

    Returns pointer to array listing primes less than n
    Algorithm is Sieve of Eratosthenes


    STATUS:
    - returns segmentation fault on execution
    - I suspect the issue is related to usage of merge_sorted

 */

    // create counter variables;
    int i, j, k, l;
    int pA_ndx = 0;

    // create array to hold primes and to be returned
    int *primeArr;
    primeArr = malloc(sizeof(int) * ( n + 1 ) );

    int candidates[n];
    int *not_primes;
    int multiples[n];
    int val, np_val, val_multiple;

    // Return basic list -- to establish proper pointer handling

//-w-    // initialize array values
//-w-    for (i=0; i<n; i++) 
//-w-    {
//-w-        primeArr[i] = i * 2;
//-w-    }
//-w-
//-w-    // Send end of array value
//-w-    primeArr[n] = -1;
//-w-

    // initialize primeArr values

    // populate candidates

    for ( i = 2; i < n; i++ ) {
        candidates[i-2] = i;
    }

    i++;
    candidates[i-2] = -1;
    
    // Scan candidates for prime possibility
    while ( ( val = candidates[j] ) != -1 ) {
        // check if val is in not_primes
        int prime_flag = 1;
        int k = 0;
        while ( ( np_val = not_primes[k] ) >= val ) {
            if ( np_val == val ) {
                prime_flag = 0;
            }
        }

        // if val is not in not_primes, put in prime, and put multiples of val in not_prime 
        if ( prime_flag == 1 ) {
            primeArr[pA_ndx] = val;
            pA_ndx++;

            // collect multiples of val less than or equal to n
            int l = 0;
            while ( ( val_multiple = l * val ) <= n ) {
                multiples[l] = val_multiple;
            }

            // merge multiples with not_primes
            // suspect that segmentation fault is related to this line
            not_primes = merge_sorted(not_primes, multiples);
        }

    }

    return primeArr;

}
