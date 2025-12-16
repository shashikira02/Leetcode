class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        grid[row][col] = '0';

        vector<int> dRow = {-1, 0, 1, 0};
        vector<int> dCol = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                grid[nRow][nCol] == '1') {
                dfs(nRow, nCol, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid);
                }
            }
        }

        return count;
    }
};