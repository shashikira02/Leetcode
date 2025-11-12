class Solution {
    int findMaxi(vector<string>& strs, int m, int n, int ind, vector<vector<vector<int>>> &dp) {
        if (ind == strs.size())
            return 0;
        if(dp[m][n][ind] !=-1){
            return dp[m][n][ind];
        }

        int zeros = count(strs[ind].begin(), strs[ind].end(), '0');
        int ones = strs[ind].size() - zeros;

        if (m >= zeros && n >= ones) {
            return dp[m][n][ind] = max(1 + findMaxi(strs, m - zeros, n - ones, ind + 1, dp),
                       findMaxi(strs, m, n, ind + 1, dp));
        }

        return dp[m][n][ind]= findMaxi(strs,m,n, ind+1, dp);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(m+1, vector<vector<int>>(n+1,vector<int>(strs.size(), -1)));
        return findMaxi(strs, m, n, 0, dp);
    }
};