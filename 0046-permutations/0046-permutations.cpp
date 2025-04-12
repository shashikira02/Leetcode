class Solution {
public:
    void permutations(vector<int>& nums, vector<int>& permutation,
                      vector<vector<int>>& ans, vector<bool>& freq) {
        if (permutation.size() == nums.size()) {
            ans.push_back(permutation);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
                freq[i] = true;
                permutation.push_back(nums[i]);
                permutations(nums, permutation, ans, freq);
                permutation.pop_back();
                freq[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> permutation;
        vector<bool> freq(nums.size(), false);
        permutations(nums, permutation, ans, freq);
        return ans;
    }
};