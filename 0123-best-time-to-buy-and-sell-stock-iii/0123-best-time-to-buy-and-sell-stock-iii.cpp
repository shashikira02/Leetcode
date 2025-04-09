class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuy = INT_MIN, firstSell = 0;
        int secondBuy = INT_MIN, secondSell = 0;

        for (int price : prices) {
            // Update the four states
            firstBuy = max(firstBuy, -price);              // First buy: most negative profit
            firstSell = max(firstSell, firstBuy + price);  // First sell: firstBuy + current price
            secondBuy = max(secondBuy, firstSell - price); // Second buy: firstSell - current price
            secondSell = max(secondSell, secondBuy + price); // Second sell: secondBuy + current price
        }

        return secondSell; // Max profit after two transactions
    }
};
