class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i =0;
        while(i<n){
            if(i>0 && nums[i] == nums[i-1]){
                i++;
                continue;
            }
            int j = i+1, k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else {
                    vector<int>temp =  { nums[i] , nums[j], nums[k]};
                    ans.push_back(temp);
                    j++, k--;
                    while(j<k && nums[j] == nums[j-1])j++;
                    while(j<k && nums[k] == nums[k+1])k--;
                }
            }
            i++;
        }
        return ans;
    }
};
