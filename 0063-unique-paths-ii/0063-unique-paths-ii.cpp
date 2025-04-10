class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0; // Starting point is blocked.

        vector<int> prev(m, 0);

        for (int i = 0; i < n; i++) {
            vector<int> curr(m, 0);
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[i][j] == 1) {
                    curr[j] = 0; // No paths through an obstacle.
                } else if (i == 0 && j == 0) {
                    curr[j] = 1; // Starting point.
                } else {
                    int top = (i > 0) ? prev[j] : 0;
                    int left = (j > 0) ? curr[j-1] : 0;
                    curr[j] = top + left;
                }
            }
            prev = curr; 
        }

        return prev[m-1];
    }
};
