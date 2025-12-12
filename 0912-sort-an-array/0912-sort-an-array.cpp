class Solution {
public:
 void helper(int head, int tail, vector<int>& nums) {

        if (head >= tail) return;

        int l = head;
        int r = tail;

        int m = (r - l) / 2 + l;
        int pivot = nums[m];

        while (r >= l) {

            while (r >= l && nums[l] < pivot) {
                l++;
            }

            while (r >= l && nums[r] > pivot) {
                r--;
            }

            if (r >= l) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }

        helper(head, r, nums);

        helper(l, tail, nums);
    }
    vector<int> sortArray(vector<int>& nums) {
         helper(0, nums.size() - 1, nums);

        return nums;
    }
};