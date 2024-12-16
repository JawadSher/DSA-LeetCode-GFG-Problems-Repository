class Solution {
public:
    // Helper function to calculate the maximum profit using recursion and memoization
    // Parameters:
    // prices - reference to the price array
    // index  - current day we are processing
    // buy    - whether we are allowed to buy (1) or sell (0) on the current day
    // dp     - 2D vector for memoization to store intermediate results
    int solve(vector<int>& prices, int index, int buy, vector<vector<int>>& dp) {
        // Base case: If we have processed all the days, there is no profit to be made
        if (index == prices.size()) return 0;

        // If the result for this state is already computed, return it
        if (dp[index][buy] != -1) return dp[index][buy];

        int profit = 0; // Initialize profit for the current state

        if (buy) {
            // If we are allowed to buy on this day, we have two choices:
            // 1. Buy the stock today: Subtract prices[index] and move to the next day with buy=0 (since we now own the stock).
            // 2. Skip buying today: Move to the next day and keep buy=1.
            profit = max(
                (-prices[index] + solve(prices, index + 1, 0, dp)), // Option 1: Buy today
                (0 + solve(prices, index + 1, 1, dp))               // Option 2: Skip buying
            );
        } else {
            // If we are allowed to sell on this day, we have two choices:
            // 1. Sell the stock today: Add prices[index] to profit and move to the next day with buy=1 (since we no longer own the stock).
            // 2. Skip selling today: Move to the next day and keep buy=0.
            profit = max(
                (+prices[index] + solve(prices, index + 1, 1, dp)), // Option 1: Sell today
                (0 + solve(prices, index + 1, 0, dp))               // Option 2: Skip selling
            );
        }

        // Store the computed profit for the current state in the dp table
        return dp[index][buy] = profit;
    }

    // Main function to calculate the maximum profit
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); // Get the number of days

        // Create a 2D dp table with dimensions (n+1) x 2
        // dp[i][buy] stores the maximum profit from day i onward with the ability to buy or sell
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));

        // Start from the first day (index=0) with the ability to buy (buy=1)
        return solve(prices, 0, 1, dp);
    }
};
