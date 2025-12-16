class Solution {
public:
    int canJump(int i, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        if (i >= n - 1)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int mini = INT_MAX;

        for (int ind = 1; ind <= nums[i] && i + ind < n; ind++) {
            int res = canJump(i + ind, nums, dp);
            if (res != INT_MAX)
                mini = min(mini, 1 + res);
        }

        return dp[i] = mini;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);

        return canJump(0, nums, dp);
    }
};