class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); // Size of the input array
        vector<int> dp(n, 1); // dp[i] starts at 1, since every element can form an LIS of length 1
        int maxi = 1; // Variable to track the maximum LIS length

        // Iterate through each element
        for (int i = 0; i < n; i++) {
            // Check all previous elements for LIS condition
            for (int prev = 0; prev < i; prev++) {
                // If nums[prev] < nums[i], we can extend the LIS ending at prev to include nums[i]
                if (nums[prev] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[prev]); // Update dp[i] to the longest LIS ending at i
                }
            }
            // Update the global maximum LIS length
            maxi = max(maxi, dp[i]);
        }

        return maxi; // Return the length of the longest increasing subsequence
    }
};
