class Solution {
public:
    // Iterative function to calculate the maximum profit using dynamic programming (bottom-up approach)
    // `prices`: vector of stock prices
    // `k`: maximum number of transactions allowed
    int solve(vector<int>& prices, int k) {
        int n = prices.size(); // Total number of days

        // Create a 3D DP table where:
        // dp[i][buy][limit]: Maximum profit achievable starting from day `i` with `buy` state and `limit` transactions left
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

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
                        int buyStock = -prices[index] + dp[index + 1][0][limit]; // Buying
                        int notBuyStock = 0 + dp[index + 1][1][limit];          // Skipping
                        profit = max(buyStock, notBuyStock);                    // Maximize profit
                    } else {
                        // If the current state allows selling, we have two options:
                        // 1. Sell the stock at the current price, then move to the next day with `buy = 1` and decrement the transaction count.
                        // 2. Skip selling and move to the next day with `buy = 0`.
                        int sellStock = prices[index] + dp[index + 1][1][limit - 1]; // Selling
                        int notSellStock = 0 + dp[index + 1][0][limit];             // Skipping
                        profit = max(sellStock, notSellStock);                      // Maximize profit
                    }

                    // Store the result in the DP table
                    dp[index][buy][limit] = profit;
                }
            }
        }

        // Return the maximum profit starting from day 0, with the ability to buy and `k` transactions available
        return dp[0][1][k];
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
