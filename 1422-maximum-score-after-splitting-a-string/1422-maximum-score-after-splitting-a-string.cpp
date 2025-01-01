class Solution {
public:
    int maxScore(string s) {
        int ones = 0, zeros = 0;
        int maxScore = INT_MIN;
        int n = s.size();
        for (char c : s) {
            if (c == '1') {
                ones++;
            }
        }
        int leftZeros = 0, rightOnes = ones;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') {
                leftZeros++;
            } else {
                rightOnes--;
            }
            maxScore = max(maxScore, leftZeros + rightOnes);
        }

        return maxScore;
    }
};
