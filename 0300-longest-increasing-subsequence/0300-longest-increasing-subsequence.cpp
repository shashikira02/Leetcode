class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); // Size of the input array
        vector<int>next(n + 1, 0), curr(n+1,0); // {ind, prev_ind}

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
                int len = next[prev_ind + 1]; // Skip the current element
                if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
                    len = max(len, 1 + next[ind + 1]); // Include the current element
                }
                curr[prev_ind + 1] = len; // Update the correct cell
            }
            next = curr ;
        }

        return curr[0]; // The result is stored here
    }
};
