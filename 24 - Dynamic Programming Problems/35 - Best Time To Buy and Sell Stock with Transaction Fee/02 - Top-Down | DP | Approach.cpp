class Solution {
public:
    // Helper function to calculate the maximum profit using dynamic programming
    int solve(vector<int>& prices, int index, int buy, int fee, vector<vector<int>>& dp) {
        int n = prices.size(); // Get the size of the prices array

        // Base case: If we've reached the end of the array (index == n), no more transactions can be made
        if(index == n) return 0;

        // If the result is already computed for this index and buy state, return it from dp array
        if(dp[index][buy] != -1) return dp[index][buy];

        int profit = 0;
        
        // If we are in a "buy" state (buy == 1), we can either:
        // 1. Buy the stock at current price (this is represented by -prices[index])
        //    and move to the next index (index+1) in a "sell" state (buy = 0).
        // 2. Skip this index (do nothing) and stay in the "buy" state (buy = 1).
        if(buy) {
            profit = max((-prices[index] + solve(prices, index+1, 0, fee, dp)), // Buy and move to the sell state
                          (0 + solve(prices, index+1, 1, fee, dp))); // Do nothing and stay in the buy state
        } else {
            // If we are in a "sell" state (buy == 0), we can either:
            // 1. Sell the stock at current price (this is represented by +prices[index] - fee)
            //    and move to the next index (index+1) in a "buy" state (buy = 1).
            // 2. Skip this index (do nothing) and stay in the "sell" state (buy = 0).
            profit = max((+prices[index] - fee + solve(prices, index+1, 1, fee, dp)), // Sell and move to the buy state
                          (0 + solve(prices, index+1, 0, fee, dp))); // Do nothing and stay in the sell state
        }

        // Store the result in dp array and return it
        return dp[index][buy] = profit;
    }

    // Main function to calculate the maximum profit with transaction fee
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(); // Get the size of the prices array

        // Initialize the dp array with -1 (indicating no result is computed yet)
        // dp[i][0] represents the maximum profit we can have at index i without buying the stock
        // dp[i][1] represents the maximum profit we can have at index i while having the stock to sell
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        
        // Start solving from index 0 with the possibility of buying (buy = 1)
        return solve(prices, 0, 1, fee, dp);
    }
};
