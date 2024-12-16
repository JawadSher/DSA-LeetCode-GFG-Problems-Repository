class Solution {
public:
    // Helper function to calculate the maximum profit using recursion.
    // Parameters:
    // prices - reference to the price array
    // index  - current day we are processing
    // buy    - whether we are allowed to buy (1) or sell (0) on the current day
    int solve(vector<int>& prices, int index, int buy) {
        // Base case: If we have processed all the days, there is no profit to be made
        if (index == prices.size()) return 0;

        int profit = 0; // Initialize profit for the current state

        if (buy) {
            // If we are allowed to buy on this day, we have two choices:
            // 1. Buy the stock today: Subtract prices[index] and move to the next day with buy=0 (since we now own the stock).
            // 2. Skip buying today: Move to the next day and keep buy=1.
            profit = max(
                (-prices[index] + solve(prices, index + 1, 0)), // Option 1: Buy today
                (0 + solve(prices, index + 1, 1))               // Option 2: Skip buying
            );
        } else {
            // If we are allowed to sell on this day, we have two choices:
            // 1. Sell the stock today: Add prices[index] to profit and move to the next day with buy=1 (since we no longer own the stock).
            // 2. Skip selling today: Move to the next day and keep buy=0.
            profit = max(
                (+prices[index] + solve(prices, index + 1, 1)), // Option 1: Sell today
                (0 + solve(prices, index + 1, 0))               // Option 2: Skip selling
            );
        }

        // Return the maximum profit for the current state
        return profit;
    }

    // Main function to calculate the maximum profit
    int maxProfit(vector<int>& prices) {
        // Start from the first day (index=0) with the ability to buy (buy=1)
        return solve(prices, 0, 1);
    }
};
