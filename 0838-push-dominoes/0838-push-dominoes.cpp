class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int>left(n,0),right(n,0);
        char prev = '.';
        int count =1;
        for(int i =0;i<n;i++){
            if(dominoes[i]=='R'){
                prev = 'R';
                count =1;
                continue;
            }
            else if(dominoes[i]== 'L'){
                prev = 'L';
            }
            if(prev == 'R' and dominoes[i] == '.'){
                right[i]= count;
                count++;
            }
        }
        prev = '.';
        count =1;
        for(int i =n-1;i>=0;i--){
            if(dominoes[i] == 'L'){
                prev = 'L';
                count =1;
                continue;
            }
            else if(dominoes[i] == 'R') prev = 'R';
            if(prev == 'L' and dominoes[i] == '.'){
                left[i] = count;
                count++;
            }
        }
        string res = "";

        for(int i =0;i<n;i++){
            if(left[i] == 0 and right[i] == 0) res += dominoes[i];
            else if(left[i] == 0) res += 'R';
            else if(right[i] == 0) res += 'L';
            else if(left[i] == right[i]) res += '.';
            else if(left[i] > right[i]) res += 'R';
            else {
            res += 'L';
            }
        }
        
        return res;
    }
};