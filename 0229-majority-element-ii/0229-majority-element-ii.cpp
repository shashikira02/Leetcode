class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0, count2=0;

        int ele1 = INT_MIN, ele2 = INT_MIN;

        for(int i =0;i<nums.size();i++){
            if(count1 == 0 && ele2 != nums[i]){
                count1 =1;
                ele1 = nums[i];
            }
            else if(count2 == 0 && ele1 != nums[i]){
                count2 =1;
                ele2 = nums[i];
            }
            else if(nums[i] == ele1)count1++;
            else if(nums[i] == ele2)count2++;
            else{
                count1--, count2--;
            }
        }

        vector<int>ans;
        count1 =0, count2 =0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(ele1 == nums[i])count1++;
            if(ele2 == nums[i])count2++;
        }

        int mini = (int)(n/3)+1;
        if(count1 >= mini)ans.push_back(ele1);
        if(count2 >= mini)ans.push_back(ele2);
        sort(ans.begin(), ans.end());

        return ans;   
    }
};