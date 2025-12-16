class Solution {
public:
    void bfs(int row, int col, vector<vector<bool>>& vis,
             vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vis[row][col] = true;

        queue<pair<int, int>> q; //{row, col}
        q.push({row, col});

        vector<int> dRow = {-1, 0, 1, 0};
        vector<int> dCol = {0, 1, 0, -1};
        while (!q.empty()) {
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nRow = currRow + dRow[i];
                int nCol = currCol + dCol[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                    vis[nRow][nCol] == false && grid[nRow][nCol] == '1') {
                    vis[nRow][nCol] = true;
                    q.push({nRow, nCol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    count++;
                    bfs(i, j, vis, grid);
                }
            }
        }

        return count;
    }
};