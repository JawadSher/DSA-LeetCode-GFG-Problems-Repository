class Solution {
public:
    // Function to calculate the maximum profit using space-optimized dynamic programming
    // `prices`: vector of stock prices
    // `k`: maximum number of transactions allowed
    int solve(vector<int>& prices, int k) {
        int n = prices.size(); // Number of days

        // `curr` and `next` arrays store the maximum profit for the current and next days
        // Each array has size `2*k+1`, representing all transaction states
        vector<int> curr(2 * k + 1, 0);
        vector<int> next(2 * k + 1, 0);

        // Iterate through days in reverse order (bottom-up DP)
        for (int index = n - 1; index >= 0; index--) {
            // Iterate through all transaction states
            for (int transactionNo = 0; transactionNo < 2 * k; transactionNo++) {
                int profit = 0;

                // Determine whether the current transaction is a "buy" or "sell"
                if (transactionNo % 2 == 0) { // Buy operation
                    // Option 1: Buy the stock on the current day and move to the next transaction
                    int buyStock = -prices[index] + next[transactionNo + 1];
                    // Option 2: Skip buying and move to the next day
                    int notBuyStock = 0 + next[transactionNo];
                    // Maximize profit between buying and skipping
                    profit = max(buyStock, notBuyStock);
                } else { // Sell operation
                    // Option 1: Sell the stock on the current day and move to the next transaction
                    int sellStock = +prices[index] + next[transactionNo + 1];
                    // Option 2: Skip selling and move to the next day
                    int notSellStock = 0 + next[transactionNo];
                    // Maximize profit between selling and skipping
                    profit = max(sellStock, notSellStock);
                }

                // Store the calculated profit in the current day's array
                curr[transactionNo] = profit;
            }

            // Move to the next day by updating `next` to `curr`
            next = curr;
        }

        // The maximum profit starting from day 0 with no transactions made yet
        return next[0];
    }

    // Main function to calculate the maximum profit with at most `k` transactions
    int maxProfit(int k, vector<int>& prices) {
        // Call the `solve` function to compute the maximum profit
        return solve(prices, k);
    }
};
