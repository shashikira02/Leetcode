class Solution {
public:
  int bfs(int row, int col, vector<vector<int>> & vis, vector<vector<int>>& grid){

        vis[row][col] =1;
        int area =0;
        queue<pair<int,int>>q;
        q.push({row, col});

        int n = grid.size(), m = grid[0].size();

        vector<int> dRow = {-1, 0, 1, 0};
        vector<int> dCol = {0, 1, 0, -1};

        while(!q.empty()){
            int currRow = q.front().first, currCol = q.front().second;
            q.pop();
            area++;

            for (int i = 0; i < 4; i++) { 
                int nRow = currRow + dRow[i];
                int nCol = currCol + dCol[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && !vis[nRow][nCol]) {
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
                }
            }

            return area;
        }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        int maxArea = 0;

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!vis[i][j] && grid[i][j] ==1){
                    int currArea = bfs(i,j,vis,grid);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }
};