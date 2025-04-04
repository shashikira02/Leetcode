class Solution {
public:

    void bfs(int row, int col,vector<vector<char>>& grid){

        queue<pair<int,int>>q;
        q.push({row, col});
        grid[row][col] ='0';
        int n = grid.size(), m = grid[0].size();

        vector<int> dRow = {-1, 0, 1, 0};
        vector<int> dCol = {0, 1, 0, -1};

        while(!q.empty()){
            int currRow = q.front().first, currCol = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) { 
                int nRow = currRow + dRow[i];
                int nCol = currCol + dCol[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == '1' ) {
                    grid[nRow][nCol] = '0';
                    q.push({nRow, nCol});
                }
                }
            }
        }


    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int count =0;

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] =='1'){
                    count++;
                    bfs(i,j,grid);
                }
            }
        }
        return count;
    }
};

