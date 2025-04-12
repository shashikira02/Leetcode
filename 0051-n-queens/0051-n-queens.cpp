class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n){
        int tempRow = row, tempCol = col;

        while(row >= 0 && col>=0){ // Check upper diagonal
            if(board[row][col] == 'Q')return false;
            row--, col--;
        }
        // Check left column
        col = tempCol;
        row = tempRow;
        while(col >= 0){
            if(board[row][col] == 'Q')return false;
            col--;
        }
        // Check lower diagonal
        col = tempCol;
        row = tempRow;
        while(row<n && col >= 0){
            if(board[row][col] == 'Q')return false;
            col--;
            row++;
        }
        return true;

    }
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
      if (col == n) {// All queens placed
        ans.push_back(board);
        return;
      }
      // Try placing queen in each row
      for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board,n)) {
          board[row][col] = 'Q';// Place queen
          solve(col + 1, board, ans, n);
          board[row][col] = '.'; // Remove queen (backtrack)        
        }
      }
    }

  public:
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> ans;
      vector<string> board(n); // empty board
      string s(n, '.'); // Initialize empty row
      for (int i = 0; i < n; i++) {
        board[i] = s;  // Fill board with empty rows
      }
      solve(0, board, ans, n);
      return ans;
    }
};