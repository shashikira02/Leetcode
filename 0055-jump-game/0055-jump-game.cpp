class Solution {
public:
    bool jump(int i, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();

        if (i == n - 1 || i >= n)
            return true;
        if(dp[i]!=-1)return dp[i];

        for (int ind = i + 1; ind <= i + nums[i] && i < n; ind++) {
            if (jump(ind, nums, dp))
                return dp[i]= 1;
        }

        return dp[i]= 0;
    }

    bool canJump(vector<int>& nums) {

        vector<int> dp(nums.size(), -1);

        return jump(0, nums, dp);
    }
};