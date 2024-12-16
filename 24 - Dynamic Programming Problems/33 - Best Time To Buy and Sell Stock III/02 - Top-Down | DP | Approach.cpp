class Solution {
public:
    // Helper function to calculate maximum profit with memoization
    int solve(vector<int>& prices, int index, int buy, int limit, vector<vector<vector<int>>>& dp){
        int n = prices.size();
        
        // Base case: If we have reached the end of the prices array (index == n) or no transactions left (limit == 0)
        if(index == n || limit == 0) return 0;

        // Check if the result for the current state has already been computed (memoized)
        if(dp[index][buy][limit] != -1) return dp[index][buy][limit];

        int profit = 0;

        // If we are allowed to buy (buy == 1)
        if(buy){
            // Option 1: Buy the stock today, and move to the next day (after buying, we can't buy again)
            // Option 2: Skip buying and move to the next day, still with the option to buy
            profit = max((-prices[index] + solve(prices, index+1, 0, limit, dp)), 
                          (0 + solve(prices, index+1, 1, limit, dp)));
        } else {
            // If we are allowed to sell (buy == 0)
            // Option 1: Sell the stock today, reduce the transaction limit by 1 and move to the next day (after selling, we can buy again)
            // Option 2: Skip selling and move to the next day, still with the option to sell
            profit = max((+prices[index] + solve(prices, index+1, 1, limit-1, dp)), 
                          (0 + solve(prices, index+1, 0, limit, dp)));
        }

        // Store the computed result in dp to avoid redundant calculations in future recursive calls
        return dp[index][buy][limit] = profit;
    }

    // Main function to return the maximum profit
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // Create a 3D DP table initialized with -1, where:
        // dp[i][j][k] represents the maximum profit starting from index i, with a flag j (1 = can buy, 0 = can sell), 
        // and k remaining transactions.
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        // Start the recursive function with index = 0, buy = 1 (indicating we can buy), and limit = 2 (two transactions allowed)
        return solve(prices, 0, 1, 2, dp);
    }
};
