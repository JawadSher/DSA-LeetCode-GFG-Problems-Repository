class Solution {
public:
    // Recursive function to calculate the maximum profit
    // `prices`: vector of stock prices
    // `index`: current day index
    // `transactionNo`: current transaction number (0-based, where even = buy, odd = sell)
    // `k`: maximum number of transactions allowed
    int solve(vector<int>& prices, int index, int transactionNo, int k) {
        // Base case: if we reach the end of the prices array or have completed `2 * k` transactions
        if (index == prices.size() || transactionNo == 2 * k) return 0;

        int profit = 0; // Variable to store the profit for the current state

        // Check if the current transaction is a "buy" (even transactionNo)
        if (transactionNo % 2 == 0) {
            // Option 1: Buy the stock on the current day and move to the next transaction
            int buyStock = -prices[index] + solve(prices, index + 1, transactionNo + 1, k);
            // Option 2: Skip buying and move to the next day
            int notBuyStock = 0 + solve(prices, index + 1, transactionNo, k);
            // Maximize the profit between buying and skipping
            profit = max(buyStock, notBuyStock);
        } else {
            // If the current transaction is a "sell" (odd transactionNo)
            // Option 1: Sell the stock on the current day and move to the next transaction
            int sellStock = +prices[index] + solve(prices, index + 1, transactionNo + 1, k);
            // Option 2: Skip selling and move to the next day
            int notSellStock = 0 + solve(prices, index + 1, transactionNo, k);
            // Maximize the profit between selling and skipping
            profit = max(sellStock, notSellStock);
        }

        return profit; // Return the profit for the current state
    }

    // Function to calculate the maximum profit with at most `k` transactions
    // `k`: maximum number of transactions allowed
    // `prices`: vector of stock prices
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(); // Total number of days

        // Call the recursive function starting from day 0 and transaction number 0
        return solve(prices, 0, 0, k);
    }
};
