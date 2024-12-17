class Solution {
public:
    // Recursive function to calculate the maximum profit with memoization
    // `prices`: vector of stock prices
    // `index`: current day index
    // `transactionNo`: current transaction number (0-based, where even = buy, odd = sell)
    // `k`: maximum number of transactions allowed
    // `dp`: memoization table to store intermediate results
    int solve(vector<int>& prices, int index, int transactionNo, int k, vector<vector<int>>& dp) {
        // Base case: If we've reached the end of the array or completed all allowed transactions
        if (index == prices.size() || transactionNo == 2 * k) return 0;

        // Check if the result for this state is already computed
        if (dp[index][transactionNo] != -1) return dp[index][transactionNo];

        int profit = 0; // Variable to store the profit for the current state

        // If the current transaction is a "buy" operation (even transaction number)
        if (transactionNo % 2 == 0) {
            // Option 1: Buy the stock on the current day and move to the next transaction
            int buyStock = -prices[index] + solve(prices, index + 1, transactionNo + 1, k, dp);
            // Option 2: Skip buying and move to the next day
            int notBuyStock = 0 + solve(prices, index + 1, transactionNo, k, dp);
            // Maximize the profit between buying and skipping
            profit = max(buyStock, notBuyStock);
        } else {
            // If the current transaction is a "sell" operation (odd transaction number)
            // Option 1: Sell the stock on the current day and move to the next transaction
            int sellStock = +prices[index] + solve(prices, index + 1, transactionNo + 1, k, dp);
            // Option 2: Skip selling and move to the next day
            int notSellStock = 0 + solve(prices, index + 1, transactionNo, k, dp);
            // Maximize the profit between selling and skipping
            profit = max(sellStock, notSellStock);
        }

        // Store the result in the dp table to avoid recomputation
        return dp[index][transactionNo] = profit;
    }

    // Function to calculate the maximum profit with at most `k` transactions
    // `k`: maximum number of transactions allowed
    // `prices`: vector of stock prices
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(); // Total number of days

        // Memoization table to store results for each day and transaction number
        // `dp[i][j]`: Maximum profit achievable from day `i` onwards with transaction number `j`
        vector<vector<int>> dp(n, vector<int>(2 * k, -1));

        // Call the recursive function starting from day 0 and transaction number 0
        return solve(prices, 0, 0, k, dp);
    }
};
