class Solution {
public:
    int bitwiseComplement(int n) {
        
        if(n == 0) return 1;
        int numBits = log2(n) + 1;
        int mask = (1 << numBits) - 1;
        return n ^ mask;
    }
};