class Solution {
public:
    // Helper function to calculate maximum profit using dynamic programming (bottom-up approach)
    int solve(vector<int>& prices){
        int n = prices.size();

        // Create a 3D DP table to store the maximum profit at each index, with the options to buy or sell, and the remaining transaction limit.
        // dp[i][j][k] represents the maximum profit starting from index i, with buy/sell option j (1 = can buy, 0 = can sell), and k remaining transactions.
        // We use n+1 for index to account for the boundary condition where we reach the end of the prices array.
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        // Start iterating from the last day (index = n-1) towards the first day (index = 0)
        for(int index = n-1; index >= 0; index--){
            // For each index, we check whether we can buy (buy == 1) or sell (buy == 0) and the remaining transaction limit
            for(int buy = 0; buy <= 1; buy++){
                for(int limit = 1; limit <= 2; limit++){
                    int profit = 0;

                    // If we can buy (buy == 1)
                    if(buy){
                        // Option 1: Buy the stock today, and move to the next day with the ability to sell and the same remaining transaction limit
                        int buyStock = -prices[index] + dp[index+1][0][limit];
                        // Option 2: Skip buying and move to the next day, still with the ability to buy and the same remaining transaction limit
                        int notBuyStock = 0 + dp[index+1][1][limit];
                        // Choose the option that gives the maximum profit
                        profit = max(buyStock, notBuyStock);
                    }else{
                        // If we can sell (buy == 0)
                        // Option 1: Sell the stock today, reduce the transaction limit by 1, and move to the next day with the ability to buy
                        int sellStock = +prices[index] + dp[index+1][1][limit-1];
                        // Option 2: Skip selling and move to the next day, still with the ability to sell and the same remaining transaction limit
                        int notSellStock = 0 + dp[index+1][0][limit];
                        // Choose the option that gives the maximum profit
                        profit = max(sellStock, notSellStock);
                    }

                    // Store the computed result in the dp table for the current index, buy/sell option, and remaining transaction limit
                    dp[index][buy][limit] = profit;
                }
            }
        }

        // The final result is stored at dp[0][1][2], representing the maximum profit starting from day 0, with the ability to buy, and 2 transactions allowed
        return dp[0][1][2];
    }

    // Main function to return the maximum profit from the given prices array
    int maxProfit(vector<int>& prices) {
        // Call the solve function and return the result
        return solve(prices);
    }
};
