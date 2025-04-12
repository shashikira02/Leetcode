class Solution {
public:
    void solve(int col, vector<string>& board, vector<vector<string>>& ans,
               vector<int>& leftrow, vector<int>& upperDiagonal,
               vector<int>& lowerDiagonal, int n) {
        if (col == n) {
            ans.push_back(board); // Store valid configuration
            return;
        }
        for (int row = 0; row < n; row++) {
            // Check if position is safe
            if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 &&
                upperDiagonal[n - 1 + col - row] == 0) {
                board[row][col] = 'Q'; // Place queen
                leftrow[row] = 1;  // Mark row as occupied
                lowerDiagonal[row + col] = 1; // Mark lower diagonal
                upperDiagonal[n - 1 + col - row] = 1; // Mark upper diagonal
                solve(col + 1, board, ans, leftrow, upperDiagonal,
                      lowerDiagonal, n);
                board[row][col] = '.'; // Backtrack
                leftrow[row] = 0; // Unmark row
                lowerDiagonal[row + col] = 0; // Unmark lower diagonal
                upperDiagonal[n - 1 + col - row] = 0; // Unmark upper diagonal
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n); // Create empty board
        string s(n, '.'); // Initialize empty row
        for (int i = 0; i < n; i++) {
            board[i] = s; // Fill board with empty rows
        }
        // leftrow: Tracks occupied rows (size n).
        // upperDiagonal and lowerDiagonal: Track occupied diagonals (size 2 * n - 1). These ensure no two queens conflict.
        vector<int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0),
            lowerDiagonal(2 * n - 1, 0);
        solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};