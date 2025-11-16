class Solution {
public:
    int numSub(string s) {
        int MOD = 1e9 + 7;
        long long res = 0;
        int onesCount = 0;

        for (auto c : s) {
            if (c == '1') {
                onesCount++;
                res += onesCount;
            } else {
                onesCount = 0;
            }
        }
        return res % MOD;
    }
};