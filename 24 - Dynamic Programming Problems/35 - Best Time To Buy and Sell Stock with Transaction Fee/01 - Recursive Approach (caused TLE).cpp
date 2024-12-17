class Solution {
public:
    // Helper function to calculate the maximum profit
    int solve(vector<int>& prices, int index, int buy, int fee) {
        int n = prices.size(); // Get the size of the prices array

        // Base case: If we've reached the end of the array, no more transactions can be made
        if(index == n) return 0;

        int profit = 0;

        // If we are in a buying state (buy == 1), we can either:
        // 1. Buy the stock at current price (this is represented by -prices[index])
        //    and move to the next index (index+1) in a "sell" state (buy = 0).
        // 2. Skip this index (do nothing) and stay in the "buy" state (buy = 1).
        if(buy) {
            profit = max((-prices[index] + solve(prices, index+1, 0, fee)), // Buy and move to the sell state
                          (0 + solve(prices, index+1, 1, fee))); // Do nothing and stay in the buy state
        } else {
            // If we are in a selling state (buy == 0), we can either:
            // 1. Sell the stock at current price (this is represented by +prices[index] - fee)
            //    and move to the next index (index+1) in a "buy" state (buy = 1).
            // 2. Skip this index (do nothing) and stay in the "sell" state (buy = 0).
            profit = max((+prices[index] - fee + solve(prices, index+1, 1, fee)), // Sell and move to the buy state
                          (0 + solve(prices, index+1, 0, fee))); // Do nothing and stay in the sell state
        }

        // Return the maximum profit for the current state
        return profit;
    }

    // Main function to calculate the maximum profit with transaction fee
    int maxProfit(vector<int>& prices, int fee) {
        // Start solving from index 0 with the possibility of buying (buy = 1)
        return solve(prices, 0, 1, fee);
    }
};
