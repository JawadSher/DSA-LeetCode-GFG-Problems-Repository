class Solution {
public:
    // Recursive helper function to calculate the maximum profit
    // `prices`: vector of stock prices
    // `index`: current day index in the prices array
    // `buy`: indicates whether we are allowed to buy (1) or need to sell (0)
    // `k`: remaining transactions we are allowed to perform
    int solve(vector<int>& prices, int index, int buy, int k) {
        int n = prices.size(); // Number of days in the prices array

        // Base case: if we've reached the end of the array or have no transactions left, return 0
        if(index == n || k == 0) return 0;

        int profit = 0; // Variable to store the maximum profit at the current state

        if(buy) {
            // If we are allowed to buy, we have two choices:
            // 1. Buy the stock on this day and subtract its price from profit, then move to the next day with `buy = 0`.
            // 2. Skip buying and move to the next day with `buy = 1`.
            profit = max(
                -prices[index] + solve(prices, index + 1, 0, k), // Buy
                0 + solve(prices, index + 1, 1, k)              // Skip
            );
        } else {
            // If we are not allowed to buy (we need to sell), we have two choices:
            // 1. Sell the stock on this day and add its price to profit, then move to the next day with `buy = 1` and decrement transactions.
            // 2. Skip selling and move to the next day with `buy = 0`.
            profit = max(
                prices[index] + solve(prices, index + 1, 1, k - 1), // Sell
                0 + solve(prices, index + 1, 0, k)                // Skip
            );
        }

        return profit; // Return the maximum profit for this state
    }

    // Main function to calculate the maximum profit
    // `k`: maximum number of transactions allowed
    // `prices`: vector of stock prices
    int maxProfit(int k, vector<int>& prices) {
        // Start the recursive process from day 0, with the ability to buy and `k` transactions remaining
        return solve(prices, 0, 1, k);
    }
};
