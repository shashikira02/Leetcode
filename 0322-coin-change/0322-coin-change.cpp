class Solution {
public:
    int totalCoins( int i,  vector<int>& coins, int amount, vector<vector<int>>&dp){
        if(amount == 0)return 0;
        if(amount< 0)return INT_MAX;
        if(i >= coins.size())return INT_MAX;

        if(dp[i][amount]!= -1)return dp[i][amount];
        if(coins[i] == amount) return 1;
        //take
        int take = totalCoins(i, coins, amount - coins[i], dp);
        if(take != INT_MAX)take +=1;

        //not take
        int notTake = totalCoins(i+1, coins, amount, dp);

        return dp[i][amount]= min((int)take, (int)notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1, -1));
        int ans = totalCoins(0, coins, amount, dp) ;
    
        if(ans == INT_MAX)return -1;
        else return ans;
    }
};