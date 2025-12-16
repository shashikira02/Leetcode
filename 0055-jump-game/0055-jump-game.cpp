class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 0);
        dp[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--) {
            for (int ind = i + 1; ind <= i + nums[i] && ind < n; ind++) {
                if (dp[ind]) {
                    dp[i] = 1;
                    break;
                }
            }

        }

        return dp[0];
    }
};