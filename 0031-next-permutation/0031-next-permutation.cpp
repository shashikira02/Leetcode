class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind =-1;
        //Find the first index from the right where nums[i] < nums[i+1]
        for(int i =n-2;i>=0; i--){ 
            if(nums[i] < nums[i+1]){ // to check the index where we have to swap
                ind =i;
                break;
            }
        }
        //if no such index is found we reverse the arrray;
        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        //for finding smallest element on the right side of ind that is larger
        for(int i =n-1;i>=ind;i--){
            if(nums[i] > nums[ind]){
                swap(nums[i],nums[ind]);// swap the first element
                break;
            }
        }
        //reverse the elements to the right of ind to get the next permutation
        reverse(nums.begin()+ ind+1, nums.end());
    }
};