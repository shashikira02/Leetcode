class Solution {
public:
    bool isPowerOfFour(int n) {

        if (n <= 0) return false;
        /*
            if n = 16 in binary == 10000;
            n - 1 == 01111 ==> n & (n - 1) == 00000;
            (n & 0xAAAAAAAA) == 0 checks if the bit representation of n has an 
            even number of zeros between every pair of 1s.
            This ensures that n is a power of 4 since powers of 4 have their 1 bits 
            positioned at even positions in binary representation
        */
        return (n & (n - 1)) == 0 && (n & 0xAAAAAAAA) == 0;

    }
};