class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int suff = 1, pre = 0, ans = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                suff++;
            } else {
                pre = suff;
                suff = 1;
            }
            ans = max({ans, suff / 2, min(pre, suff)});
        }

        return ans;
    }
};