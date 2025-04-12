class Solution {
public:
    void permutations(int ind, vector<int>& nums,
                      vector<vector<int>>& ans) {
        if (ind == nums.size()) {
            vector<int> permutation;
            for(int i =0;i<nums.size();i++){
                permutation.push_back(nums[i]);// current permutation.
            }
            ans.push_back(permutation); // Store the permutation in the result.
            return;
        }
        // Iterate through all possible elements for the current position.
        for (int i = ind; i < nums.size(); i++) {
           swap(i, ind, nums);// Swap to fix an element at the current position.
           permutations(ind+1, nums, ans);
           swap(i, ind, nums);// Backtrack to restore original order.
        }
    }

    void swap( int i , int j, vector<int>& nums){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutations(0, nums, ans);
        return ans;
    }
};