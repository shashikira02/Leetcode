class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int bits = 0;
        for (auto& num : nums) {
            if (num % original != 0) continue;
            num /= original;
            if ((num & (num - 1)) == 0)
                bits |= num;
        }
        bits++;
        return original * (bits & -bits);
    }
};