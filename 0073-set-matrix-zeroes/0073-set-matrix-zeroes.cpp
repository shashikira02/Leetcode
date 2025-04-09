class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int col0 = 1; 
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(matrix[i][j] == 0){
                    //i'th row
                    matrix[i][0] =0;

                    //j'th col
                    if(j != 0)matrix[0][j]=0;
                    else col0 = 0;
                }
            }
        }

        //changing everything except first row and col
        for(int i = 1;i<n;i++){
            for(int j = 1;j<m;j++){
                if(matrix[i][j] != 0){
                    //check if row or col is 0 then mark the [i][j] to 0
                    if(matrix[0][j] == 0 || matrix[i][0] ==0)matrix[i][j] =0;
                }
            }
        }
        //check if first row is 0 then the whole col will be 0
        if(matrix[0][0] == 0){
            for(int j =0;j<m;j++)matrix[0][j] =0;
        }
        //check if first col is 0 then the whole row will be 0
        if(col0 == 0){
            for(int i =0;i<n;i++)matrix[i][0] = 0;
        }
    }
};