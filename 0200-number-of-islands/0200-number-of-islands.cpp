class Solution {
public:
    void dfs(int row, int col, vector<vector<bool>>& vis,
             vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
                
        vis[row][col] = true;

        vector<int> dRow = {-1, 0, 1, 0};
        vector<int> dCol = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                vis[nRow][nCol] == false && grid[nRow][nCol] == '1') {
                    dfs(nRow, nCol, vis, grid);
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
                    dfs(i, j, vis, grid);
                }
            }
        }

        return count;
    }
};