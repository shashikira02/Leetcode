class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(); // Grid dimensions

        queue<pair<pair<int,int>,int>> q; // BFS queue: {{row, col}, time}
        int freshCount = 0;              // Count of fresh oranges

        // Initialize the queue and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) { // Rotten orange
                    q.push({{i, j}, 0}); // Push its position and time = 0
                } else if (grid[i][j] == 1) { // Fresh orange
                    freshCount++;            // Increment fresh orange count
                }
            }
        }

        int maxTime = 0; // Variable to track the maximum time elapsed
        vector<int> delRow = {-1, 0, 1, 0}; // Direction array for row movements
        vector<int> delCol = {0, 1, 0, -1}; // Direction array for column movements

        // BFS to rot adjacent oranges
        while (!q.empty()) {
            int row = q.front().first.first;  // Current orange's row
            int col = q.front().first.second; // Current orange's column
            int time = q.front().second;      // Time taken to rot
            maxTime = max(maxTime, time);     // Update maxTime
            q.pop();                          // Remove the current orange from the queue

            // Check all 4 possible directions
            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i]; // Compute neighboring row
                int nCol = col + delCol[i]; // Compute neighboring column
                // Check validity and if the neighbor is fresh
                if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < m &&
                    grid[nRow][nCol] == 1) {
                    q.push({{nRow, nCol}, time + 1}); // Mark neighboring orange as rotten with time + 1
                    grid[nRow][nCol] = 2;             // Mark it as rotten
                    freshCount--;                     // Decrement fresh orange count
                }
            }
        }

        // If there are remaining fresh oranges, return -1
        if (freshCount > 0) return -1;

        return maxTime; // Return the total time taken to rot all oranges
    }
};
