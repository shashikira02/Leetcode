class Solution {
    int gcd(int a, int b) {
        if (b == 0)
            return a;

        return gcd(b, a % b);
    }

public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ones = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                ones += 1;
        }
        if (ones > 0)
            return n - ones;

        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            int GCD = 0;
            for (int j = i; j < n; j++) {
                if (j - i + 1 > mini)
                    break;
                GCD = gcd(GCD, nums[j]);
                if (GCD == 1) {
                    mini = j - i + 1;
                    break;
                }
            }
        }

        return mini == INT_MAX ? -1 : (mini - 1) + (n - 1);
    }
};