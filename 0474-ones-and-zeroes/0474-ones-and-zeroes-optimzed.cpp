class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= strs.size(); i++) {
            int zeros = count(strs[i - 1].begin(), strs[i - 1].end(), '0');
            int ones = strs[i - 1].size() - zeros;
            for (int j = m; j >= zeros; j--) {
                for (int k = n; k >= ones; k--) {

                    dp[j][k] = max(1 + dp[j - zeros][k - ones], dp[j][k]);
                }
            }
        }

        return dp[m][n];
    }
};