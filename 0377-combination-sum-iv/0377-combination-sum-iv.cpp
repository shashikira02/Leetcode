class Solution {
public:
    int solve(vector<int>& nums, int target){
        if(target == 0)return 1;
        if(target < 0)return 0;

        int ways =0;

        for(auto num: nums){
            ways +=solve(nums, target-num);
        }

        return ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        return solve(nums,target);
    }
};