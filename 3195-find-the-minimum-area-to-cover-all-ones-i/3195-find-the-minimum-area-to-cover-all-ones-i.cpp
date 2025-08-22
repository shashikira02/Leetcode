class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int minRow =n, maxRow = 0;
        int minCol =m, maxCol = 0;

        for(int row = 0; row< n;row++){
            for(int col = 0; col<m ;col++){
                if(grid[row][col] == 1){
                    minRow = min(minRow, row);
                    maxRow = max(maxRow, row);
                    minCol = min(minCol, col);
                    maxCol = max(maxCol, col);
                }
            }
        }
        return (maxRow - minRow +1)*(maxCol - minCol +1 );
    }
};