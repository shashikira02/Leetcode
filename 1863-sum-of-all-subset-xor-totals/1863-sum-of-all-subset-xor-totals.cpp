class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return Xor(nums,0,0);
    }

    int Xor(vector<int>& nums, int index, int currXor){
        if(index == nums.size())return currXor;

        int currEle = Xor(nums, index+1, currXor^nums[index]);

        int exclude = Xor(nums, index+1, currXor);

        return currEle + exclude;

    }
};