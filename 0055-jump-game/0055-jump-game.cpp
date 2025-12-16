class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxi =0;
        if(nums[0] == 0 && n ==1)return true;
        for(int i =0;i<n;i++){
            if(i > maxi)return false;
            maxi = max(maxi, i + nums[i]);
        }

        return maxi >= n-1;
    }
};