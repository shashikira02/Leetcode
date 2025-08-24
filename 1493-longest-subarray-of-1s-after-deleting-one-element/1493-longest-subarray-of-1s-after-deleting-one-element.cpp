class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int countZero = 0;
        int maxi = 0;
        int start = 0;

        for(int i =0;i<nums.size();i++){
            if(nums[i] == 0)countZero++;
            while(countZero >1){
                if(nums[start] == 0) countZero--;
                start++;
            }
            maxi = max(maxi, i - start);
        }
        return maxi;
    }
};