class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int> next(n+1,0), curr(n+1,0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (text1[i] == text2[j])
                    curr[j] = 1 + next[j + 1];

                else curr[j] = max(next[j], curr[j + 1]);
            }
            next =curr;
        }
        return curr[0];
    }
};