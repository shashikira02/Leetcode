class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        int n = coins.size();
        if (n == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            return 1e7;
        }
        vector<int>curr(amount+1, 1e7), prev(amount+1, 1e7);
        curr[0] = prev[0] = 0;

        for (int ind = 0; ind < n; ind++) {
            for (int mon = 1; mon <= amount; mon++) {
                int skip = (ind == 0) ? 1e7 : prev[mon];
                int take = 1e7;
                if (mon >= coins[ind]) {
                    take = 1 + curr[mon - coins[ind]];
                }
                curr[mon] = min(skip, take);
            }
            prev = curr;
        }

        return prev[amount] >= 1e7 ? -1 : prev[amount];
    }
};
