class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<vector<char>> rows(9, vector<char>(9, 0));
        vector<vector<char>> cols(9, vector<char>(9, 0));
        vector<vector<char>> grid(9, vector<char>(9, 0));

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){

                if(board[i][j] == '.'){
                    continue;
                }

                char digit = board[i][j];
                int digitIndex = digit - '1';

                if(rows[i][digitIndex] != 0 || cols[j][digitIndex] != 0 ||
                    grid[(i/3)*3 + j/3][digitIndex] != 0){
                    return false;
                }

                rows[i][digitIndex] = 1;
                cols[j][digitIndex] = 1;
                grid[(i/3)*3 + j/3][digitIndex] = 1;
            }
        }
        return true;
    }
};