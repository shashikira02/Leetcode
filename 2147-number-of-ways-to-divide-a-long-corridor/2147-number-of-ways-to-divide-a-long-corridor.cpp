class Solution {
public:
    int MOD = 1e9 + 7;

    int dfs(int i, int seats, string& corridor, vector<vector<int>>& dp) {
        if (i == corridor.length()) {
            return (seats == 2) ? 1 : 0;
        }
        int res = 0;

        if(dp[i][seats] != -1)return dp[i][seats];

        if (seats == 2) {
            if (corridor[i] == 'S') {
                res = dfs(i + 1, 1, corridor, dp);
            } else {
                res = (dfs(i + 1, 0, corridor, dp) + dfs(i + 1, 2, corridor, dp)) % MOD;
            }
        } else {
            if (corridor[i] == 'S') {
                res = dfs(i + 1, seats + 1, corridor, dp);
            } else {
                res = dfs(i + 1, seats, corridor, dp);
            }
        }

        return dp[i][seats] = res;
    }

    int numberOfWays(string corridor) {
        vector<vector<int>> dp(corridor.size(),
                               vector<int>(3, -1));

        return dfs(0, 0, corridor, dp);
    }
};
