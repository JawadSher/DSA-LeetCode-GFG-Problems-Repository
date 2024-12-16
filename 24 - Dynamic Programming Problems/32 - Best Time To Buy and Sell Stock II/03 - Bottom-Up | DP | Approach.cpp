class Solution {
public:
    // Function to calculate the maximum profit using an iterative dynamic programming approach
    int solve(vector<int>& prices) {

        int n = prices.size(); // Get the number of days

        // Create a 2D DP table to store the maximum profit for each state
        // dp[index][buy]:
        // - `index` represents the current day
        // - `buy` represents whether buying (1) or selling (0) is allowed on this day
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Iterate backward from the second last day to the first day
        for (int index = n - 1; index >= 0; index--) {
            // Iterate over the two states: buy (1) and sell (0)
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0; // Initialize profit for the current state

                if (buy) {
                    // If we are allowed to buy:
                    // - Option 1: Buy the stock today (-prices[index]) and move to the next day with buy=0
                    // - Option 2: Skip buying today and move to the next day with buy=1
                    int buyStock = -prices[index] + dp[index + 1][0];
                    int notBuyStock = 0 + dp[index + 1][1];
                    profit = max(buyStock, notBuyStock);
                } else {
                    // If we are allowed to sell:
                    // - Option 1: Sell the stock today (+prices[index]) and move to the next day with buy=1
                    // - Option 2: Skip selling today and move to the next day with buy=0
                    int sellStock = +prices[index] + dp[index + 1][1];
                    int notSellStock = 0 + dp[index + 1][0];
                    profit = max(sellStock, notSellStock);
                }

                // Store the profit for the current state in the DP table
                dp[index][buy] = profit;
            }
        }

        // The maximum profit starting from day 0 with the ability to buy (buy=1)
        return dp[0][1];
    }

    // Main function to calculate the maximum profit
    int maxProfit(vector<int>& prices) {
        return solve(prices); // Call the solve function
    }
};
