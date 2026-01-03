class Solution {
public:
     const int MOD = 1e9;
    vector<string> possibleStates = {"RYG", "RGY", "RYR", "RGR", "YRG", "YGR",
                                  "YGY", "YRY", "GRY", "GYR", "GRG", "GYG"};

    int solve(int n , int prev){
        if(n == 0)return 1;

        int ans =0;
        string last = possibleStates[prev];

        for(int curr = 0;curr<12;curr++){
            if(curr == prev)continue;
            string currPath = possibleStates[curr];
            bool conflict = false;
            
            for(int col =0;col<3;col++){
                if(currPath[col] == last[col]){
                    conflict = true;
                    break;
                }
            }

            if(!conflict){
                ans = (ans+solve(n-1, curr))%MOD;
            }
        }

        return ans;

    }


    int numOfWays(int n) {
        int ans = 0;

        for(int i =0;i<12;i++){
            ans = (ans + solve(n-1, i))%MOD;
        }

        return ans;

    }
};