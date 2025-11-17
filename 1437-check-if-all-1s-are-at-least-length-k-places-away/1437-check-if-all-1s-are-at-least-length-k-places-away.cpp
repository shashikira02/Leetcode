class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n =nums.size();
        int i =0, prev = -1;

        while(i<n){
            if(nums[i] == 1){
                if(prev != -1 && i - prev-1<k)return false;
                prev = i;
            }
            i++;
        }
        return true;
    }
};