class Solution {
public:
    bool isNonDecreasing(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;

        while (!isNonDecreasing(nums)) {
            int ind = 0;
            int minSum = nums[0] + nums[1];

            for (int i = 1; i + 1 < nums.size(); i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    ind = i;
                }
            }

            nums[ind] = nums[ind] + nums[ind + 1];
            nums.erase(nums.begin() + ind + 1);
            ops++;
        }
        return ops;
    }
};
