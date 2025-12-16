class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n =grid.size();
        int m =grid[0].size();

        vector<vector<int>>vis(grid);
        queue<pair<pair<int, int>, int>> q; //{row, col, time}

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }

        vector<int> row = {-1, 0, 1, 0};
        vector<int> col = {0, 1, 0, -1};
        int maxTime = 0;

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int r = node.first.first;
            int c = node.first.second;
            int time = node.second;

            maxTime = max(maxTime, time);

            for (int i = 0; i < 4; i++) {
                int nRow = r + row[i];
                int nCol = c + col[i];

                if(nRow>=0 && nCol>=0 && nRow<n && nCol<m && vis[nRow][nCol]==1){
                    q.push({{nRow, nCol}, time+1});
                    vis[nRow][nCol]=2;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 1)
                    return -1;
            }
        }

        return maxTime;
    }
};