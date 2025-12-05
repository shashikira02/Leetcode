class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        long long S = 0;
        for (int x : nums) S += x;

        if (S % 2 != 0) return 0; 

        long long prefix = 0;
        int count = 0;

        for (int r = 1; r < n; r++) {
            prefix += nums[r - 1];
            if ((2 * prefix - S) % 2 == 0)
                count++;
        }
        return count;
    }
};
