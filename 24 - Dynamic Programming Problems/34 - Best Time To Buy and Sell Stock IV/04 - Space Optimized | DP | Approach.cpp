class Solution {
public:
    // Function to calculate the maximum profit using space-optimized dynamic programming
    // `prices`: vector of stock prices
    // `k`: maximum number of transactions allowed
    int solve(vector<int>& prices, int k) {
        int n = prices.size(); // Total number of days

        // Create two 2D vectors `curr` and `next` to store the DP states for the current and next days.
        // Each has 2 rows for the buy/sell state and `k+1` columns for the transaction limit.
        vector<vector<int>> curr(2, vector<int>(k + 1, 0)); // Current day's DP table
        vector<vector<int>> next(2, vector<int>(k + 1, 0)); // Next day's DP table

        // Iterate backwards over days (from the last day to the first day)
        for (int index = n - 1; index >= 0; index--) {
            // Iterate over the buy/sell state (0 = sell, 1 = buy)
            for (int buy = 0; buy <= 1; buy++) {
                // Iterate over the transaction limits (from 1 to k)
                for (int limit = 1; limit <= k; limit++) {
                    int profit = 0; // Variable to store the profit for the current state

                    if (buy) {
                        // If the current state allows buying, we have two options:
                        // 1. Buy the stock at the current price, then move to the next day with `buy = 0`.
                        // 2. Skip buying and move to the next day with `buy = 1`.
                        int buyStock = -prices[index] + next[0][limit]; // Buying
                        int notBuyStock = 0 + next[1][limit];          // Skipping
                        profit = max(buyStock, notBuyStock);           // Maximize profit
                    } else {
                        // If the current state allows selling, we have two options:
                        // 1. Sell the stock at the current price, then move to the next day with `buy = 1` and decrement the transaction count.
                        // 2. Skip selling and move to the next day with `buy = 0`.
                        int sellStock = prices[index] + next[1][limit - 1]; // Selling
                        int notSellStock = 0 + next[0][limit];             // Skipping
                        profit = max(sellStock, notSellStock);             // Maximize profit
                    }

                    // Store the result in the current DP table
                    curr[buy][limit] = profit;
                }
            }

            // Move the current DP table to the next day (space optimization)
            next = curr;
        }

        // Return the maximum profit starting from day 0, with the ability to buy and `k` transactions available
        return curr[1][k];
    }

    // Main function to calculate the maximum profit
    // `k`: maximum number of transactions allowed
    // `prices`: vector of stock prices
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(); // Total number of days
        
        // Call the solve function to compute the result using dynamic programming
        return solve(prices, k);
    }
};
