class Solution {
public:
    int func(int i, int n, vector<int>& dp) {
        if(i>n)return 0;
        if(i == n)return 1;
        if(dp[i] !=-1) return dp[i];

        return dp[i] = func(i+1, n, dp) + func(i+2, n, dp);
    }
    int climbStairs(int n) { 
        vector<int>dp(n, -1);
        return func(0,n, dp); 
    }
};