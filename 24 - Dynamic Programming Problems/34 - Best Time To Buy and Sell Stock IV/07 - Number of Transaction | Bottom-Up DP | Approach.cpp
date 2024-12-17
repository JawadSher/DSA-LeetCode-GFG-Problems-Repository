class Solution {
public:
    // Function to calculate the maximum profit using dynamic programming
    // `prices`: vector of stock prices
    // `k`: maximum number of transactions allowed
    int solve(vector<int>& prices, int k) {
        int n = prices.size(); // Number of days

        // Create a DP table to store the maximum profit
        // `dp[i][j]`: Maximum profit achievable from day `i` onwards with transaction number `j`
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        // Iterate through days in reverse order (bottom-up DP)
        for (int index = n - 1; index >= 0; index--) {
            // Iterate through all possible transaction states
            for (int transactionNo = 0; transactionNo < 2 * k; transactionNo++) {
                int profit = 0;

                // Determine whether the current transaction is a "buy" or "sell"
                if (transactionNo % 2 == 0) { // Buy operation
                    // Option 1: Buy the stock on the current day and move to the next transaction
                    int buyStock = -prices[index] + dp[index + 1][transactionNo + 1];
                    // Option 2: Skip buying and move to the next day
                    int notBuyStock = 0 + dp[index + 1][transactionNo];
                    // Maximize profit between buying and skipping
                    profit = max(buyStock, notBuyStock);
                } else { // Sell operation
                    // Option 1: Sell the stock on the current day and move to the next transaction
                    int sellStock = +prices[index] + dp[index + 1][transactionNo + 1];
                    // Option 2: Skip selling and move to the next day
                    int notSellStock = 0 + dp[index + 1][transactionNo];
                    // Maximize profit between selling and skipping
                    profit = max(sellStock, notSellStock);
                }

                // Store the calculated profit in the DP table
                dp[index][transactionNo] = profit;
            }
        }

        // The maximum profit starting from day 0 with no transactions made yet
        return dp[0][0];
    }

    // Main function to calculate the maximum profit with at most `k` transactions
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(); // Total number of days

        // Call the solve function to compute the maximum profit
        return solve(prices, k);
    }
};
