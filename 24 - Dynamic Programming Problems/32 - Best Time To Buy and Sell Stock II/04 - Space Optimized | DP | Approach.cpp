class Solution {
public:
    // Function to calculate the maximum profit using space-optimized dynamic programming
    int solve(vector<int>& prices) {
        int n = prices.size(); // Get the number of days

        // Space-optimized DP approach:
        // Instead of a 2D table, use two 1D arrays to store current and next states
        vector<int> curr(2, 0); // Array to store the current day's profit for both states (buy/sell)
        vector<int> next(2, 0); // Array to store the next day's profit for both states (buy/sell)

        // Iterate backward from the second last day to the first day
        for (int index = n - 1; index >= 0; index--) {
            // Iterate over the two states: buy (1) and sell (0)
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0; // Initialize profit for the current state

                if (buy) {
                    // If we are allowed to buy:
                    // - Option 1: Buy the stock today (-prices[index]) and move to the next day with buy=0
                    // - Option 2: Skip buying today and move to the next day with buy=1
                    int buyStock = -prices[index] + next[0];
                    int notBuyStock = 0 + next[1];
                    profit = max(buyStock, notBuyStock);
                } else {
                    // If we are allowed to sell:
                    // - Option 1: Sell the stock today (+prices[index]) and move to the next day with buy=1
                    // - Option 2: Skip selling today and move to the next day with buy=0
                    int sellStock = +prices[index] + next[1];
                    int notSellStock = 0 + next[0];
                    profit = max(sellStock, notSellStock);
                }

                // Store the profit for the current state in the current day's array
                curr[buy] = profit;
            }

            // Update the next day's array with the current day's results
            next = curr;
        }

        // The maximum profit starting from day 0 with the ability to buy (buy=1)
        return curr[1];
    }

    // Main function to calculate the maximum profit
    int maxProfit(vector<int>& prices) {
        return solve(prices); // Call the solve function
    }
};
