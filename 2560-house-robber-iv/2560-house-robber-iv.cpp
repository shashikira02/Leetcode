class Solution {
public:
    int solve(int i, int k, vector<int>& nums, vector<vector<int>>& dp) {
        if (k == 0)
            return 0;

        if (i >= nums.size()) {
            return  INT_MAX;
        }
        
        if(dp[i][k] != -1)return dp[i][k];

        int take = max(nums[i], solve(i + 2, k - 1, nums, dp));

        int skip = solve(i + 1, k, nums, dp);

        return dp[i][k] = min(take, skip);
    }

    int minCapability(vector<int>& nums, int k) { 
        vector<vector<int>>dp(nums.size()+1, vector<int>(k+1, -1));
        return solve(0, k, nums, dp); 
    }
};