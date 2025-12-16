class Solution {
public:
    int canJump(int i, vector<int>& nums, int jumps, vector<int>& dp) {
        int n = nums.size();
        if (i >= n - 1)
            return jumps;

        if(dp[i]!=-1)return dp[i];

        int mini = INT_MAX;

        for (int ind = 1; ind <= nums[i] && i + ind < n; ind++) {
            mini = min(canJump(ind + i, nums, jumps + 1, dp), mini);
        }

        return dp[i] = mini;
    }

    int jump(vector<int>& nums) { 
        vector<int>dp(nums.size(), -1);

        return canJump(0, nums, 0, dp); 

        
        }
};