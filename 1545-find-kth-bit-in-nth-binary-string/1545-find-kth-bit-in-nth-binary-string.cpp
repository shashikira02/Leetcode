class Solution {
public:
    char findKthBit(int n, int k) {
        // Find the position of the rightmost set bit in k
        // This helps determine which "section" of the string we're in
        int positionInSection = k & -k;

        // Determine if k is in the inverted part of the string
        // This checks if the bit to the left of the rightmost set bit is 1
        bool isInInvertedPart = ((k / positionInSection) >> 1 & 1) == 1;

        bool originalBitIsOne = (k & 1) == 0;

        if (isInInvertedPart) {

            return originalBitIsOne ? '0' : '1';
        } else {

            return originalBitIsOne ? '1' : '0';
        }
    }
};