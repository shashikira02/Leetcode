#include <vector>

using namespace std;

class Solution {
public:
    int func(vector<int>& coins, int ind, int amount, vector<vector<int>>&dp) {
        if (amount == 0) return 1;
        if (amount < 0) return 0;  
        if (ind < 0) return 0;      

        if(dp[ind][amount] !=-1) return dp[ind][amount];
        int skip = func(coins, ind - 1, amount, dp);   
        int take = func(coins, ind, amount - coins[ind], dp);

        return dp[ind][amount] = skip + take;  
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return func(coins, n - 1, amount, dp);
    }
};
