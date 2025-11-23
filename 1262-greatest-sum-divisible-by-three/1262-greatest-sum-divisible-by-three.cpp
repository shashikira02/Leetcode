class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int>dp(3, INT_MIN);
        dp[0]=0;
        for(int num : nums){
            int rem = num%3;
            vector<int>next = dp;
            for(int r =0;r<3;r++){
                if(dp[r]==INT_MIN)continue;
                int sum = dp[r]+num;
                int remainder = (r+num)%3;
                next[remainder]=max(next[remainder],sum);
            }
            dp=next;
        }
        return dp[0];
    }
};