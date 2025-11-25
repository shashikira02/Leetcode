class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int curr = 1;

        for (int i = 1; i <= k; i++) {
            if (curr % k == 0)
                return i;
            curr = 10 * (curr % k) + 1;
        }
        return -1;
    }
};