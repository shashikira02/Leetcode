class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum % 2 != 0) return false;

        int target = sum / 2;
        vector<bool> prev(target+1, false);
        vector<bool> curr(target+1, false);

        prev[0] = curr[0] = true;

        for (int i = 0; i < n; i++) curr[0] = true; 

        if (nums[0] <= target)curr[nums[0]] = true;
        
        for (int ind = 1; ind < n; ind++) {
            for (int tar = 1; tar <= target; tar++) {
                bool skip = prev[tar];
                bool include = false;
                if (nums[ind] <= tar) include = prev[tar - nums[ind]];
                curr[tar] = skip || include;
            }
            prev = curr;
        }

        return prev[target];
    }
};