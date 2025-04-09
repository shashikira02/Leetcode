class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> next(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));

        for(int ind =n-1;ind>=0;ind--){
            for(int buy = 0;buy<=1;buy++){
                for(int capacity =1;capacity<=k; capacity++){
                    if (buy == 1) {
                        curr[buy][capacity] =
                            max(-prices[ind] + next[0][capacity],
                                next[1][capacity]);
                    } else
                        curr[buy][capacity] =
                            max(prices[ind] + next[1][capacity-1],
                                next[0][capacity]);
                }
                next = curr;
            }
        }


        return curr[1][k];
    }
};