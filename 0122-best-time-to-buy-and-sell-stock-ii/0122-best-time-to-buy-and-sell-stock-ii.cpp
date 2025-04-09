class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>next(2,0), curr(2,0);

        // DP base case: at the end of the array, profit is 0 regardless of
        // bought/sell state
        next[0] = 0;
        next[1] = 0;

        // Fill the DP table from bottom to top
        for (int index = n - 1; index >= 0; index--) {
            for (int bought = 0; bought <= 1; bought++) {
                int skip = next[bought]; // Skip the current day
                int profit = 0;

                if (bought) {
                    // If we have already bought, we can sell today
                    int sell = prices[index] + next[0];
                    profit = max(skip, sell);
                } else {
                    // If we haven't bought, we can buy today
                    int buy = -prices[index] + next[1];
                    profit = max(skip, buy);
                }

                // Store the calculated profit in the DP table
                curr[bought] = profit;
            }
            next = curr;
        }
        return curr[0];
    }
};
