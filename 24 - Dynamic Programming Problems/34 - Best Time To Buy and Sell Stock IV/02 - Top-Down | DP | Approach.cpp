class Solution {
public:
    // Recursive helper function to calculate the maximum profit
    // `prices`: vector of stock prices
    // `index`: current day index in the prices array
    // `buy`: indicates whether we are allowed to buy (1) or need to sell (0)
    // `k`: remaining transactions we are allowed to perform
    // `dp`: 3D DP table to store intermediate results for memoization
    int solve(vector<int>& prices, int index, int buy, int k, vector<vector<vector<int>>>& dp) {
        int n = prices.size(); // Total number of days in the prices array

        // Base case: If we reach the end of the array or have no transactions left, return 0
        if(index == n || k == 0) return 0;

        // If the current state is already computed, return the stored value
        if(dp[index][buy][k] != -1) return dp[index][buy][k];

        int profit = 0; // Variable to store the maximum profit at the current state

        if(buy) {
            // If we are allowed to buy, we have two choices:
            // 1. Buy the stock on this day and subtract its price from profit, then move to the next day with `buy = 0`.
            // 2. Skip buying and move to the next day with `buy = 1`.
            profit = max(
                -prices[index] + solve(prices, index + 1, 0, k, dp), // Buy
                0 + solve(prices, index + 1, 1, k, dp)              // Skip
            );
        } else {
            // If we are not allowed to buy (we need to sell), we have two choices:
            // 1. Sell the stock on this day and add its price to profit, then move to the next day with `buy = 1` and decrement transactions.
            // 2. Skip selling and move to the next day with `buy = 0`.
            profit = max(
                prices[index] + solve(prices, index + 1, 1, k - 1, dp), // Sell
                0 + solve(prices, index + 1, 0, k, dp)                // Skip
            );
        }

        // Store the result in the DP table for future use and return it
        return dp[index][buy][k] = profit;
    }

    // Main function to calculate the maximum profit
    // `k`: maximum number of transactions allowed
    // `prices`: vector of stock prices
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(); // Total number of days

        // Initialize a 3D DP table with dimensions [n][2][k+1] and set all values to -1
        // dp[i][j][l]: maximum profit at day `i` with `j` (buy = 1, sell = 0) and `l` transactions remaining
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));

        // Start the recursive process from day 0, with the ability to buy and `k` transactions remaining
        return solve(prices, 0, 1, k, dp);
    }
};
