class Solution {
public:
    int dp[605][101][101];
    int solve(vector<string>& strs, int m, int n,int idx){
        if(idx==strs.size()) return 0;

        if(dp[idx][m][n]!=-1) return dp[idx][m][n];

        int cnt_0 = 0,cnt_1 = 0,ans = 0;

        for(int j = 0;j<strs[idx].size();j++){
            if(strs[idx][j]=='1') cnt_1++;
            else cnt_0++;
        }

        if(m>=cnt_0 && n>=cnt_1) ans = max(ans,1+solve(strs,m-cnt_0,n-cnt_1,idx+1));
        ans = max(ans,solve(strs,m,n,idx+1));

        return dp[idx][m][n] = ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(strs,m,n,0);
    }
};