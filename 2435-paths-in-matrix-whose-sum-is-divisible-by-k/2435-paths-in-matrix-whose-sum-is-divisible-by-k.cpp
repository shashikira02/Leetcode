class Solution {
public:
    int n, m;
    unsigned int mod = 1e9+7;
    int recursive(vector<vector<int>>& grid, int k, int i, int j, int rem,
                  vector<vector<vector<int>>>& dp) {
        if (i == n - 1 && j == m - 1)
            return (rem + grid[i][j]) % k == 0;

        if (dp[i][j][rem] != -1)
            return dp[i][j][rem];

        int right = 0, down = 0;

        if (i + 1 < n)
            down = recursive(grid, k, i + 1, j, (rem + grid[i][j]) % k, dp);
        if (j + 1 < m)
            right = recursive(grid, k, i, j + 1, (rem + grid[i][j]) % k, dp);

        return dp[i][j][rem] = (right + down) % mod;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));

        return recursive(grid, k, 0, 0, 0, dp);
    }
};